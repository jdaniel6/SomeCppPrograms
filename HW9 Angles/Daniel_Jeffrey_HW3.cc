/**
 * @file Daniel_Jeffrey_HW3.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to compute sums of squares, and to calculate angles of right triangles
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
#include <cmath>

using namespace std;

void print(const uint64_t array[], uint32_t len){
    for(int i = 0; i < len; i++){
        cout << array[i] << "\t";
    }
    cout << "\n";
}

uint64_t sumsq(uint64_t startPosition, uint64_t endPosition){
    uint64_t sum = 0;
    for(int i = startPosition; i <= endPosition; i++){
        sum += i*i;
    }
    return sum;
}

double angle(uint64_t sideA, uint64_t sideB){
    return atan2(sideB, sideA);
}

void polar2rect(double r, double angPhi, double &xOut, double &yOut){
    xOut = r * cos(angPhi);
    yOut = r * sin(angPhi);
}

void multtable(uint64_t n){
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=n; j++){
            cout << i*j << "\t";
        }
        cout << "\n";
    }
}

void cubeit(uint64_t array[], uint32_t len){
    for(int i = 0; i < len; i++){
        array[i] = array[i]*array[i]*array[i]; //could speed this up
    }
}


int main(){
    uint64_t s = sumsq(1,5);

    double ang = angle(3,4);
    cout << ang << "\n";

    double deg = 0; //convert ang to degrees

    double r = 5; //find a way to improve the ang 

    double x, y;

    polar2rect(r, ang, x, y);
    cout << "x = " << x << "\ty = " << y << "\n";

    multtable(5);

    uint64_t a[] = {1, 3, 5, 9};

    cubeit(a, 4);

    print(a, 4);

}