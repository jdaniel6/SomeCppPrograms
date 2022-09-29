/**
 * @file BigInteger.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A class to define a BigInteger object, capable of storing numbers with infinite precision
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//ULL MAX = 18446744073709551615 ffffffffffffffff
class BigInteger{
    friend std::ostream &operator<<(std::ostream &os, BigInteger num);

    private:
        string NUMBER;
        void pad(BigInteger &num, long digitsToBePadded){
            BigInteger num2("0");

        }
    public:
        BigInteger(){
            this->NUMBER.push_back('0');
        }
        BigInteger(string number){
            this->NUMBER = number;
        }
        BigInteger(unsigned long long number){
            this->NUMBER = to_string(number);
        }
        BigInteger(double number){
            //figure out a way to get mantissa and exponent
            // 2.7 e79 should be represented as 2700000000000000000000000000.....00000 
            // zeros and ones function?
            this->NUMBER = to_string(floor(number));
        }
        BigInteger operator+(BigInteger &operand2){
            if(this->NUMBER.length() > operand2.NUMBER.length()){
                pad(operand2, this->NUMBER.length())
            }
            
        }
};

std::ostream &operator<<(std::ostream &os, BigInteger num){
    return os << num << endl;
}

std::istream &operator>>(std::istream &is, BigInteger num){
    string s;
    is >> s;
    if(s.find_first_not_of("0123456789") == std::string::npos){
        return is >> num;
    }
    else{
        throw std::invalid_argument("Non-numeric character entered");
    }    
}

int main(){
    cout << ULLONG_MAX << endl;
}

