/**
 * @file Daniel_Jeffrey_HW1F.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to calculate a specific sum
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

#define VeryLargeN 10000

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

int main(){
    double input = getInput();
    float sum1 = 0, sum2 = 0, sum3 = 0;
    float result1 = 0, result2 = 0, result3 = 0;
    
    for(int i = 1; i <= input; i++){
        sum1+= (1.0F/(i*i));
    }
    result1 = sqrtf(6 * sum1);
    cout << "result1 = " << result1 << endl;

    for(int i = 1; i <= VeryLargeN; i++){
        sum2+= (1.0F/(i*i));
    }
    result2 = sqrtf(6 * sum2);
    cout << "result2 = " << result2 << endl;

    for(int i = VeryLargeN; i > 0; i--){
        sum3+= (1.0F/(i*i));
    }
    result3 = sqrtf(6 * sum3);
    cout << "result3 = " << result3 << endl;


}