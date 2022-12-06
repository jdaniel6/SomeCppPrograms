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
        char* data;
    public:
        TemplatedDynArray() : len(0), capacity(0), data(nullptr){}
        TemplatedDynArray(uint64_t capacity) : len(0), capacity(capacity), data(new char[capacity*sizeof(T)]){}
        TemplatedDynArray(const TemplatedDynArray &orig) : len(orig.len), capacity(orig.capacity), data(new char[capacity*sizeof(T)]){for(uint64_t i = 0; i < len; i++) new (data + i*(sizeof(T))) T(orig.data[i*sizeof(T)]);}
        TemplatedDynArray(TemplatedDynArray &&orig) : len(orig.len), capacity(orig.capacity), data(orig.data){orig.data = nullptr;} 
        TemplatedDynArray &operator=(const TemplatedDynArray &orig){
            if(this == &orig)
                return *this;
            else{
                len = orig.len; 
                capacity = orig.capacity;
                delete [] data;
                data = new char[capacity*sizeof(T)]; 
                for(uint64_t i = 0; i < len; i++)
                    new (data + i*sizeof(T)) T(orig.data[i*sizeof(T)]);
                return *this;
            }
        }
        void print();
        void add(T val);
        friend std::ostream &operator<<(std::ostream &os, const TemplatedDynArray &tda){
            os << "{";
            if(tda.len > 0){
                for(uint64_t pos = 0; pos < (tda.len-1)*sizeof(T); pos+=sizeof(T)){
                    os << *(T*)(&tda.data[pos]) << ", ";
                }
                os << *(T*)(&tda.data[(tda.len-1)*sizeof(T)]);
            }
            os << "}";
            return os; 
        }
};

template <typename T>
void TemplatedDynArray<T>::print(){
    std::cout << *this;
}

template <typename T>
void TemplatedDynArray<T>::add(T val){
    if(len == capacity){
        if(capacity == 0){
            capacity = 1;
            data = new char[capacity*sizeof(T)];
            new (data) T(val);
        }  else capacity *= 2;
        const T* old = (const T*)data;        
        data = new char[capacity*sizeof(T)];
        for(uint64_t i = 0; i < len; i++)
            new (data+i*sizeof(T)) T(old[i]);
        new (data+len*sizeof(T)) T(val);
        len++;
        delete [] (char*)old;
    }
    else{
        new (data+len*sizeof(T)) T(val);
        len++;
    }
}


class Elephant {
private:
    std::string name;
public:
    Elephant() : name("") {}
    ~Elephant() {
        std::cout << "dying " << name << " dying\n";
    }
    Elephant(const std::string& name) : name(name) {}
    friend std::ostream& operator <<(std::ostream& s, const Elephant& e) {
    return s << "Elephant " << e.name;
    }  
};

int main() {
    TemplatedDynArray<int> a;
    a.add(3);
    a.add(1);
    for (int i=0; i < 10; i++)
        a.add(i);
    std::cout << a << '\n';
    TemplatedDynArray<int> b = a;
    TemplatedDynArray<int> c = a;

    c = a; // test operator =

    std::cout << b << '\n';
    std::cout << c << '\n';

    TemplatedDynArray<Elephant> elephants;
    elephants.add(Elephant("Eve"));
    elephants.add(Elephant("Alice"));
    elephants.add(Elephant("Bob"));
    std::cout << elephants << '\n';

    b.print();
}