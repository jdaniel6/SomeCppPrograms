/**
 * @file compilerIndependentPi.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A stub to define pi using either std::numbers::pi if C++20, else using a predefined value
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//START
#if(__cplusplus == 202002L)
    long double pi = std::numbers::pi;
    #pragma message("using C++20")
#else
    long double pi = 3.14159265358979323846264338327950288419716939937510;
    #pragma message("Using pre-C++20")
#endif
//END


//import libraries
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    cout << "This stub showcases a defition of pi that is independent of C++ compiler version." << endl;
    (__cplusplus == 202002L) ? cout << "The C++ Version is C++20" << endl : cout << "The C++ Version is not C++20" << endl;
    cout << "Pi is currently defined as " << setprecision(32) << pi << endl;
}