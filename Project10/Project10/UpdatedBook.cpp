#include "UpdatedBook.h"
#include <iostream>

// constructor to create the UpdatedBook object accept as input the author, title, and edition number of the book.
UpdatedBook::UpdatedBook(string authorsN, string bookT, int edition) : Book(authorsN, bookT) {
	editionNumber = edition; 
}

// getter method to return the edition number
int UpdatedBook:: getEditionNumber() {
	return editionNumber;
}


// override of the printintBookInfo method to include the edition number. 
void UpdatedBook::printingBookInfo()  {
	cout << getBookInfo() << "Edition: " << editionNumber << endl;
}