#include <iostream>
#include "DynArray.hh"

//Private methods
//Default constructor
template <typename T>
DynArray<T>::DynArray(uint64_t capacity) : capacity(capacity), len(0), data(new T[capacity]) {}

//Copy constructor
template <typename T>
DynArray<T>::DynArray(const DynArray &oldArray) : capacity(oldArray.capacity), len(oldArray.len), data(new T[capacity]) {
    for(uint64_t pos = 0; pos < len; pos++){
        data[pos] = oldArray[pos];
    }
}

//Destructor
template <typename T>
DynArray<T>::~DynArray(){
    delete [] data;
    delete len;
    delete capacity;
}

//Grow function
template <typename T>
void DynArray<T>::grow(){
    capacity *= 2;
    T* newArray = new T[capacity];
    for(uint64_t pos = 0; pos <= len; pos++){
        newArray[pos] = data[pos];
    }
    delete [] data;
    data = newArray; 
}

//Check grow function
template <typename T>
void DynArray<T>::check_grow(){
    if(len = capacity - 1)
        grow();
}

//[] overloading
template <typename T>
T DynArray<T>::operator[](uint64_t index) const{
    return data[index];
}

template <typename T>
T &DynArray<T>::operator[](uint64_t index){
    return data[index];
}

//<< overloading
template <typename T>
ostream& operator<<(ostream &os, const DynArray &d){

}