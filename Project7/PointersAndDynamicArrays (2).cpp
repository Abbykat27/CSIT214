#include <iostream>
using namespace std;

void addInteger(int*& p, int& size, int& capacity, int newInt);
void searchInteger(int*& p, int& size);
void updateInteger(int* p, int size);
void deleteInteger(int*& p, int& size);
void displayAllIntegers(int* p, int size);

int main() {
	int userChoice = 0;
	int integer = 0;
	int newInt = 0;
	int size = 0;
	int capacity = 19;

	// creation of initial dynamic array with a capacity of 10 integers
	int* p = new int[capacity];


	// while loop that allows the user to enter a choice until they enter to sentil value -1, which stops the while loop.
	while (userChoice != -1) {
		cout << "Dynamic Integer Array Manager" << endl;
		cout << "1. Add Integer" << endl;
		cout << "2. Search Integer" << endl;
		cout << "3. Update Integer" << endl;
		cout << "4. Delete Integer" << endl;
		cout << "5. Display All Integers" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice from 1 -5, enter -1 to quit: ";
		cin >> userChoice;

		// switch statement to either add a task, search for tasks, delete a task, display all tasks, or exit the program.
		switch (userChoice) {
			// add a task
		case 1:
			addInteger(p, size, capacity, newInt);
			break;
			// search for tasks 
		case 2:
			searchInteger(p, size);
			break;
			// delete a task
		case 3:
			updateInteger(p, size);
			break;
			// display all tasks
		case 4:
			deleteInteger(p, size);
			break;
			// exit the program 
		case 5: 
			displayAllIntegers(p, size);
			break;
		case 6:
			cout << "Ending the program" << endl;
			return 0;
			// if the user enters something other than 1 -5, a message for invalid input will be sent out

		default:
			cout << "You did not enter a number from 1-5, please try again" << endl;
			break;
		}
	}

}
void addInteger(int*& p, int& size, int& capacity, int newInt) {
	// resize the array if it reaches capacity
	// resizes the array by doubling its size.
	int integer;
	cout << "Enter an integer: " << endl;
	cin >> integer;
	if (size == capacity) {
		// doubles the size of the array
		int newCapacity = capacity * 2;
		// assigns to the new array the doubled size.
		int* newArr = new int[newCapacity];

		// add the original array elements to the array
		for (int i = 0; i < size; i++) {
			newArr[i] = p[i];
		}

		// // deallocate the dynamically allocated memory that was in the dynamic array p
		delete[] p;
		// set p equal to the resized array
		p = newArr;
		capacity = newCapacity;
	}

	// add the integer that the user typed into the array
	p[size] = integer;
	size++;
}

void searchInteger(int*& p, int& size) {

	int integer;
	cout << "Enter the integer to search: " << endl;
	// reads the entire line
	cin >> integer;
	//passes through the dynamic array p and then checks to see if the integer in the dynamic array p is equal to the integer entered by the user.
	// If the dynamic array element is equal to the integer entered by the user, it is printed out.
	for (int i = 0; i < size; i++) {
		if (p[i] == integer) {
			cout << "You have located: " << p[i] << endl;
		}
	}
}


void updateInteger(int* p, int size) {
	int index, newInteger;
	cout << "Enter the integer that you would you to update the dynamic array with: " << endl;
	cin >> newInteger; 
	cout << "Enter the position that you would like to insert the integer at: " << endl; 
	cin >> index;

	// error handling that checks if the index entered is less than 0 or greater than the size of the dynamic array
	if (index < 0 || index >= size) {
		cout << "Invalid! Please enter a value between 0 and " << size - 1 << endl;
	}
	
	p[index] = newInteger;
	cout << "The value at index " << index << "has been updated to: " << p[index] << endl; 

}
void deleteInteger(int*& p, int& size) {

	int index;
	cout << "Enter the index that you want to delete an integer at:  " << endl;
	cin >> index;

	// input validation to make sure the index the user picks is within range
	if (index < 0 || index >= size) {
		cout << "Invalid. Please enter an index between 0 and " << size - 1 << endl;
	}

	// shift integers left to fill the gap
	for (int i = index; i < size - 1; i++) {
		p[i] = p[i + 1];

	}
	// decrease the size of the dynamic array by one.
	size--;

	cout << "The integer at index location " << index << "has been delated" << endl;
	
}

void displayAllIntegers(int* p, int size) {
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;

}