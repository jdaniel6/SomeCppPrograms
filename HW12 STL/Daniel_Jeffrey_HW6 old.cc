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
using iterator = double**;

//class to define where the shape exists
class Shape{
    private:
        string name;
    public:
        Shape(){
            name = "";
        }
        virtual iterator begin() const {} = 0;


};

class Triangle : public Shape{
    private:
        double x1, y1, z1;
        double x2, y2, z2;
        double x3, y3, z3;
    public:
        Triangle() : Shape(){
            x1 = x2 = x3 = y1 = y2 = y3 = z1 = z2 = z3 = 0;
        }
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : x1(x1), y1(x1), z1(0), x2(x2), y2(x2), z2(0), x3(x3), y3(x3), z3(0), Shape() {}
        Triangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) : x1(x1), y1(x1), z1(z1), x2(x2), y2(x2), z2(z2), x3(x3), y3(x3), z3(z3), Shape() {}
        friend Model;
};

//class to define how pre-defined shapes are written in STL
class Model : public Shape{
    private:
        string predefshape_name;
    public:
        Model(){
            predefshape_name = "null figure";
        }

        friend ostream &operator<< (ostream &os, Model m){
            os << "solid " << m.predefshape_name << "\n";
            for(Triangle t : m){
                os << "facet normal 0 0 0" << "\n";
                os << "outer loop " << t.x1 << " " << t.x2 << " " << t.x3 << "\n";
                os << "outer loop " << t.y1 << " " << t.y2 << " " << t.y3 << "\n";
                os << "outer loop " << t.z1 << " " << t.z2 << " " << t.z3 << "\n";
            }
        }
};

