/**
 * @file Daniel_Jeffrey_HW1A.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to show the Collatz Conjecture (also known as the 3n+1 Conjecture)
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
using namespace std;

//Main driver function
int main(){
    uint32_t n = 10;
    
    //get valid input
    while(true){
        cout << "Please enter a positive integer: ";
        cin >> n;
        if(n < 1){
            cout << "\nInvalid input.";
        }
        else
            break;
    }
    cout << "\n" << n << "\t";
    while(n > 1){
        if(n % 2 == 0){
            n = n / 2;
        }
        else{
            n = 3 * n + 1;
        }
        cout << n << "\t";
    }

}