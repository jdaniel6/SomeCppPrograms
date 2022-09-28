/**
 * @file Daniel_Jeffrey_HW4.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to manipulate complex numbers and circles
 * @version 0.2
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#if(__cplusplus == 202002L)
    double pi = std::numbers::pi;
    #pragma message("using C++20")
#else
    double pi = 3.141592653589793238462;
    #pragma message("Using pre-C++20\n")
#endif

//import libraries
#include <iostream>
#include <cmath>

using namespace std;

class Complex{
    friend std::ostream &operator<<(std::ostream &os, Complex &c);
    
    private:
        double realPart;
        double imaginaryPart;
    public:
        Complex(){
            realPart = 0;
            imaginaryPart = 0;
        }

        Complex(double realPart, double imaginaryPart){
            this->realPart = realPart;
            this->imaginaryPart = imaginaryPart;
        }

        Complex(double realPart){
            this->realPart = realPart;
            imaginaryPart = 0;
        }

        Complex operator +(const Complex &operand2){ //complex + complex
            Complex sum;
            sum.realPart = this->realPart + operand2.realPart;
            sum.imaginaryPart = this->imaginaryPart + operand2.imaginaryPart;
            return sum;
        }
        Complex operator +(const double &operand2){ //complex + real
            Complex sum;
            sum.realPart = this->realPart+operand2;
            sum.imaginaryPart = this->imaginaryPart;
            return sum;
        }
};


class Circle{
    friend std::ostream &operator<<(std::ostream &os, Circle &c);

    private:
        double x_centre;
        double y_centre;
        double radius;

        double getDistance(double a_point_x, double a_point_y, double b_point_x, double b_point_y){
            return(sqrt( sqr(a_point_x - b_point_x) + sqr(a_point_y - b_point_y) ));
        }

        double sqr(double input){
            return input * input;
        }
        
    public:
        Circle(){
            x_centre = 0;
            y_centre = 0;
            radius = 0;
        }
        Circle(double x, double y, double r){
            x_centre = x;
            y_centre = y;
            radius = r;
        }
        bool contains(double x_Point, double y_Point){
            if(getDistance(this->x_centre, this->y_centre, x_Point, y_Point) <= this->radius )
                return true;
            else
                return false;
        }
};



std::ostream &operator<<(std::ostream &os, Complex &c){
    return os << c.realPart << " + " << c.imaginaryPart << "i" << endl;
}

std::ostream &operator<<(std::ostream &os, Circle &c){
    return os << "Circle centered at (" << c.x_centre << ", " << c.y_centre << ") with a radius of " << c.radius << endl;
}



int main(){
    Complex c1;
    Complex c2(1.0, 2.5);
    Complex c3 = 2.5;
    Complex c4 = c2 + c3;
    cout << c4 << "\n";

    double x = 50, y = 62.5, r = 10;
    Circle c(x,y,r);
    
    cout << c.contains(x+8, y) << "\n";
    cout << c.contains(x+10, y) << "\n";
    cout << c.contains(x+10, y+3) << "\n";
    cout << c.contains(x, y+10) << "\n";
    double dx = r * cos(45 * pi / 100);
    cout << c.contains(x + dx, y + dx) << "\n";
    
}