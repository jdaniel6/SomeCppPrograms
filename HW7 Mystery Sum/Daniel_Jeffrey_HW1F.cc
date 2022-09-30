/**
 * @file Daniel_Jeffrey_HW1F.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to calculate a specific sum
 * @version 0.2
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022
 *
 */

// import libraries
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define VeryLargeN 1000000

double getInput()
{
    double input = 0;
    cout << "Enter a positive integer:" << endl;
    while (true)
    {
        cin >> input;
        if (input <= 0)
        {
            cout << "\n"
                 << "NO! Enter a POSITIVE integer:" << endl;
        }
        else if (trunc(input) != input)
        {
            cout << "\n"
                 << "NO! Enter a positive INTEGER:" << endl;
        }
        else
        {
            return input;
        }
    }
}

int main()
{
    double input = getInput();
    float sum1 = 0, sum2 = 0;
    float sum3 = 0;
    float result1 = 0, result2 = 0, result3 = 0;

    for (uint64_t i = 1; i <= input; i++)
    {
        sum1 += (1.0F / (i * i));
    }
    result1 = sqrtf(6 * sum1);
    cout << "result1 = " << result1 << endl;

    for (uint64_t j = 10; j < 1000000000; j *= 10){
        cout << setprecision(8);
        sum2 = sum3 = 0;
        for (uint64_t i = 1; i <= j; i++){
            sum2 += (1.0F / (i * i));
        }
        result2 = sqrtf(6 * sum2);
        cout << "result2 = " << result2 << endl;

        for (uint64_t i = j; i > 0; i--){
            sum3 += (1.0 / (i * i));
        }
        result3 = sqrt(6 * sum3);
        cout << "result3 = " << result3 << endl;
    }
}