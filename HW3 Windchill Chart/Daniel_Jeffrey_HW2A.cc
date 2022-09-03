/**
 * @file Daniel_Jeffrey_HW2A.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to print the NOAA windchill table as provided in https://www.weather.gov/safety/cold-wind-chill-chart , as updated on 2nd September 2022
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
#include <cmath>
using namespace std;

//function to get the Wind Chill Temperature
int32_t getWindChill(int32_t temperature, int32_t windspeed){
    double temp = 35.74 + (0.6215 * temperature) - (35.75 * pow(windspeed, 0.16)) + (0.4275 * temperature * pow(windspeed, 0.16));
    return (int32_t)(round(temp));
}

//main driver function
int main(){
    cout << "\t\033[4m\t";
    for(int32_t temperature = 40; temperature > -46; temperature-=5){
        cout << temperature << "\t";
    }
    cout << "\033[0m\n";
    for(int32_t windspeed = 5; windspeed < 61; windspeed+=5){
        cout << windspeed << "\t|\t";
        for(int32_t temperature = 40; temperature > -46; temperature-=5){
            cout << getWindChill(temperature, windspeed) << "\t";
        }
        cout << "\n";
    }
}