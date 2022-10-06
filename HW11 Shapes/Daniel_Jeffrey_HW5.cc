/**
 * @file Daniel_Jeffrey_HW5.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to store Shape objects and display them using PostScript
 * @version 0.1
 * @date 2022-10-04
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

class Shape{
    protected:
        double centre_x, centre_y;
        double fill_r, fill_g, fill_b;
    public:
        Shape(){}
        Shape(double x, double y) : centre_x(x), centre_y(y) {}
        Shape(double x, double y, double fill_r, double fill_g, double fill_b) : centre_x(x), centre_y(y), fill_r(fill_r), fill_g(fill_g), fill_b(fill_b) {}
        virtual void print(ostream &fileToOutputTo) = 0;
        virtual double area() = 0;
        virtual double perimeter() = 0;
};

class Circle : public Shape{
    private:
        double radius;
    public:
        Circle(){
            centre_x = centre_y = radius = fill_r = fill_g = fill_b = 0.0;
        }
        Circle(double centre_x, double centre_y, double radius) : Shape(centre_x, centre_y), radius(radius) {
            //circle without RGB parameters
            fill_r = fill_g = fill_b = 0.0;
        }
        Circle(double centre_x, double centre_y, double radius, double fill_r, double fill_g, double fill_b) : Shape(centre_x, centre_y, fill_r, fill_g, fill_b), radius(radius) {
            //circle with RGB parameters
        }
        void display(){
            cout << "Circle found centred at <" << centre_x << ", " << centre_y << ">, with a radius of " << radius << " units." << endl;
            cout << "Circle is filled with a color whose RGB is given by <" << fill_r << ", " << fill_g << ", " << fill_b << ">." << endl;
        }
        void print(ostream &fileToOutputTo) override{
            ostringstream os;
            os << "%Circle\n";
            os << centre_x << " " << centre_y << " " << radius << " 0 360 arc\n";
            os << fill_r << " " << fill_g << " " << fill_b << " setrgbcolor fill\n\n";
            fileToOutputTo << os.str();
        }
        double area() override{
            return (pi * radius * radius);
        }
        double perimeter() override{
            return (2 * pi * radius);
        }
};

class Rect : public Shape{
    private:
        double length, height;
    public:
        Rect(){
            centre_x = centre_y = length = height = fill_r = fill_g = fill_b = 0.0;
        }
        Rect(double centre_x, double centre_y, double length, double height) : Shape(centre_x, centre_y), length(length), height(height) {
            //circle without RGB parameters
            fill_r = fill_g = fill_b = 0.0;
        }
        Rect(double centre_x, double centre_y, double length, double height, double fill_r, double fill_g, double fill_b) : Shape(centre_x, centre_y, fill_r, fill_g, fill_b), length(length), height(height) {
            //circle with RGB parameters
        }
        void display(){
            cout << "Rectangle found with base vertex at <" << centre_x << ", " << centre_y << ">, with a base length of " << length << " and height of " << height << " units." << endl;
            cout << "Rectangle is filled with a color whose RGB is given by <" << fill_r << ", " << fill_g << ", " << fill_b << ">." << endl;
        }
        void print(ostream &fileToOutputTo) override{
            ostringstream os;
            os << "%Rectangle\n";
            os << centre_x << " " << centre_y << " moveto " << (centre_x + length) << " " << centre_y << " lineto " << (centre_x + length) << " " << (centre_y + height) << " lineto " << centre_x << " " << (centre_y + height) << " lineto closepath\n";
            os << fill_r << " " << fill_g << " " << fill_b << " setrgbcolor fill\n\n";
            fileToOutputTo << os.str();
        }
        double area() override{
            return (length * height);
        }
        double perimeter() override{
            return (2 * (length + height));
        }
};

class Triangle : public Shape{
    private:
        double x2, y2, x3, y3;
        double sqr(double input){
            return input * input;
        }
        double getDistance(double a_point_x, double a_point_y, double b_point_x, double b_point_y){
            return(sqrt( sqr(a_point_x - b_point_x) + sqr(a_point_y - b_point_y) ));
        }

    public:
        Triangle(){
            centre_x = centre_y = x2 = y2 = x3 = y3 = fill_r = fill_g = fill_b = 0.0;
        }
        Triangle(double centre_x, double centre_y, double x2, double y2, double x3, double y3) : Shape(centre_x, centre_y), x2(x2), y2(y2), x3(x3), y3(y3) {
            //circle without RGB parameters
            fill_r = fill_g = fill_b = 0.0;
        }
        Triangle(double centre_x, double centre_y, double x2, double y2, double x3, double y3, double fill_r, double fill_g, double fill_b) : Shape(centre_x, centre_y, fill_r, fill_g, fill_b), x2(x2), y2(y2), x3(x3), y3(y3) {
            //circle with RGB parameters
        }
        void display(){
            cout << "Triangle found at <(" << centre_x << ", " << centre_y << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")>." << endl;
            cout << "Triangle is filled with a color whose RGB is given by <" << fill_r << ", " << fill_g << ", " << fill_b << ">." << endl;
        }
        void print(ostream &fileToOutputTo) override{
            ostringstream os;
            os << "%Triangle\n";
            os << centre_x << " " << centre_y << " moveto " << x2 << " " << y2 << " lineto " << x3 << " " << y3 << " lineto closepath\n";
            os << fill_r << " " << fill_g << " " << fill_b << " setrgbcolor fill\n\n";
            fileToOutputTo << os.str();
        }
        double area() override{
            return abs(0.5 * ((centre_x * (y2 - y3)) + (x2 * (y3 - centre_y)) + (x3 * (centre_y - y2))));
        }
        double perimeter() override{
            return (getDistance(centre_x, centre_y, x2, y2) + getDistance(x2,y2,x3,y3) + getDistance(x3,y3, centre_x, centre_y));
        }
};

int main(){
    vector<Shape*> shapes;
    shapes.push_back(new Circle(100, 200, 50, 1.0, 0.0, 0.0));
    shapes.push_back(new Rect(200, 300, 50, 40, 0.0, 1.0, 0.0));
    shapes.push_back(new Triangle(100, 500, 300, 600, 400, 500, 0.0, 0.0, 1.0));

    ofstream file("out.ps", std::ios_base::app);
    
    file << "%!PS\n\n";

    for(auto s : shapes){
        s -> print(file);
    }
    for(auto s : shapes){
        delete s;
    }

    file << "showpage";

    file.close();
}