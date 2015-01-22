/*
* PolyHandlerTest.cpp
* By Pedro Garate on 10/16/2014
* Description: Test the ADT for a Polynomial Handler.
* 				This program manipulates polynomials in a single variable
*				x (e.g., p = 4x^5 + 7x^3 - x^2 + 9). Consider only polynomials
*				whose exponents are nonnegative integers.
*/

#include "PolyHandler.h"
#include <iostream>

using namespace std;

int main() {
	cout << "POLYHANDLER:" << endl;
	cout << "This program manipulates polynomials in a single variable\n"
		"x (e.g., p = 4x^5 + 7x^3 - x^2 + 9). Consider only polynomials\n"
		"whose exponents are nonnegative integers." << endl;

	PolyHandler poly1;
	poly1.setPoly(); // set polynomial from user input
	cout << "\nThis is your polynomial:";
	poly1.printPoly(); // print polynomial

	//get degree of polynomial
	cout << "\nThe degree of this polynomial is: " << poly1.degree() << endl;

	//get coefficients from polynomial
	cout << "\nThe coefficient for the x^4 term is: " <<
		poly1.coefficient(4) << endl;
	cout << "The coefficient for the x term is: " <<
		poly1.coefficient(1) << endl;

	//change coefficients
	cout << "Let's switch these two coefficients..." << endl;
	int temp = poly1.coefficient(1);
	poly1.changeCoefficient(poly1.coefficient(4), 1);
	poly1.changeCoefficient(temp, 4);
	cout << "\nThis is the new polynomial:";
	poly1.printPoly();

	//test scalarMult(int)
	cout << "\nLet's multiply this polynomial by -5." << endl;
	cout << "This is the resulting polynomial:";
	poly1.scalarMult(-5).printPoly();

	//test the overloaded "/" operator
	//we are suppossed to get the original polynomial
	//before multiplying by -5
	cout << "\nLet's divide this new polynomial by -5." << endl;
	cout << "This is the resulting polynomial:";
	(poly1.scalarMult(-5) / -5).printPoly();

	//test the "-" operator; negate the polynomial
	cout << "\nLet's negate the polynomial:";
	poly1.printPoly();
	cout << "The resulting polynomial is:";
	(-poly1).printPoly();

	//test the put operator "<<"
	//we are suppossed to get the same polynomial twice
	cout << "\nTesting the overload \"put\" operator \"<<\":";
	poly1.printPoly();
	cout << poly1;

	//get a second polynomial from user
	//to test addition of two polynomials
	cout << "\nSecond polynomial:";
	PolyHandler poly2;
	poly2.setPoly();
	cout << "This is your polynomial:";
	poly2.printPoly();

	//test addition
	cout << "\nLet's add these two polynomials:";
	poly1.printPoly();
	poly2.printPoly();
	cout << "\nThe result is:";
	poly1.polyAdd(poly2).printPoly();

	return 0;
}// end of main()
