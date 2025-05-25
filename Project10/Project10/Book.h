// header file 
#include <iostream>
#include <string>
using namespace std;

class Book {
private: 
	string authorsName;
	string bookTitle;

public:
	// constructor to set the book title author.
	Book(string authorsN, string bookT);

	// constructor to set the book title to a parameter passed in and the author to "unknown"
	Book(string bookT);

	// method to get the author and title concatenated into a single C++ String
	string getBookInfo();

	// method for printing the book information
	virtual void printingBookInfo();
};