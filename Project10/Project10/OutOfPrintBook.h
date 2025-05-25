#include "Book.h"
#include <string>

// field to store the last printed date. data type should be a struct type including the day, month, and year 
struct date {
	int day; 
	int month;
	int year;
};


class OutOfPrintBook : Book {

private:
	date lastPrinted;

public:
	// constructor 
	OutOfPrintBook(string authorsN, string bookT, date lastPrinted);

	// default constructor
	OutOfPrintBook();

	// getter for the lastPrinted date
	date getLastPrintedDate();


	// override of the printingBookInfo() method 
	void printingBookInfo() override;

}; 
ostream& operator<<(ostream& os, const date& d);