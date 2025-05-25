#include "Book.h" 
#include <iostream>
using namespace std;


// constructor to set the book title author.
Book::Book(string authorsN, string bookT) {
	authorsName = authorsN;
	bookTitle = bookT;
}

// constructor to set the title and set the author's name to "unknown"
Book::Book(string bookT) {
	authorsName = "unknown";
	bookTitle = bookT;
}

// method to get the author and title concatenated into a single C++ String
string Book::getBookInfo() {
	return authorsName + "   " + bookTitle;
}

// method for printing the book information
 void Book::printingBookInfo() {
	 cout << getBookInfo() << endl;

}