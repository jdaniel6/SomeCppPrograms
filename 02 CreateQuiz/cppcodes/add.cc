#include <iostream>
#include <random>

int main(){
    int a = rand();
    int b = rand();
    int c = a + b;
    std::cout << a << "\t" << b << "\t" << c;
}