#include <iostream>
using namespace std; 
#include "Geometry.h"

int main() {
	// set up values for testing and change as needed
	int len = 15, wid = 14, side = 5; 

	// creating a shape to test with.
	Geometry unicornShape;

	// add code to test setLenth, setWidth, setSide 
	unicornShape.setLength(len); 
	unicornShape.setWidth(wid);
	unicornShape.setSide(side);

	// add code to instantiate the constructor for the rectangle 
	Geometry rec = Geometry(len, wid);

	// Test getLength and getWidth
	cout << "The rectangles length is " << rec.getLength() << endl;
	cout << "The recntangles width is " << rec.getWidth() << endl;

	// Test getArea
	
	cout << "The area of the rectangle is " << rec.getArea() << endl;
	// Test getPerimeter 
	cout << "The perimeter of the rectangle is " << rec.getPerimteter() << endl;

	// add code to instantiate the constructor for the cube

	Geometry cube = Geometry(side);

	// Test get Side
	cout << "The length of a side of the cube is: " << cube.getSide() << endl;

	// Test getSurfaaceArea
	cout << "The surface area of the cube is: " << cube.getSurfaceArea() << endl;

	// Test default constructor
	Geometry def = Geometry();
	cout << "Default length: " << def.getLength() << endl;
	cout << "Default Width:  " << def.getWidth() << endl;
	cout << "Default side: " << def.getSide() << endl;

	system("pause");
	return 0;
}