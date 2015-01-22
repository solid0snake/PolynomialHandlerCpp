/*
 * PolyHandler.h
 * by Pedro Garate on 10/16/2014
 * Description: Definition of an ADT for a Polynomial Handler
 * 				This program manipulates polynomials in a single variable
 *				x (e.g., p = 4x^5 + 7x^3 - x^2 + 9). Consider only polynomials
 *				whose exponents are nonnegative integers.
 */

#ifndef POLYHANDLER_H_
#define POLYHANDLER_H_

#include <iostream>
#include <vector>

class PolyHandler {
	private:
		std::vector<int> poly; // vector of coefficients
		int deg; //degree of polynomial
	public:
		PolyHandler(); // default constructor
		PolyHandler(const PolyHandler& oldPoly); // get a polynomial from another polynomial
		PolyHandler(int degree, std::vector <int> vector); // set a polynomial from a degree and vector
		void setPoly(); // get an entire polynomial by interacting with user
		int degree(); // returns the degree of a polynomial
		int coefficient(int power) const; // returns the coefficient of the x^power term
		void changeCoefficient(int newCoefficient, int power); // replaces coefficient of the x^power term with newCoefficient
		PolyHandler scalarMult(int scalar); // multiply a polynomial by a scalar
		PolyHandler polyAdd(PolyHandler poly1); // adds two polynomials
		void printPoly(); // prints out a polynomial
		friend PolyHandler operator/(PolyHandler poly, int scalar);// divide a polynomial by a scalar
		friend PolyHandler operator-(PolyHandler poly);// negate a polynomial
		friend std::ostream& operator<<(std::ostream& os, const PolyHandler& poly);// output a polynomial
		int validInput(); // check if input is an int
		int validPosInput(); // check if input is a positive int
};// end of PolyHandler

#endif /* POLYHANDLER_H_ */
