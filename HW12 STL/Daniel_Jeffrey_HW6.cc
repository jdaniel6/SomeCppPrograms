/**
 * @file Daniel_Jeffrey_HW6.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to store STL objects and print STL files
 * @version 0.2
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Shape.h"

using namespace std;

//class to define where the shape exists

class Triangle : public Shape{
    private:
        //
    public: 
        Triangle() : Shape(1){}
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
            vector<BaseTriangle> temp;
            temp.push_back(BaseTriangle(x1, y1, x2, y2, x3, y3));
            this->list_of_base_triangles = temp;
            this->name = "unnamed_triangle";
        }
        //Triangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) : x1(x1), y1(x1), z1(z1), x2(x2), y2(x2), z2(z2), x3(x3), y3(x3), z3(z3) {}
};

class Cube : public Shape{
    private:
        //
    public:
        Cube() : Shape(12){}
        Cube(double init_x, double init_y, double init_z, double side_length) {}
        Cube(double side_length) {
            vector<BaseTriangle> temp;
            temp.push_back(BaseTriangle(0, 0, 1, 0, side_length, side_length, side_length, 0, side_length, side_length, side_length, side_length));
            temp.push_back(BaseTriangle(0, 0, 1, side_length, 0, side_length, 0, side_length, side_length, 0, 0, side_length));
            temp.push_back(BaseTriangle(0, 0, -1, 0, 0, 0, side_length, side_length, 0, side_length, 0, 0));
            temp.push_back(BaseTriangle(0, 0, -1, side_length, side_length, 0, 0, 0, 0, 0, side_length, 0));
            temp.push_back(BaseTriangle(0, -1, 0, 0, 0, 0, side_length, 0, side_length, 0, 0, side_length));
            temp.push_back(BaseTriangle(0, -1, 0, side_length, 0, side_length, 0, 0, 0, side_length, 0, 0));
            temp.push_back(BaseTriangle(1, 0, 0, side_length, 0, side_length, side_length, side_length, 0, side_length, side_length, side_length));
            temp.push_back(BaseTriangle(1, 0, 0, side_length, side_length, 0, side_length, 0, side_length, side_length, 0, 0));
            temp.push_back(BaseTriangle(0, 1, 0, side_length, side_length, 0, 0, side_length, side_length, side_length, side_length, side_length));
            temp.push_back(BaseTriangle(0, 1, 0, 0, side_length, side_length, side_length, side_length, 0, 0, side_length, 0));
            temp.push_back(BaseTriangle(1, 0, 0, 0, 0, 0, 0, side_length, side_length, 0, side_length, 0));
            temp.push_back(BaseTriangle(1, 0, 0, 0, side_length, side_length, 0, 0, 0, 0, 0, side_length));
            this->list_of_base_triangles = temp;
            this->name = "unnamed_cube";
        }
};

//class to define how pre-defined shapes are written in STL

int main(){
    Triangle t(0, 0, 0, 2, 2, 0);
    Cube c(50);
    cout << t;
    cout << c;

    ofstream file("out.stl", ios_base::app);

    c.print(file, c);
}

