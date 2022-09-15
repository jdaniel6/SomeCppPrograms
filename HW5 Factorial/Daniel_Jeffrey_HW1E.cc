/**
 * @file Daniel_Jeffrey_HW1E.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to calculate Factorial of a number
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
#include <cmath>

typedef long long int BigInteger;

using namespace std;

BigInteger fact(BigInteger n){
    if(n == 1)
        return n;
    else   
        return(n * fact(n-1));
}

int main(){
    double_t dummyInput = 0;
    BigInteger input = 0;
    cout << "Enter a positive integer:" << endl;
    while(true){
        cin >> dummyInput;
        if(dummyInput <= 0){
            cout << "\n" << "NO! Enter a POSITIVE integer:" << endl;
        } else
        if(trunc(dummyInput) != dummyInput){
            cout << "\n" << "NO! Enter a positive INTEGER:" << endl;
        }
        else {
            input = (BigInteger)dummyInput;
            break;
        }
    }
    cout << input << "! = " << fact(input);
    
}