
#include <iostream>
using namespace std;
#include <cmath>


void displayTitle();
/* this is a void method that does not accept any input, but displays the title for the program by printing it out.
It is three lines long. */

double getData(double& lengthMeters, double& widthMeters);
/* this is a double value returning method that accepts input from the user about the width & the length of the room in meters and then supplies
the main method with these values. This is a call-by-reference method */

void convert12Format(int& hour, int& muinute);
/*this is a void method that accepts input (a hour in 24-hour notation and converts it to 12-hour notation. It then prints
the hour with A for AM or P for PM*/

int calcSqMeter(double lengthMeters, double widthMeters);
/* this is a function that takes in the values for length and width, and calculates the square meter and then returns an integer value
for the area to the main functioin*/

int calcTotalCans(double totalSquareMeters);
/* this is a function that takes in the value totalSquareMeters and uses that value to calculate the number of cans needed and then returns
the number of cans that are needed to cover the entire area*/

double calcCost(int totalCans);
/* this function takes in the total number of cans used, multiplies that number by 15.50 and then returns to the computer the cost of the
number of cans that were used*/

void displayResults(int totalSquareMeters, int totalCans, double costOfCans);
/* this is a method that takes in the totalSqureMeters, totalCans, and the costOfCans and then displays these values*/

bool isLeapYear(int year);
/*this is a method that takes in the integer value year and then takes modulus 4 & modulus 100 of the year to then return true if the year is
a leap year and false if the year is not a leap year*/

int getYearValue(int year);
/* this is a function that takes in the integer value year and computres the years since the beginning of the century.*/

int getMonthNumber(string monthName);
// this is a function that accepts a string value for the month and then returns an integer value from 1 - 12 that represents the month number.

int getMonthValue(int month, int year);
/* this function accepts an integer value for the name of the month and an integer value for the year that the month occurs in.It then returns a
value based on the table on page 302 of our textbook*/

int dayOfWeek(string day);
/* this function accepts a string value for the day of the week and then returns the day of the week specified as an int (i.e. Sunday = 0, Monday = 1
etc..*/

void displayMsg(int totalCans);
/*this is a void type function that accepts an integer value for the totalCans and displays a message showing whether / what type of free gift the
customer gets based on the number of cans purchased.*/

void displayMonthValue(int month);
/* function that accepts the integer value for the month and then prints out the month that corresponds to that number in words.*/

int getYearCode(int year); 
// this is a function that takes in the value of the year and returns the year code which is used to determine the day of the week it is.

int getLeapYearCode(int year, int month);
/* this is a function that accepts two integer values - one for the year and another for the month and then returns a code that is the leap year code.This code
will be used for determining what day of the week corresponds to a given date.*/

int getCenturyCode(int year);
// this is a function that accepts an integer value for the year and then returns the century code for that year as an integer value.

void dayOfWeek2(int year, int day2, int month);

int main() {
	
	double lengthMeters = 1.1;
	double widthMeters = 1.1;
	int hour = 0;
	int year = 0;
	int minute = 0;
	string day;
	int day2;
	string monthName;
	int month;

	displayTitle();
	while (getData(lengthMeters, widthMeters) != 0) {
		//getData(lengthMeters, widthMeters);
		double totalSquareMeters = calcSqMeter(lengthMeters, widthMeters);
		int totalCans = calcTotalCans(totalSquareMeters);
		double costOfCans = calcCost(totalCans);
		isLeapYear(year);
		int yearsSinceBeginningCentury = getYearValue(year);
		int monthNumber = getMonthNumber(monthName);
		int dayOfWeekValue = dayOfWeek(day);
		cout << "                                     Enter the transaction time in 24-hour notation: " << endl;
		cout << "                                     Hour: " << endl;
		cin >> hour;
		cout << "                                     Minute:" << endl;
		cin >> minute;
		cout << "                                     Enter the transaction date (dd mm yyyy): " << endl;
		cin >> day2;
		cin >> month;
		cin >> year;

		displayResults(totalSquareMeters, totalCans, costOfCans);
		cout << "                      Date/Time: ";
		dayOfWeek2(year, day2, month);
		cout << ", " << " ";
		displayMonthValue(month);
		cout << " ";
		cout << day2 << "," << " ";
		cout << year << "        ";
		convert12Format(hour, minute);
		cout << endl;
		displayMsg(totalCans);
		cout << " " << endl;
		cout << " " << endl;
		cout << "                      Thank you for your purchase" << endl;
	}
}

void displayTitle() {
	cout << "                                         Rainbow Painting Company" << endl;
	cout << "                                              Paint Costing" << endl;
	cout << "                                         ----------------------------" << endl;
}

double getData(double& lengthMeters, double& widthMeters) {

	cout << "                                     Enter the length of the room in meters (0 to stop)..." << endl;
	cin >> lengthMeters;
	while (lengthMeters != 0) {
		cout << "                                     Enter the width of the room in meters................" << endl;
		cin >> widthMeters;

		return widthMeters;
	}
	return lengthMeters;
}

void convert12Format(int& hour, int& minute) {
	if (hour <= 11) {
		cout << hour << ":" << minute << "AM";
	}
	if (hour == 12) {
		cout << hour << ":" << minute << "PM";
	}
	if (hour > 12) {
		cout<< hour - 12 << ":" << minute <<"PM";
	}
}

int calcSqMeter(double lengthMeters, double widthMeters) {
	int height = 3;
	return (2 * height * lengthMeters) + (2 * height * widthMeters) + (lengthMeters * widthMeters);
}

