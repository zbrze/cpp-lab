#include "fraction.h"
#include<iostream>
#include <algorithm>  

using namespace std;


Fraction :: Fraction(int numerator, int dominator){
	this->numerator =  numerator;
    if( dominator == 0) throw std::invalid_argument("Denominator cannot be zero");
    else this->denominator = dominator;
	
}

void Fraction :: setDenominator(int dominator){
    if( dominator == 0) throw std::invalid_argument("Denominator cannot be zero");
    else this->denominator = dominator;
}
/*

Fraction Fraction :: operator+ (Fraction other){
     int common_factor = std::__gcd(this->denominator, other.getDenominator());
	 int denominator_result = (this->denominator *other.getDenominator()) / common_factor; 
	 int numerator_result = (this->numerator)*(denominator/this->denominator) + (other.getNumerator())*(denominator_result/other.getDenominator()); 
	 Fraction *result = new Fraction(numerator_result, denominator_result);
	 int gcd = std::__gcd(result->numerator, result->denominator);
	 result->denominator = result->denominator/gcd;
	 result->numerator = result->numerator/gcd;
	 return *result;
     }

Fraction Fraction :: operator* (Fraction other){
	 int denominator_result = this->denominator * other.getDenominator(); 
	 int numerator_result = this->numerator * other.getNumerator(); 
	 Fraction *result = new Fraction( numerator_result, denominator_result);
	 int gcd = std::__gcd(result->numerator, result->denominator);
	 result->denominator = result->denominator/gcd;
	 result->numerator = result->numerator/gcd;
	 return *result;
    }*/

 
int lcm(int a, int b)
{
    return a/std::__gcd(a,b)*b;
}

Fraction Fraction :: operator+(const Fraction other_f) const{
    int denominator_result = lcm(this->denominator,other_f.getDenominator());
	int numerator_result;
    if(this->denominator != other_f.getDenominator()){
        numerator_result = denominator_result/this->denominator*other_f.getNumerator()+denominator_result/other_f.getDenominator()*this->numerator;
    }else
    {
        denominator_result = this->denominator;
        numerator_result = this->numerator + other_f.getNumerator();
    }
    int nwd = __gcd(numerator_result,denominator_result);
    numerator_result /=nwd;
    denominator_result /=nwd;

    Fraction result = Fraction(numerator_result, denominator_result);
    return result;
}



Fraction Fraction :: operator*(const Fraction other_f) const{
        int numerator_result = this->numerator*other_f.getNumerator();
        int denominator_result = this->denominator*other_f.getDenominator();
        int nwd = std:: __gcd(numerator_result, denominator_result);
        numerator_result /=nwd;
        denominator_result /=nwd;

        Fraction result = Fraction( numerator_result,denominator_result);
        return result;
    }


