// client.c
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*set_shared_data_t)(int);
typedef int (*get_shared_data_t)();
typedef void (*print_shared_data_t)();

int main(int argc, char *argv[]) {

    //print the pid of the process
    printf("enter pid: %d\n", getpid());

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int value = atoi(argv[1]);

    void *handle = dlopen("./libshared.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading shared library: %s\n", dlerror());
        return 1;
    }

    set_shared_data_t set_shared_data = (set_shared_data_t)dlsym(handle, "set_shared_data");
    get_shared_data_t get_shared_data = (get_shared_data_t)dlsym(handle, "get_shared_data");
    print_shared_data_t print_shared_data = (print_shared_data_t)dlsym(handle, "print_shared_data");

    if (!set_shared_data || !get_shared_data || !print_shared_data) {
        fprintf(stderr, "Error loading symbols: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }
    print_shared_data();
    set_shared_data(value);
    print_shared_data();

    dlclose(handle);

    printf("exit pid %d\n", getpid());
    return 0;
}