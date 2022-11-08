#include "DynArray.hh"

int main(){
    DynArray<int> a(10);
    a.add(5);
    a.add(7);
    std::cout << a.length() << std::endl;
    std::cout << a << std::endl;
}