/**
 * @file Daniel_Jeffrey_HW1B.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to calculate radius of circumscribed circles for different polygons
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

#if(__cplusplus == 202002L)
    double pi = std::numbers::pi;
    #pragma message("using C++20")
#else
    double pi = 3.141592653589793238462;
    #pragma message("Using pre-C++20\n")
#endif

double getNextRadius(double currentRadius, double numberOfSides){
    return(currentRadius / cos(pi/numberOfSides));
}

int main(){
    //initPi();
    double currentRadius = 1;
    int numberOfSides = 3;
    int powerOfTen = 10;
    for( ; numberOfSides <= 1000000 ; numberOfSides++){
        currentRadius = getNextRadius(currentRadius, numberOfSides);
        if(numberOfSides % powerOfTen == 0){
            cout << "n = " << numberOfSides << "\t\t Radius = " << currentRadius << endl;
            powerOfTen *= 10;
        }
        
    }
}
