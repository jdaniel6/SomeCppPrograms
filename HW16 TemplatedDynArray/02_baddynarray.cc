#include <iostream>
#include <string>
#include <cstring>

template <typename T>
class BadDynArray{
    private:
        char* data;
        uint32_t len;
    public:
        BadDynArray() : data(nullptr), len(0){}
        ~BadDynArray(){
            delete [] (char*)data;
        }
        BadDynArray(const BadDynArray &orig) : data(new char[orig.len*sizeof(T)]), len(orig.len){
            for(int i = 0; i < len; i++){
                new ((data)+i*sizeof(T)) (T)(orig.data[i*sizeof(T)]);   //is this right? needs to be checked (I don't think it's right)
            //  at i units of T length away from starting char* data pointer, add new T data
            }
        }
        void* operator new(size_t s, void* ptr){
            return ptr;
        }
        BadDynArray<T> &operator=(BadDynArray<T> copy){ // (CHANGED) needed to specify template return type
            if(&copy != this)
                this->len = copy.len;
                std::swap(this->data, copy.data);            
            return *this;
        }
        void add(const T& val){
            const T* old = (const T*) data;
            data = new char[(len+1)*sizeof(T)];
            for(int i = 0; i < len; i++){
                new ( (data)+ i*sizeof(T) ) (T)(old[i]);
            }
            new ( (data)+ len*sizeof(T) ) (T)(val);
            len++;
            delete [] (char*)old;
        }
        friend std::ostream &operator<<(std::ostream &os, const BadDynArray &list){
            for (int i = 0; i < list.len*sizeof(T); i+=sizeof(T)){      // (CHANGED) needed to jump by sizeof(T)
                //os << (T)(list.data[i]) << '\t';        // (CHANGED) list.data[i] points to a char stream; needs to explicitly be cast to type
                os << *(T*)(&list.data[i]) << '\t';
            }
            return os;
        }
};

class Elephant{
    private:
        std::string name;
    public:
        Elephant() : name("") {}
        ~Elephant() {}
        Elephant(const std::string &name) : name(name) {}
        Elephant(char& elephant){   // (CHANGED) this constructor is required to document how to convert char stream to Elephant (in ostream)
            char* e = &elephant;    // (CHANGED) get pointer to data
            std::string output(e+16, strlen(e)-1);  // (CHANGED) cast the data to string. pointer+16 for header bytes, and strlen = the length of the string - 1 (for EOF)
            name = output + "\t";   // (CHANGED) add a tab for easier reading
        }
        friend std::ostream &operator<<(std::ostream &os, const Elephant &e){
            return os << "Elephant " << e.name;
        }
};

int main(){
    BadDynArray<int> a;
    a.add(3);
    a.add(1);
    for(int i = 0; i < 10; i++){
        a.add(i);
    }
    std::cout << a << "\n";

    BadDynArray<int> b = a;
    BadDynArray<int> c = a;

    c = a; // test operator =

    BadDynArray<Elephant> elephants;
    elephants.add(Elephant("Eve"));
    elephants.add(Elephant("Alice"));
    elephants.add(Elephant("Bob"));
    std::cout << elephants << '\n';
}