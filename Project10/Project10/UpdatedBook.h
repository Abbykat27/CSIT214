// header file for UpdatedBook.cpp
#include "Book.h"
#include <string>

// derived class of the base book class
class UpdatedBook : public Book {


private: 
	// field for the edition number of the book
	int editionNumber; 


public: 
	// constructor to create the UpdatedBook object accept as input the author, title, and edition number of the book.
	UpdatedBook(string authorsN, string bookT, int edition);

	// getter method to return the edition number
	int getEditionNumber(); 

	// override of the printintBookInfo method to include the edition number. 
	void printingBookInfo() override; 
};