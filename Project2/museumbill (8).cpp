#include <iostream>
using namespace std;

int main() {
	int numOfChildrenTickets = 0;
	int numOfAdultTickets = 0;
	double costOfAdultTickets = 0;
	double costOfChildrenTickets = 0;
	int totalPeople = 0;
	double cashPaid = 0.0;
	double totalBill = 0.0;
	double change = 0.0;
	int confirmationNumber = 100;

	cout << "                         Eighth Art Museum";
	cout << "\n";
	cout << "\nEnter the children tickets or -1 to stop. . .";
	cin >> numOfChildrenTickets;

	while (numOfChildrenTickets != -1) {
		cout << "\Enter adults tickets.........................";
		cin >> numOfAdultTickets;
		totalPeople = numOfAdultTickets + numOfChildrenTickets;
		if (numOfAdultTickets > 4)
			costOfAdultTickets = numOfAdultTickets * 25.50 - 3;
		else
			costOfAdultTickets = numOfAdultTickets * 25.50;

		costOfChildrenTickets = (numOfChildrenTickets * 15) - ((numOfChildrenTickets / 3) * 15);

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "                                     Eighth Art Museum";
		cout << "\n                                   ________________________________";
		cout << "\n ";
		cout << "\n ";
		cout << "                                  Tickets       Price        Total";
		cout << "\n                        Child" << "        " << numOfChildrenTickets << "          " << "15.00" << "        " << costOfChildrenTickets;
		cout << "\n                        Adult" << "        " << numOfAdultTickets << "           " << "25.50" << "        " << costOfAdultTickets;

		if ((numOfChildrenTickets >= 10) || (totalPeople > 25))
			cout << "\n                        Security Fee                                           15";
		else
			cout << "\n                        Security Fee";

		cout << "\n";
		cout << "\n";
		cout << "\n";

		if ((numOfChildrenTickets >= 10) || (totalPeople > 25))
			cout << "\n                             Total:    " << costOfAdultTickets + (numOfChildrenTickets * 15) - ((numOfChildrenTickets / 3) * 15) + 15;
		else
			cout << "\n                             Total:    " << costOfAdultTickets + (numOfChildrenTickets * 15) - ((numOfChildrenTickets / 3) * 15);


		if ((numOfChildrenTickets >= 10) || (totalPeople > 25))
			totalBill = costOfAdultTickets + (numOfChildrenTickets * 15) - ((numOfChildrenTickets / 3) * 15) + 15;
		else
			totalBill = costOfAdultTickets + (numOfChildrenTickets * 15) - ((numOfChildrenTickets / 3) * 15);

		cout << "\n";
		cout << "\n";
		cout << "Cash recieved.......";
		cin >> cashPaid;
		cout << "\n";
		while (cashPaid < totalBill) {
			cout << "Cash must be >= totalBill";
			cout << "\n";
			cout << "\nCash recieved.........";
			cin >> cashPaid;
		}
		change = cashPaid - totalBill;
		cout << "\nChange                              " << change;
		cout << "\n";
		cout << "\nConfirmation Number = " << confirmationNumber;
		confirmationNumber++;
		cout << "\nEnter the children tickets or -1 to stop. . .";

		cin >> numOfChildrenTickets;
	}
	return 0;
}