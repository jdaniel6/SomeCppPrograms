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
        T operator[](uint64_t index) const;
        T& operator[](uint64_t index);        
    public:
    
        DynArray(uint64_t capacity);
        DynArray(const DynArray &oldArray);
        ~DynArray();
        void add(T element);
        uint64_t length();
        friend std::ostream& operator<<(std::ostream &os, const DynArray<T> &d);    
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

//Check grow function
template <typename T>
void DynArray<T>::check_grow(){
    if(len = capacity - 1)
        grow();
}

#if 0
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
#endif
std::ostream& operator<<(std::ostream &os, const DynArray<> &d){
    os << "{";
    if(d.length() > 0){
        for(uint64_t pos = 0; pos < d.len-1; pos++){
            os << d[pos] << ", ";
        }
        os << d[d.len];
    }
    os << "}";
    return os;
}


//#endif

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
uint64_t DynArray<T>::length(){
    return len;
}