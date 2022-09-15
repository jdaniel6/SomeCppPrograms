/**
 * @file Daniel_Jeffrey_HW2A_CommandLine.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief An interactive program to print the NOAA windchill table as provided in https://www.weather.gov/safety/cold-wind-chill-chart, as updated on 2nd September 2022, using the command line.
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//import libraries
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

void printTable(){
    cout <<    "\t\t\t\t\t\t\t\t  \033[1;4;5mWIND CHILL CHART\033[0m\n" << endl;
    cout <<    "\033[1;4m     |    40      35      30      25      20      15      10      5       0       -5      -10     -15     -20     -25     -30     -35     -40     -45\033[0m" << endl;
    cout <<    "\033[1m5\033[0m    |    \033[96m36      31      25      19      13      7       1       -5      -11     -16     \033[93m-22     -28     -34     -40     -46     -52     \033[95m-57     -63\033[0m" << endl;
    cout <<    "\033[1m10\033[0m   |    \033[96m34      27      21      15      9       3       -4      -10     -16     \033[93m-22     -28     -35     -41     \033[95m-47     -53     -59     -66     -72\033[0m" << endl;
    cout <<    "\033[1m15\033[0m   |    \033[96m32      25      19      13      6       0       -7      -13     \033[93m-19     -26     -32     -39     \033[95m-45     -51     -58     -64     \033[91m-71     -77\033[0m" << endl;
    cout <<    "\033[1m20\033[0m   |    \033[96m30      24      17      11      4       -2      -9      -15     \033[93m-22     -29     -35     \033[95m-42     -48     -55     -61     \033[91m-68     -74     -81\033[0m" << endl;
    cout <<    "\033[1m25\033[0m   |    \033[96m29      23      16      9       3       -4      -11     -17     \033[93m-24     -31     \033[95m-37     -44     -51     -58     \033[91m-64     -71     -78     -84\033[0m" << endl;
    cout <<    "\033[1m30\033[0m   |    \033[96m28      22      15      8       1       -5      -12     \033[93m-19     -26     -33     \033[95m-39     -46     -53     \033[91m-60     -67     -73     -80     -87\033[0m" << endl;
    cout <<    "\033[1m35\033[0m   |    \033[96m28      21      14      7       0       -7      -14     \033[93m-21     -27     \033[95m-34     -41     -48     \033[91m-55     -62     -69     -76     -82     -89\033[0m" << endl;
    cout <<    "\033[1m40\033[0m   |    \033[96m27      20      13      6       -1      -8      -15     \033[93m-22     -29     \033[95m-36     -43     -50     \033[91m-57     -64     -71     -78     -84     -91\033[0m" << endl;
    cout <<    "\033[1m45\033[0m   |    \033[96m26      19      12      5       -2      -9      -16     \033[93m-23     -30     \033[95m-37     -44     \033[91m-51     -58     -65     -72     -79     -86     -93\033[0m" << endl;
    cout <<    "\033[1m50\033[0m   |    \033[96m26      19      12      4       -3      -10     -17     \033[93m-24     -31     \033[95m-38     -45     \033[91m-52     -60     -67     -74     -81     -88     -95\033[0m" << endl;
    cout <<    "\033[1m55\033[0m   |    \033[96m25      18      11      4       -3      -11     \033[93m-18     -25     \033[95m-32     -39     -46     \033[91m-54     -61     -68     -75     -82     -89     -97\033[0m" << endl;
    cout <<    "\033[1m60\033[0m   |    \033[96m25      17      10      3       -4      -11     \033[93m-19     -26     \033[95m-33     -40     \033[91m-48     -55     -62     -69     -76     -84     -91     -98\033[0m" << endl;
    cout <<    "\n\t\t\t  \033[1;4mFrostbite Times:\033[0m      \033[106m  \033[0m : >45 minutes     \033[103m  \033[0m : 30 minutes      \033[105m  \033[0m : 10 minutes     \033[101m  \033[0m : 5 minutes" << endl;
    return;
}

void cls(){
    cout << "\033[2J\033[1;1H";
    return;
}

int32_t getWindChill(int32_t temperature, int32_t windspeed){
    double temp = 35.74 + (0.6215 * temperature) - (35.75 * pow(windspeed, 0.16)) + (0.4275 * temperature * pow(windspeed, 0.16));
    return (int32_t)(round(temp));
}

int32_t convertTemp(int32_t temperature, int32_t unit){
    if(unit == 'f' || unit == 'F')
        return temperature;
    else
        return (int32_t)(round(((temperature*9.0)/5.0)+32));
}

int32_t convertSpeed(int32_t windspeed, int32_t unit){
    if(unit == 'm' || unit == 'M')
        return windspeed;
    else
        return (int32_t)(round(windspeed/1.609));
}

void acceptUserOption(){
    cout << "Type in the option you would like to use:" << endl;
    cout << "1. Print Windchill Table" << endl;
    cout << "2. Get Windchill value for given temperature and windspeed" << endl;
    cout << "3. Exit" << endl;
    uint32_t input = 0;
    int32_t temperature = 0;
    char unit = 'F';
    int32_t windspeed = 0;
    cin >> input;
    switch (input)
    {
    case 1:
        printTable();
        break;
    case 2:
        cout << "Enter the parameters with their units as C or F for temperature, and k (for kmph) or m (for mph) for windspeed. Leave a space between value and unit of parameter (Example: 36 F)" << endl;
        cout << "Enter the temperature in C or F as described above (Example 36 F): ";
        cin >> temperature >> unit;
        cout << "Enter the windspeed in k or m as described above (Example 15 k): ";        
        cin >> windspeed >> unit; 
        temperature = convertTemp(temperature, unit);
        windspeed = convertSpeed(windspeed, unit);
        if(temperature > 50 || windspeed < 3){
            cout << "Invalid parameters! Windchill is only defined for temperatures below 50 F (10 C) and windspeeds higher than 3 mph (~5 kmph)" << endl; 
            break;
        }  
        cout << "Windchill for your parameters is: " << getWindChill(temperature,windspeed) << endl;
        break;
    case 3:
        cls();
        cout << "\033[1;5mGoodbye!\033[0m" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        cls();
        exit(0);
    default:
        break;
    }
}

int main(int argc, char *argv[]){
    uint32_t input = 0;
    int32_t temperature = 0;
    char unit = 'F';
    int32_t windspeed = 0;
    
    if(argc <= 1){
        printTable();
        return 0;
    }
    if(argc >= 5){
        cout << "Sorry, multiple command line arguments are not accepted at the moment." << endl;
        return 0;
    }
    if(argv[1] == "help" || argv[1] == "-h"){
        cout << "Program to print the Windchill Chart. " << endl;
    }
    else{
        if(argv[1] == "wcmet" || argv[1] == "-m"){
            cout << "Program to get the windchill value based on metric units. " << endl;
            cout << getWindChill(convertTemp(argv[2], 'C'), convertSpeed(argv[3]));
        }
        else{
            if(argv[1] == "wcimp" || argv[1] == "-i"){
                cout << "Program to get the windchill value based on imperial units. " << endl;
            }
            else{
                if(argv[1] == "exit" || argv[1] == "-q"){
                    cout << "Exit the program. " << endl;
                }
                else{
                    cout << "Invalid command line arguments, try again. Use -h for help." << endl;
                }
            }
        }
    }

    return 0;
}
