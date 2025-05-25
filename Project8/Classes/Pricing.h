// includes the code from Geometry.h
#include "Geometry.h"

// Pricing is derived from the Geometry class
class Pricing : Geometry {

	public: 
		// constructor 
		// invokes the Geometry function 
		Pricing(int l, int w) : Geometry(l, w) {}

		// getSodCost function
		// recieves the pricce 
		// useses the getArea function in the Geometry class

		double getSodCost(double priceSod) {
			return getArea() *priceSod;
		
		}


		// getFenceCost function 
		// Recieves the price
		// uses the getPerimeter function in the Geometry class
		// returns the perimeter times price 
		double getFenceCost(double priceFence) {
			return priceFence * getPerimteter();
		}
};