#include <iostream>
#include "Pricing.h"
using namespace std;

int main() {
    // inputs the length and width 
    int length;
    int width;
    double priceSod = 0.47;
    double priceFence = 22.50;

    cout << "                                                    Parkton Landscaping" << endl;

    // inputs the length and width 
    cout << "Enter the length in feet ";
    cin >> length;

    cout << "Enter the width in feet ";
    cin >> width;

    // creates an object using the Pricing constructor 
    Pricing space(length, width);

    // code to display to two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double sodCost = space.getSodCost(priceSod);
    // displays the sod cost using getSodCost function
    cout << "The price of the sod is: $" << sodCost << endl;

    // display the price of the fencing using the getFenceCost function
    double fenceCost = space.getFenceCost(priceFence);
    cout << "The price of the fencing is $" << fenceCost << endl;



    return 0;
}