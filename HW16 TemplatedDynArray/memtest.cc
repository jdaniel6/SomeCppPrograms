//a program to test memory access
#include <iostream>

class alloc{
    private:
        char* data;
        uint64_t size = INT64_MAX;
    public:
        alloc(){
            data = new char[size];
        }
};

int main(){
    alloc a();
    std::cout << a;
}

