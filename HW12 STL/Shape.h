#ifndef _SHAPE_H_
#define _SHAPE_H_

//import libraries
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

class BaseTriangle{
    public:
        double n1, n2, n3;  //normal
        double x1, y1, z1;  //first vertex
        double x2, y2, z2;  //second vertex
        double x3, y3, z3;  //third vertex
    public:
        BaseTriangle(){
            x1 = x2 = x3 = y1 = y2 = y3 = z1 = z2 = z3 = 0;
        }
        BaseTriangle(double x1, double y1, double x2, double y2, double x3, double y3) : n1(0), n2(0), n3(1), x1(x1), y1(x1), z1(0), x2(x2), y2(y2), z2(0), x3(x3), y3(x3), z3(0) {}
        BaseTriangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) : n1(0), n2(0), n3(1), x1(x1), y1(x1), z1(z1), x2(x2), y2(x2), z2(z2), x3(x3), y3(x3), z3(z3) {}
        BaseTriangle(double n1, double n2, double n3, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) : n1(n1), n2(n2), n3(n3), x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2), x3(x3), y3(y3), z3(z3) {}
};

class Shape : public BaseTriangle{
    public:
        string name;
        vector<BaseTriangle> list_of_base_triangles;
        uint64_t num_of_base_triangles;
    public:
        Shape() : BaseTriangle(){
            name = "";
            num_of_base_triangles = 0;
        }
        Shape(uint64_t num_of_base_triangles) : name(""), num_of_base_triangles(num_of_base_triangles) {}
        Shape(vector<BaseTriangle> base_triangles) : name(""), list_of_base_triangles(list_of_base_triangles), num_of_base_triangles(num_of_base_triangles) {}
        friend ostream &operator<< (ostream &os, Shape &s);
        ostream &print(ostream &os, Shape s);
};

#endif