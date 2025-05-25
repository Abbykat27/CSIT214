#include <iostream>
// library for vectors
#include <vector>
#include <string>
using namespace std;

// function that accepts a vecotr as input and adds an element to the vector.
void addTask(vector <string>& Tasks);
// function that searches for a task in the vector and then prints it out. Accepts a vector as the input.
void searchTask(const vector <string>& Tasks);
// function that accepts a vector as input and then removes the task typed from the vector.
void deleteTask(vector<string>& Tasks);
// accepts a vector as a paratmer and then prints out all elements in the vector.
void displayTask(vector<string>& Tasks);


int main() {
	int userChoice = 0;
	// local vector to store tasks
	vector<string> Tasks;
	// while loop that allows the user to enter a choice until they enter to sentil value -1, which stops the while loop.
	while (userChoice != -1) {
		cout << "Task Manager Menu:" << endl;
		cout << "1. Add Task" << endl;
		cout << "2. Search Task" << endl;
		cout << "3. Delete Task" << endl;
		cout << "4. Display All Tasks" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice from 1 -5, enter -1 to quit: ";
		cin >> userChoice;
		cin.ignore();

		// switch statement to either add a task, search for tasks, delete a task, display all tasks, or exit the program.
		switch (userChoice) {
			// add a task
		case 1:
			addTask(Tasks);
			break;
			// search for tasks 
		case 2:
			searchTask(Tasks);
			break;
			// delete a task
		case 3:
			deleteTask(Tasks);
			break;
			// display all tasks
		case 4:
			displayTask(Tasks);
			break;
			// exit the program 
		case 5:
			cout << "Ending the program" << endl;
			return 0;
			// if the user enters something other than 1 -5, a message for invalid input will be sent out.
		default:
			cout << "You did not enter a number from 1-5, please try again" << endl;
			break;
		}
	}

}
void addTask(vector<string>& Tasks) {
	// accepting input from the user about the task that they would like to add to the vector.
	string taskName = "";
	cout << "Enter the description of a task that you would like added to the vector" << endl;
	// reads the entire line
	getline(cin, taskName); 

	 
	// using the member function push_back to add the element TaskName to the vector. It adds elements to the next available position. 
	Tasks.push_back(taskName);
}

void searchTask(const vector <string>& Tasks) {

	string taskName;
	cout << "Enter a task description to search for & print" << endl;
	// reads the entire line
	getline(cin, taskName); 
	/*passes through the vector Tasks and then checks to see if the element in the vector Tasks is equal to the taskName entered by the user.
    If the vector element is equal to the taskName entered by the user, it is printed out.*/
	for (int i = 0; i < Tasks.size(); i++) {
		if (Tasks[i] == taskName) {
			cout << Tasks[i] << endl;
		}
	}
}

void deleteTask(vector<string>& Tasks) {

	string taskName;
	cout << "Enter a task description to delete: ";
	getline(cin, taskName);

	int index = -1;

	// Search for the task
	for (int i = 0; i < Tasks.size(); i++) {
		if (Tasks[i] == taskName) {
			index = i;
			break; 
		}
	}

	if (index != -1) {
		for (int i = index; i < Tasks.size() - 1; i++) {
			// Shifting elements to the left
			Tasks[i] = Tasks[i + 1]; 
		}
		// setting the last element to be empty
		Tasks[Tasks.size() - 1] = "";
		cout << "Task successfully deleted." << endl;
	}
	else {
		cout << "Task not found." << endl;
	}
}
void displayTask(vector<string>& Tasks) {
	// iterates through all of the tasks in the vector and displays them one-by-one.
	for (int i = 0; i < Tasks.size(); i++) {
		cout << Tasks[i] << endl;
	}
}