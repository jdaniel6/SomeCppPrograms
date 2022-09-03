/**
 * @file Daniel_Jeffrey_HW1C.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to sum the numbers 1-100 using both the Gaussian Formula and a loop
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
using namespace std;

//Calculate result using Gaussian formula
uint32_t gaussFormula(){
    uint32_t n = 100;
    return (n * (n+1)) / 2;
}

//Calculate result using a for loop
uint32_t loop(){
    uint32_t sum = 0;
    for(uint32_t i = 1; i <= 100; i++){
        sum += i;
    }
    return sum;
}

//Main driver function
int main(){
    uint32_t gF = gaussFormula();
    uint32_t l = loop();
    const char* op = (gF==l)?"Both Results are the same.":"Both results are not the same.";
    cout << "Gauss Results: " << gF << endl;
    cout << "Loop Results: " << l << endl;
    cout << op << endl;
    return 0;
}