int calcTotalCans(double totalSquareMeters) {
	int coverage_per_can = 20;
	// one gallon paint can covers 20 square meter. 
	return ceil(static_cast<double>(totalSquareMeters) / coverage_per_can);
}

double calcCost(int totalCans) {

	// the price of one can of paint is $15.50
	const double priceCan = 15.50;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	return totalCans * priceCan;
}

void displayResults(int totalSquareMeters, int totalCans, double costOfCans) {
	cout << "                      Area                  =                     " << totalSquareMeters << " Square meters" << endl;
	cout << "                      Cans                  =                     " << totalCans << endl;
	cout << "                      Cost                  =                     " << costOfCans << endl;
}

bool isLeapYear(int year) {
	// the year must be evently divisbile by 4 to be a leap year.
	// the year cannot be evently divisible by 100 to be a leap year.
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else {
		return false;
	}
}

int getYearValue(int year) {
	return (year % 100) + ((year % 100) / 4);
}

int getMonthNumber(string monthName) {
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	for (int i = 0; i < 12; i++) {
		if (monthName == months[i]) {
			return i + 1;
		}
	}
	return 0;
}

int getMonthValue(int month, int year) {
	if (month == 1 && isLeapYear(year) == false) {
		return 0;
	}
	else if (month == 1 && isLeapYear(year) == true) {
		return 6;
	}
	else if (month == 2 && isLeapYear(year) == false) {
		return 3;
	}
	else if (month== 2 && isLeapYear(year) == true) {
		return 2;
	}
	else if (month == 3) {
		return 3;
	}
	else if (month == 4) {
		return 6;
	}
	else if (month == 5) {
		return 1;
	}
	else if (month == 6) {
		return 4;
	}
	else if (month == 7) {
		return 6;
	}
	else if (month == 8) {
		return 2;
	}
	else if (month == 9) {
		return 5;
	}
	else if (month== 10) {
		return 0;
	}
	else if (month == 11) {
		return 3;
	}
	else if (month == 12) {
		return 5;
	}
	return 0;
}
void displayMonthValue(int month) {
	if (month == 1) {
		cout << "January";
	}
	else if (month == 2) {
		cout << "February";
	}
	else if (month == 3) {
		cout << "March";
	}
	else if (month == 4) {
		cout << "April";
	}
	else if (month == 5) {
		cout << "May";
	}
	else if (month == 6) {
		cout << "June";
	}
	else if (month == 7) {
		cout << "July";
	}
	else if (month == 8) {
		cout << "August";
	}
	else if (month == 9) {
		cout << "September";
	}
	else if (month == 10) {
		cout << "October";
	}
	else if (month == 11) {
		cout << "November";
	} 
	else if (month == 12) {
		cout << "December";
	}
	else {
		cout << "This is not a valid number. Please enter a number between 1 & 12, inclusive.";

	}
}

int dayOfWeek(string day) {
	if (day == "Sunday") {
		return 0;
	}
	else if (day == "Monday") {
		return 1;
	}
	else if (day == "Tuesday") {
		return 2;
	}
	else if (day == "Wednesday") {
		return 3;
	}
	else if (day == "Thursday") {
		return 4;
	}
	else if (day == "Friday") {
		return 5;
	}
	else if (day == "Saturday") {
		return 6;
	}
	return 0;
}
void displayMsg(int totalCans) {
	if (totalCans >= 1 && totalCans <= 3) {
		cout << "Gift: free paint brush";
	}
	else if (totalCans >= 4 && totalCans <= 7) {
		cout << "Gift: free paint tray";
	}
	else if (totalCans > 7) {
		cout << "Gift: $10 gift card";
	}
}
int getYearCode(int year) {
	int lastTwoDigits = year % 100;
	return (lastTwoDigits + (lastTwoDigits / 4)) % 7;
}
int getLeapYearCode(int year, int month) {
	if (isLeapYear(year) && (month == 1 || month == 2)) {
		return 1;
	}
	return 0;
}
int getCenturyCode(int year) {
	if (year / 100 == 17) {
		return 4;
	}
	else if (year / 100 == 18) {
		return 2;
	}
	else if (year / 100 == 19) {
		return 0;
	}
	else if (year / 100 == 20) {
		return 6;
	}
	else if (year / 100 == 21) {
		return 4;
	}
	else if (year / 100 == 22) {
		return 2;
	}
	else if (year / 100 == 23) {
		return 0;
	}
	else {
		return 0;
	}
}

void dayOfWeek2(int year, int day2, int month) {
	//(Year Code + Month Code + Century Code + Date Number - Leap Year Code) mod 7
	/*0 = Sunday
		1 = Monday
		2 = Tuesday
		3 = Wednesday
		4 = Thursday
		5 = Friday
		6 = Saturday*/
		// calculating the year code
		// (YY + (YY div 4)) mod 7

	int code = ((getYearCode(year) + getMonthValue(month, year) + getCenturyCode(year) + day2 - getLeapYearCode(year, month)) % 7);
	if (code == 0) {
		cout << "Sunday";
	}
	else if (code == 1) {
		cout << "Monday";
	}
	else if (code == 2) {
		cout << "Tuesday";
	}
	else if (code == 3) {
		cout << "Wednesday";
	}
	else if (code == 4) {
		cout << "Thursday";
	}
	else if (code == 5) {
		cout << "Friday";
	}
	else if (code == 6) {
		cout << "Saturday";
	}
	else {
		cout << "not a valid output";
	}
}