#include <iostream>
using namespace std;

class Geometry {
	public:

		// constructor 1 (rectangle)
		// recieves two integer values for length and width
		// calls checkNum to validate each value.
		// Assigns values to length and width.
		Geometry(int l, int w) {
			length = l;
			width = w;

			checkNum(l);
			checkNum(w);
		}

		// constructor 2 (cube)
		// recives 1 integer value for side
		// calls checkNum to validate the value.
		// assigns value to side
		Geometry(int s) {
			side = s;

			checkNum(s);
		}

		// constructor 3 (default constructor)
		// set variables to zero.
		Geometry() {
			length = 0;
			width = 0;
			side = 0;
		}


		// method setLength that recives an integer, is a void type, calls checkNum and assigns length

		void setLength(int l) {
			checkNum(l);
			length = l;
		
		}

		// method setWidth that recieves an integer, is a void type, calls checkNum and assigns width
		void setWidth(int w) {
			checkNum(w);
			width = w;
		}

		// method setSide that recives an integer, is a void type, calls checkNum, and assigns side 
		void setSide(int s) {
			checkNum(s);
			side = s;
		}

		// method called getLength that recives nothing and returns the length as an integer value.
		int getLength() {
			return length;
		}

		// method called getWidth that recives nothing and returns the width as an integer value
		int getWidth() {
			return width;
		}

		// method called getSide that recives nothing and returns the side as an integer value
		int getSide() {
			return side;
		}

		// method called getArea that recives nothing and returns as an integer value of the area and calculates the area of a rectangle
		int getArea() {
			return length * width;
		}

		// method called getPerimeter that recives nothing and calculates the perimeter of a rectangle
		int getPerimteter() {
			return 2 * length + 2 * width;
		}

		// method called getSurfaceArea that recieves nothing and returns an integer value that is the surface area of a cube
		int getSurfaceArea() {
			return 6 * (side * side);
		}

	private:
		int length;
		int width;
		int side;

		// function that recieves an int and checks to see if the value is less than or equal to zero.
		// // if the value is less than zero, display an error message and exit the program with exit(1)	
		void checkNum(int value) {
			if (value < 0) {
				cout << "Error: the value cannot be less than zero" << endl;
				exit(1);
			}
	}



};

// function headers and code 