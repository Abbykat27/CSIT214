#include <iostream>
#include <string>
using namespace std;
#include "fraction.h"

int main() {
    fraction input, input2;
    fraction* fractions = nullptr;
    string* names = nullptr; // For user-defined names of fractions
    int size = 0;
    int capacity = 2;

    fractions = new fraction[capacity];
    names = new string[capacity];

    cout << "Enter fractions as two integers (numerator and denominator)." << endl;
    cout << "Enter -1 as the numerator to stop entering fractions." << endl;

    while (true) {
        int num, denom;
        cout << "\nEnter numerator: ";
        cin >> num;
        if (num == -1)
            break;

        cout << "Enter denominator: ";
        cin >> denom;

        fraction f(num, denom);

        // Expand arrays if needed
        if (size == capacity) {
            capacity *= 2;
            fraction* newFractions = new fraction[capacity];
            string* newNames = new string[capacity];
            for (int i = 0; i < size; i++) {
                newFractions[i] = fractions[i];
                newNames[i] = names[i];
            }
            delete[] fractions;
            delete[] names;
            fractions = newFractions;
            names = newNames;
        }

        cin.ignore(); // Clear newline from buffer
        cout << "Name the fraction" << endl;
        getline(cin, names[size]);

        fractions[size] = f;
        size++;
    }



    int fracIndex1, fracIndex2;
    cout << "Pick the index of the two fractions that you would like to work with" << endl;
    cin >> fracIndex1 >> fracIndex2;

    if(fracIndex1 < 0 || fracIndex1 >= size || fracIndex2 < 0 || fracIndex2 >= size) {
        cout << "Invalid index" << endl;
        delete[] fractions;
        delete[] names;
        return 0;
    }

    fraction frac1 = fractions[fracIndex1];
    fraction frac2 = fractions[fracIndex2];
    string name1 = names[fracIndex1];
    string name2 = names[fracIndex2];


    cout << "First fraction: " << frac1 << endl;
    cout << "Second fraction: " << frac2 << endl;
    cout << "Sum: " << (frac1 + frac2) << endl;
    cout << "Difference:  " << (frac1 - frac2) << endl;
    cout << "Quotient: " << (frac1 / frac2) << endl;
    cout << "The result of the equality operator is: " << (frac1 == frac2) << endl;
    cout << "The result of the greater than operator is: " << (frac1 > frac2) << endl;
    cout << "The result of the greater than or equal to operator is: " << (frac1 >= frac2) << endl;
    cout << "The result of the less than operator is: " << (frac1 < frac2) << endl;
    cout << "The result of the less than or equal to operator is " << (frac1 <= frac2) << endl;

    delete[] fractions;
    delete[] names;
    return 0;
}