#include <iostream>
using namespace std;

const int ROW = 8;
const int COLUMN = 5;
int totalSales = 0;

void displayTheater(char layout[][COLUMN]);
// this is a void type function that accepts as a parameter the multi-dimensional array layout and prints out the theatre's array by iterating through 
// the array & printing out each element. This function is call-by-value.
void userChoice(char layout[][COLUMN], int& totalSales, int& numberOfSeatsSold);
// This is a call-by-reference function that takes in the array layout, totalSales, and numberOfSeatsSold as parameters and then records the sales made
// after the user chooses their memebership type as well as makes a call to the method processSale to update the theater board.

void processSale(char layout[][COLUMN], int row, char seat, int& numberOfSeatsSold);
// this is a call-by-reference function that takes in the array layout, row, seat, membership, and numberOfSeatsSold to record the 
// seat that the user has chosen & print it out.
void salesReport(int numberOfSeatsSold, int totalSales);
// this is a call-by-value function that takes in the two parameters - numberOfSeatsSold & totalSales to give information about the number of 
// seats sold, the percentage of seats sold, and the total cost of all the memberships sold.
int main() {
    int numberOfSeatsSold = 0;
    // here I am creating a 8 x 5 theatre using an array.
    char layout[ROW][COLUMN] = { {'A','B','C','D','E'},
                                 {'A','B','C','D','E'},
                                 {'A','B','C','D','E'},
                                 {'A','B','C','D','E'},
                                 {'A','B','C','D','E'},
                                 {'A','B','C','D','E'},
                                 {'A','B','C','D','E'},
                                 {'A','B','C','D','E'} };

    displayTheater(layout);
    userChoice(layout, totalSales, numberOfSeatsSold);
}

void displayTheater(char layout[][COLUMN]) {
    // this method iterates through the array and prints out each individual element of the array.
    cout << "###########" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            cout << layout[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "###########" << endl;
}

void userChoice(char layout[][COLUMN], int& totalSales, int& numberOfSeatsSold) {
    int row, membership;
    char seat;
    
    // asks the user which row they would like to reserve and stores their entry in the variable row.
    cout << "Enter the row number from 1 to 8 or -1 to end the program";
    cin >> row;

    // as long as their choice for the row is not -1, ask them which seat they want (A-E).
    while (row != -1) {
        cout << "Enter the seat letter (A-E): ";
        cin >> seat;
        // this function is used to change lowercase letter to uppercase so the computer can accept either lowercase or uppercase words.
        seat = toupper(seat);

        // asks the user the type of membership that they want.
        cout << "Enter the type of membership:\n";
        cout << "1: Gold (free popcorn and coke)\n";
        cout << "2: Silver (free coke)\n";
        cout << "3: No membership \n";
        cin >> membership;

        // adds to the total sales depending on the type of membership that the users chooses.
        if (membership == 1) {
            totalSales += 22;
        }
        else if (membership == 2) {
            totalSales += 20;
        }
        else if (membership == 3) {
            totalSales += 18;
        }
        else {
            cout << "Invalid membership choice.\n";
            continue;
        }
        // calls the processSale method to update the theatre layout and display the updated layout based on the users choices for seat reservation.
        processSale(layout, row, seat, numberOfSeatsSold);

        // asks the user to enter the row again and starts the entire process over again as long as -1 is not entered for the row.
        cout << "Enter the row number 1 through 8 or -1 to end the program";
        cin >> row;
    }

    salesReport(numberOfSeatsSold, totalSales);
}

void processSale(char layout[][COLUMN], int row, char seat, int& numberOfSeatsSold) {
    int rowChosen = row - 1;
    int colChosen = seat - 'A';

    // if there is already an X in the reservation spot, tell the user that they cannot reserve this spot.
    if (layout[rowChosen][colChosen] == 'X') {
        cout << "This seat is already taken, please choose another seat.\n";
    }
    else {
        // if there is not already an X there, go ahead and put one there. 
        // increment up the number of seats that have been reserved. 
        layout[rowChosen][colChosen] = 'X';
        numberOfSeatsSold++;
    }

    // call the display theater method again to print out the updated theater reservation. 
    displayTheater(layout);
}

void salesReport(int numberOfSeatsSold, int totalSales) {
    double percentageSeatsOccupied = (double)(numberOfSeatsSold) / (ROW * COLUMN) * 100;
    cout << "Seats sold: " << numberOfSeatsSold << endl;
    cout << "Percentage occupied: " << percentageSeatsOccupied << "%\n";
    cout << "Total sales: $" << totalSales << endl;
}