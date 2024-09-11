// main.cpp
#include <iostream>
#include "shared_lib.h"

int main() {
    print_shared_data();
    set_shared_data(42);
    print_shared_data();
    return 0;
}