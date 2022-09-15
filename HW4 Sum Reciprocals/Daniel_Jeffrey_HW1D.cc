/**
 * @file Daniel_Jeffrey_HW1D.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to demonstrate how sums of reciprocals differ with different datatypes
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;


vector<float_t> floatSum(){
    float_t sum1F = 0.0F;
    float_t sum2F = 0.0F;
    for(float_t f = 1.0F; f < 101.0F; f += 1.0f){
        float_t reciprocal = 1.0F/f;
        sum1F += reciprocal;
    }
    for(float_t f = 100.0F; f > 0.0F; f -= 1.0f){
        float_t reciprocal = 1.0F/f;
        sum2F += reciprocal;
    }
    vector<float_t> result = {sum1F, sum2F};
    return(result);
}

vector<double_t> doubleSum(){
    double_t sum1D = 0.0;
    double_t sum2D = 0.0;
    for(double_t d = 1.0; d < 101.0; d += 1.0){
        double_t reciprocal = 1.0/d;
        sum1D += reciprocal;
    }
    for(double_t d = 100.0; d > 0.0; d -=1.0){
        double_t reciprocal = 1.0/d;
        sum2D += reciprocal;
    }
    vector<double_t> result = {sum1D, sum2D};
    return(result);
}
int main(){
    vector<float_t> floatResult = floatSum();
    vector<double_t> doubleResult = doubleSum();
    
    cout << "sum1F = " << setprecision(3) << floatResult[0] << ", sum2F = " << floatResult[1] << endl;
    cout << "sum1D = " << doubleResult[0] << ", sum2D = " << doubleResult[1] << endl;
    cout << "sum1F - sum2F = " << floatResult[0] - floatResult[1] << endl;
    cout << "sum1D - sum2D = " << doubleResult[0] - doubleResult[1] << endl;

}