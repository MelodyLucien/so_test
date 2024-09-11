g++ -o main main.cpp -L. -lshared -Wl,-rpath,.

chmod +x main
./main