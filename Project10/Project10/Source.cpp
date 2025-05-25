#include "OutOfPrintBook.h"
#include <iostream>
using namespace std;

int main() {
	int numOfOutOfPrintBooks;

	cout << "Enter the number of out of print books" << endl;
	cin >> numOfOutOfPrintBooks;


	// create a dynamic array on the heap
	// OutofPrintBook data type since it is storing objects of the OutOfPrintBook data type.
	// use new to allocate memory on the heap.
	OutOfPrintBook* books = new OutOfPrintBook[numOfOutOfPrintBooks];

	for (int i = 0; i < numOfOutOfPrintBooks; i++) {
		string author;
		string title;
		int day;
		int month;
		int year;


		cout << "Enter information for book number: " << i + 1 << endl;
		cout << "Enter the name of the author: " << endl;
		cin >> author;

		cout << "Enter the title of the book: " << endl;
		cin >> title;

		cout << "Enter the last date that the book was printed (day month (entered as a number, for example January is 1, Febuaray is 2) year) Make sure to have a space between the month day and year. For example: 1 17 1994 " << endl;
		cin >> day >> month >> year;

		date lastPrintedDate = { day, month, year }; 
	
		
		books[i] = OutOfPrintBook(author, title, lastPrintedDate);
	}

	// print out the OutOfPrintBook objects using the member function of the OutOfPrintBook objects
	cout << "Information about the book: " << endl;
	for (int i = 0; i < numOfOutOfPrintBooks; i++) {
		cout << "For book number: " << i + 1 << endl;
		books[i].printingBookInfo(); 
	}


	// free the memory from the dynamic array 
	delete[] books; 
	return 0; 
} 