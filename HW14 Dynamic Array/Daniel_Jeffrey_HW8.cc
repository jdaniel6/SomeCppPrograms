/**
 * @file Daniel_Jeffrey_HW8.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to implement a Dynamic Array with O(n) access and creation time. May also include O(n) or O(log n) deletion time in future.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Daniel_Jeffrey_HW8.hh"

#if 0
int main(){
    DynArray<int> a(5);
    a.add(5);
    a.add(78);
    std::cout << a << std::endl;

    DynArray<char> b(3);
    b.add('a');
    b.add('b');
    b.add('c');
    b.add('d');
    std::cout << b << std::endl;

    DynArray<std::string> c(10);
    std::cout << c << std::endl;
    c.add("hello!");
    c.add("world?");
    std::cout << c << std::endl;

    DynArray<bool> d(10);

    for(auto i : b){
        std::cout << i << std::endl;
    }

}

#endif

int main(){
    DynArray<int> a(100);
    for(int i = 0; i < 100; i++){
        a.add(i);
    }
    a.add(101);
    std::cout << a;
}