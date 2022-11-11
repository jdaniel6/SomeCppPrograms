/**
 * @file Daniel_Jeffrey_HW8.hh
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to implement a Dynamic Array with O(n) access and creation time. May also include O(n) or O(log n) deletion time in future.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

template <typename T>
class DynArray{
    private:
        T* data;
        uint64_t len;
        uint64_t capacity;
        void grow();
        void check_grow();       
    public:   
        DynArray(uint64_t capacity);
        DynArray(const DynArray &oldArray);
        DynArray(DynArray&& oldArray);
        ~DynArray();
        void add(T element);
        uint64_t length() const;
        T* begin();
        T* end();
        T operator[](uint64_t index) const;
        T& operator[](uint64_t index); 
        T operator=(const T& orig);
        template <typename U> friend std::ostream& operator<<(std::ostream &os, const DynArray<U> &d);    
};


//Private methods
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

//Check grow function (could be optimised better)
template <typename T>
void DynArray<T>::check_grow(){
    if(len == (capacity - 1)){
        grow();
    }
}


//Public functions
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

//Move constructor
template <typename T>
DynArray<T>::DynArray(DynArray&& oldArray) : data(oldArray.data), len(oldArray.len), capacity(oldArray.capacity) {
    oldArray.data = nullptr;
}

//Destructor
template <typename T>
DynArray<T>::~DynArray(){
    delete [] data;
}

//Add an element
template <typename T>
void DynArray<T>::add(T element){
    check_grow();
    data[len] = element;
    len++;
}

//Get length of the array
template <typename T>
uint64_t DynArray<T>::length() const {
    return len;
}

//begin()
template <typename T>
T* DynArray<T>::begin(){
    return ((len > 0) ? &data[0] : nullptr);
}

//end()
template <typename T>
T* DynArray<T>::end(){
    return ((len > 0) ? &data[len] : nullptr);
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

//= overloading
template<typename T>
T DynArray<T>::operator=(const T &orig){
    if(&orig == this)
        return;
    delete [] data;
    data = new int[orig.len];
    len = orig.len;
    for(uint64_t i = 0; i < orig.len; i++)
        data[i] = orig[i];
    

}

//<< overloading
template <typename T>
std::ostream& operator<<(std::ostream &os, const DynArray<T> &d){
    os << "{";
    if(d.len > 0){
        for(uint64_t pos = 0; pos < d.len-1; pos++){
            os << d[pos] << ", ";
        }
        os << d[d.len-1];
    }
    os << "}";
    return os;
}