/**
 * @file Daniel_Jeffrey_HW8.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program implementing a dynamic array
 * @version 0.2
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

class DynArray {
private:
	uint32_t* data;
	uint32_t len;
	uint32_t capacity;
	//grow should double the size of the list and copy all the old into the new
	void grow() {
        capacity *= 2;
        uint32_t* temp = new uint32_t[capacity];
        for(uint32_t pos = 0; pos <= len; pos++){
            temp[pos] = data[pos];
        }
        delete [] data;
        data = temp;        
	}
public:
	DynArray(uint32_t capacity);
	~DynArray();
	void add(uint32_t v);
	friend ostream& operator <<(ostream& s, const DynArray& d) {
		
	}
};

DynArray::DynArray(uint32_t capacity) : capacity(capacity), len(0), data(new uint32_t[capacity]) {}

void DynArray::add(uint32_t new_element){
    if(len = capacity-1)
        grow();

}

int main() {
  DynArray a(100); // preallocate 100 size
  for (int i = 0; i < 100; i++)
    a.add(i); // this should take O(100) time
  a.add(101);
  cout << a;
  cout << a[0];
  a[0] = 5;


  int x = 5;
  int *p = &x; // & = (address of) x
  int &r = x; // r is a reference to x
  cout << sizeof(r);

  
}