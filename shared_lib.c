// shared_lib.c
#include <stdio.h>
#include <unistd.h>

static int shared_data = 0;

void set_shared_data(int value) {
    printf("pid:%d, Setting shared data to: %d\n",getpid(), value);
    shared_data = value;
}

int get_shared_data() {
    return shared_data;
}

void print_shared_data() {
    printf("pid:%d,Shared data is: %d\n",getpid() ,shared_data);
}