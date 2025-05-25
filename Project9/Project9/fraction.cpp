// contains the implementation of the Fraction class 
// how the class does what it does.
// included this because of the outline of the last program
#include "fraction.h"


// normalize methods that adjusts fractions so the denominator is always positive, and the fraction is reduced to its simplest form
int fraction::gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void fraction::normalize() {
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
	int g = gcd(abs(numerator), abs(denominator));
	numerator = numerator / g;
		denominator = denominator / g;

}

// definition of the two parameter constructor
fraction::fraction(int num, int denom) {
	if (denom == 0) {
		cout << "The denominator cannot be zero, changing it to 1." << endl;
		denom = 1;
	}
	numerator = num;
	denominator = denom;
	normalize();
}

// definiton of the single-parameter constructor
fraction::fraction(int num) {
	numerator = num;
	denominator = 1;
}


// definition for the default constructor
// always initializes the fraction to represent zero (0/1)
fraction::fraction() {
	numerator = 0;
	denominator = 1;
}

// output operator overloading to handle fraction formats such as 1/2, 15/32, or -300/-401
// found this syntax in the textbook (pg. 657)
// note since this method is not part of the fraction class, it cannot access the variables numerator & denominator, therefore, I must make the function 
// a "friend" of the class so that it can access them. 
ostream& operator<<(ostream& out , const fraction& fraction) {

	out << fraction.numerator << "/" << fraction.denominator;
	return out;

}

// input operator overloading to handle fraction formats such as 1/2, 15/32, or -300/-401
// found this syntax in the textbook (pg. 657)
// note since this method is not part of the fraction class, it cannot access the variables numerator & denomiantor, thereore, I must make the function 
// a "friend" of the classs so that it can access them.
istream& operator>>(istream& in, fraction& fraction) {
	in >> fraction.numerator >> fraction.denominator;
	if (fraction.denominator == 0) {
		cout << "You cannot have zero as the denominator" << endl;
		fraction.normalize();
		in >> fraction.denominator;
	}
	return in;
}

// Arithmetic and comparison operators: ==, <, <=, >, >=, +, -, and /.
// overloading for arithmetic operator + (plus)
fraction operator +(const fraction& fraction1, const fraction& fraction2) {
	int numer = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
	int denom = fraction1.denominator * fraction2.denominator;
	return fraction(numer, denom);
}

// overloading for the arithmetic operator - (minus)
fraction operator -(const fraction& fraction1, const fraction& fraction2) {
	int numer = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
	int denom = fraction1.denominator * fraction2.denominator;
	return fraction(numer, denom);
}

// overloading function for the arithmetic operator / (division)
fraction operator /(const fraction& fraction1, const fraction& fraction2) {
	int numer = fraction1.numerator * fraction2.denominator;
	int denom = fraction1.denominator * fraction2.numerator;
	return fraction(numer, denom);
}

// overloading function for the comparion operator == (equality)
bool operator  ==(const fraction& fraction1, const fraction& fraction2) {
	return (fraction1.numerator * fraction2.denominator == fraction2.numerator * fraction1.denominator);
}

// overloading function for the comparison operator < (less than)
bool operator <(const fraction& fraction1, const fraction& fraction2) {
	return(fraction1.numerator * fraction2.denominator < fraction2.numerator * fraction1.denominator); 
}

// overloading fuction for the comparison operator <= (less than or equal to)
bool operator <=(const fraction& fraction1, const fraction& fraction2) {
	return (fraction1 < fraction2 || fraction1 == fraction2);
}

// overloading function for the comparison operator > (greater than)
bool operator >(const fraction& fraction1, const fraction& fraction2) {
	return !(fraction1 <= fraction2);
}

// overloading function for the comparison operator >= (greater than or equal to)
bool operator >=(const fraction& fraction1, const fraction& fraction2) {
	return !(fraction1 < fraction2);
}

