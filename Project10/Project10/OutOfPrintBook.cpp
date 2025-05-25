#include "OutOfPrintBook.h"
#include <iostream>
using namespace  std;

// constructor
OutOfPrintBook::OutOfPrintBook(string authorsN, string bookT, date datelastPrinted) :Book(authorsN, bookT) {
	lastPrinted = datelastPrinted;
}



// default constructor 
OutOfPrintBook::OutOfPrintBook() : Book("", "") {
	lastPrinted = { 0, 0, 0 };
}

// getter method for the date last printed 
date OutOfPrintBook::getLastPrintedDate() {
	return lastPrinted;
}

// override of the print method for OutOfPrint
void OutOfPrintBook::printingBookInfo() {
	cout << getBookInfo() << endl; 
	cout << "The last time that the book was printed is: " << getLastPrintedDate() << endl; 
}

// overload operator<< for printing a date
ostream& operator<<(ostream& os, const date& d) {
	os << d.day << "/" << d.month << "/" << d.year;
	return os;
}