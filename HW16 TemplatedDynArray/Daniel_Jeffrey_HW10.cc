/**
 * @file Daniel_Jeffrey_HW10.cc
 * @author Jeffrey Daniel(jdaniel6@stecens.edu)
 * @brief A program to implement a templated DynArray
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

template <typename T>
class TemplatedDynArray{
    private:
        uint64_t len;
        uint64_t capacity;
        T* data;
    public:
        TemplatedDynArray() : len(0), capacity(0), data(nullptr){}
        TemplatedDynArray(uint64_t capacity) : len(0), capacity(capacity), data(new T[capacity]){}
        TemplatedDynArray(const TemplatedDynArray &orig) : len(orig.len), capacity(orig.capacity), data(new T[capacity]){for(uint64_t i = 0; i < len; i++) new (data + i*(sizeof(T))) (orig.data[i])}
        TemplatedDynArray(TemplatedDynArray &&orig) : len(orig.len), capacity(orig.capacity), data(orig.data){orig.data = nullptr;} 
        TemplatedDynArray &operator=(const TemplatedDynArray &orig){if(this == orig) return this; else{len = orig.len; capacity = orig.capacity; data = new T[capacity]; for(uint64_t i = 0; i < len; i++) data[i] = orig.data[i];}}
        void print();
        std::ostream operator<<(std::ostream &os, const TemplatedDynArray &tda);
};

TemplatedDynArray::TemplatedDynArray(){}