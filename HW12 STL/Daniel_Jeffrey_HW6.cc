/**
 * @file Daniel_Jeffrey_HW6.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to store STL objects and print STL files
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#if(__cplusplus == 202002L)
    double pi = std::numbers::pi;
    #pragma message("using C++20")
#else
    double pi = 3.141592653589793238462;
    #pragma message("Using pre-C++20")
#endif

//import libraries
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

//class to define where the shape exists
class Shape{
    private:
        double init_x, init_y, init_z;
    public:
        Shape(){
            init_x = init_y= init_z = 0;
        }

};

//class to define how pre-defined shapes are written in STL
class Model : public Shape{
    private:
        string predefshape_name;
};

//class to write models of predefined shapes to a file
class STL : public Model, Shape{
    private:
        string name;
    public:
        //constructors
        STL(){
            name = "shape"
        }
        STL(Shape s){

        }
        STL(Shape s[], uint64_t num_of_elements){

        }
        friend ostream &operator<<(ostream &os, STL stl){

        }
}