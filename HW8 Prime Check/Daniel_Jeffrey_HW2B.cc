/**
 * @file Daniel_Jeffrey_HW2B.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to check if a number is prime or not
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
#include <cmath>

using namespace std;

#define VeryLargeN 2147483647

double getInput(){
    double input = 0;
    cout << "Enter a positive integer:" << endl;
    while(true){
        cin >> input;
        if(input <= 0){
            cout << "\n" << "NO! Enter a POSITIVE integer:" << endl;
        } else
        if(trunc(input) != input){
            cout << "\n" << "NO! Enter a positive INTEGER:" << endl;
        }
        else {
            return input;
        }
    }
}

bool isPrime(uint32_t n){
    if(n % 2 == 0)
        return false;
    for(int i = 3; i < sqrt(n); i +=2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    uint32_t input = (uint32_t)getInput();
    if(isPrime(input))
        cout << "The number " << input << " is: PRIME" << endl;
    else
        cout << "The number " << input << " is: NOT PRIME" << endl;
}