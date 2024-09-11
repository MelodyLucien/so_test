// shared_lib.h
#ifndef SHARED_LIB_H
#define SHARED_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

void set_shared_data(int value);
int get_shared_data();
void print_shared_data();

#ifdef __cplusplus
}
#endif

#endif // SHARED_LIB_H