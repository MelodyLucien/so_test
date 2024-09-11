#!/bin/bash

# delete executables
rm -f main client libshared.so

gcc -fPIC -shared -o libshared.so shared_lib.c

gcc -o client client.c -ldl

./compile_sh.sh

for i in {1..5}; do
    ./client $i &
done

for i in {5..15}; do
    ./main $i &
done

wait