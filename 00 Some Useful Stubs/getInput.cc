/**
 * @file getInput.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A stub to get a non-negative integer value from the user
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


//import libraries
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

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
    cout << "You entered " << input << endl;
}