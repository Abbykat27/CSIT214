#include <iostream>
using namespace std; 
// header file that defines the interface for the Fraction class 
// this means that it tells what the Fraction class can do, but now how it does it. That part goes in the fraction.cpp file.
// do things like:
// declare classes and functions
// tell the compiler what functions exist, what parameters they take, and what they return

// must declare class fraction like I did in the last project. 
class fraction {
public:
	// two-parameter constructor: initializes the fraction with specified numerator and denominator, ensuring the denominator is not zero.
	// put the fraction constructor under the category of public because that is what the instructions did during the last assginment.
	fraction(int numerator, int denominator);

	// single-parameter constructor: treats the number as a whole number with the denominator set to 1. 
	// only uses a variable for numerator since the denominator is always set to 1, so only need a parameter to change the value of the numerator.
	fraction(int numerator);

	// default constructor: initalizes the fraction to represent zero (0/1)
	// since this is a default constructor I know that it will have no parameters passed through
	fraction();

	// operator overloads 
	friend ostream& operator<<(ostream& out, const fraction& fraction);
	friend istream& operator>>(istream& in, fraction& fraction);

	// general declaration for the overload of the + (plus) operator to tailor it for the fraction class.
	friend fraction operator +(const fraction& fraction1, const fraction& fraction2);

	// general declaration for the overload of the - (minus) operator to tailor it for the fraction class.
	friend fraction operator -(const fraction& fraction1, const fraction& fraction2);

	// general declaration for the overload of the / (division) operator to tailor it for the fraction class.
	friend fraction operator /(const fraction& fraction1, const fraction& fraction2);

	// general declaration for the overload of the == (equality) operator to tailor it for the fraction class.
	friend 	bool operator  ==(const fraction& fraction1, const fraction& fraction2);

	// general declaration for the overload of the < (less than) operator to tailor it for the fraction class.
	friend bool operator <(const fraction& fraction1, const fraction& fraction2);

	// general declaration for the overload of the <= (less than or equal to) operator to tailor it for the fraction class.
	friend bool operator <=(const fraction& fraction1, const fraction& fraction2);

	// general declaration for the overload of the > (greater than) operator to tailor it for the fraction class.
	friend bool operator >(const fraction& fraction1, const fraction& fraction2);

	// general declaration for the overload of the >= (greater than or equal to) operator to tailor it for the fraction class.
	friend bool operator >=(const fraction& fraction1, const fraction& fraction2); 






private:
	// I chose to make the member variables numerator and denominator private because it is recommended that they are set to this since it allows for encapsulation.
	int numerator;
	int denominator;
	void normalize();
	int gcd(int a, int b);
}; 