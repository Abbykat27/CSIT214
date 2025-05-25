#include <iostream>
using namespace std;

int main() {
	
	double formerAnnualSalary = 0; 
	const double payIncreaseRate = 0.056;
	double increasedPayDue = 0;
	double newAnnualSalary = 0;
	double newMonthlySalary = 0;
	string continueOrNot = " ";
	// This code tells the user to enter the employee's former annual salary and then accepts the input and saves it in the variable formerAnnualSalary.
	cout << "\nEnter employee's former annual salary: $";
	cin >> formerAnnualSalary;
	// The code below acts as input validation to ensure that only valid salary values are accepted. 
	if (formerAnnualSalary < 0) {
		cout << "Please enter a valid former annual salary: $";
		cin >> formerAnnualSalary;
		while (formerAnnualSalary < 0) {
			cout << "Please entere a valid former annual salary: $";
			cin >> formerAnnualSalary;
		}
	}
		while (continueOrNot != "N") {
			// This code computes the increased pay due because of the pay increase.
			increasedPayDue = formerAnnualSalary * payIncreaseRate;
			// Code that prints out the increased pay that is due.
			cout << "Increated pay due: " << "$" << increasedPayDue;
			// This code computes the employee's new annual salary by adding together their former annual salary and their increased pay due.
			newAnnualSalary = formerAnnualSalary + increasedPayDue;
			cout << "\nNew annual salary: " << "$" << newAnnualSalary;
			// This code computes the new amount of money that the employee earns per month.
			newMonthlySalary = newAnnualSalary / 12;
			cout << "\nNew monthly salary: " << "$" << newMonthlySalary;
			cout << "\nDo you want to calculate salary for another employee? (Y/N): ";
			cin >> continueOrNot;
			if (continueOrNot == "Y") {
				cout << "\nEnter employee's former annual salary: $";
				cin >> formerAnnualSalary;
				// The code below acts as input validation to ensure that only valid salary values are accepted. 
				while (formerAnnualSalary < 0) {
					cout << "Please entere a valid former annual salary: $";
					cin >> formerAnnualSalary;
					
				}
				}
			else {
				cout << "Exiting program. Goodbye!";

			}
		}
		return 0;
	}


	
	
