/*
* PolyHandler.cpp
* By Pedro Garate on 10/16/2014
* Description: Implementation of the ADT for a Polynomial Handler.
* 				This program manipulates polynomials in a single variable
*				x (e.g., p = 4x^5 + 7x^3 - x^2 + 9). Consider only polynomials
*				whose exponents are nonnegative integers.
*/

#include "PolyHandler.h"

#include <iostream>
#include <limits>

using namespace std;

//default constructor. deg = 0 and poly -> empty.
PolyHandler::PolyHandler() :deg{ 0 }
{
}//end of PolyHandler()

//2nd constructor. set a PolyHandler object from another PolyHandler object
PolyHandler::PolyHandler(const PolyHandler& oldPoly)
{
	deg = oldPoly.deg;
	poly.resize(deg + 1);// a total of deg+1 coefficients
	for (int i = deg; i >= 0; i--)
	{
		poly[i] = oldPoly.poly[i];
	}
}//end of 2nd constructor

//3rd constructor. set a PolyHandler object from an int(degree) and a vector(coefficients)
PolyHandler::PolyHandler(int degree, std::vector <int> vector)
{
	deg = degree;
	poly = vector;
}//end of 3rd constructor

// get an entire polynomial by interacting with user
void PolyHandler::setPoly()
{
	cout << "\nPlease enter the degree of your polynomial\n"
		"(has to be greater than 3 for the test program to work): ";
	//this depends on request from PolyHandlerTest.cpp line 36.
	deg = validPosInput(); // check if positive int and assign to deg
	poly.resize(deg + 1); // deg+1 coefficients
	for (int i = deg; i >= 0; i--) // start from higher power
	{
		cout << "Enter coefficient for term x^" << i << ": ";
		poly[i] = validInput();
	}

	while (poly[deg] == 0) //resize vector if highest degree coefficient is zero
	{
		deg -= 1;
		poly.resize(deg + 1);
	}
}//end of setPoly()

// returns the degree of a polynomial
int PolyHandler::degree()
{
	return deg;
}//end of degree()

// returns the coefficient of the x^power term
int PolyHandler::coefficient(int power) const
{
	return (poly[power]);
}//end of coefficient

// replaces coefficient of the x^power term with newCoefficient
void PolyHandler::changeCoefficient(int newCoefficient, int power)
{
	poly[power] = newCoefficient;
}//end of changeCoefficient

// multiply a polynomial by a scalar
PolyHandler PolyHandler::scalarMult(int scalar)
{
	PolyHandler temp; // new PolyHandler object to avoid modification of original
	temp.deg = deg;
	temp.poly.resize(deg + 1);
	for (int i = deg; i >= 0; i--)
	{
		temp.poly[i] = poly[i] * scalar; // multiplication term by term
	}
	return temp;
}//end of scalarMult

// adds two polynomials
PolyHandler PolyHandler::polyAdd(PolyHandler poly1)
{
	//temp PolyHandler objects to avoid modification of originals
	PolyHandler temp1(deg, poly);
	PolyHandler temp2(poly1);

	//if polynomials are different in size make sure that no
	//coefficients are left behind
	if (temp1.deg < temp2.deg) {
		temp1.poly.resize(temp2.deg + 1);
		temp1.deg = temp2.deg;
	}
	if (temp1.deg > temp2.deg) {
		temp2.poly.resize(temp1.deg + 1);
		temp2.deg = temp1.deg;
	}

	PolyHandler result;
	result.poly.resize(temp1.deg + 1);
	result.deg = temp1.deg;

	for (int i = result.deg; i >= 0; i--) {
		result.poly[i] = temp1.poly[i] + temp2.poly[i];// add term by term
	}

	return result;
}//end of polyAdd

// prints out a polynomial
void PolyHandler::printPoly()
{
	cout << endl << " ";
	// print out term by term starting in highest power
	// the first term only shows sign if is negative
	// the coefficient of x^1 will show only an "x" (e.g. 5x^1 => 5x)
	// the coefficient of x^0 will not show a variable (e.g. 5x^0 => 5)
	for (int i = deg; i >= 0; i--)
	{
		if (i == deg && i != 0 && i != 1)
			cout << poly[i] << "x^" << i;
		else if (i == deg && i == 1) {
			cout << poly[i] << "x";
		}
		else if (i == deg && i == 0) {
			cout << poly[i];
		}
		else if (i == 0 && i != deg) {
			if (poly[i] < 0)
				cout << poly[i];
			if (poly[i] > 0)
				cout << "+" << poly[i];
		}
		else if (i == 1 && i != deg) {
			if (poly[i] < 0)
				cout << poly[i] << "x";
			if (poly[i] > 0)
				cout << "+" << poly[i] << "x";
		}
		else {
			if (poly[i] < 0)
				cout << poly[i] << "x^" << i;
			if (poly[i] > 0)
				cout << "+" << poly[i] << "x^" << i;
		}
	}
	cout << endl;
}//end of printPoly

// divide a polynomial by a scalar. overload of operator "/"
PolyHandler operator/(PolyHandler poly, int scalar) {
	PolyHandler temp;// to avoid modification of original
	temp.deg = poly.deg;
	temp.poly.resize(poly.deg + 1);
	for (int i = poly.deg; i >= 0; i--)
	{
		temp.poly[i] = poly.poly[i] / scalar;// divide term by term
	}
	return temp;
}// end of operator/

// operator (-) overload. negate a polynomial
PolyHandler operator-(PolyHandler poly) {
	return poly.scalarMult(-1);//negate = multiply by -1
}//end of operator-

// output a polynomial, same as printPoly(). overload of << operator
std::ostream& operator<<(std::ostream& os, const PolyHandler& poly) {
	os << endl << " ";
	// print out term by term starting in highest power
	// the first term only shows sign if is negative
	// the coefficient of x^1 will show only an "x" (e.g. 5x^1 => 5x)
	// the coefficient of x^0 will not show a variable (e.g. 5x^0 => 5)
	for (int i = poly.deg; i >= 0; i--)
	{
		if (i == poly.deg && i != 0 && i != 1)
			os << poly.poly[i] << "x^" << i;
		else if (i == poly.deg && i == 1) {
			os << poly.poly[i] << "x";
		}
		else if (i == poly.deg && i == 0) {
			os << poly.poly[i];
		}
		else if (i == 0 && i != poly.deg) {
			if (poly.poly[i] < 0)
				os << poly.poly[i];
			if (poly.poly[i] > 0)
				os << "+" << poly.poly[i];
		}
		else if (i == 1 && i != poly.deg) {
			if (poly.poly[i] < 0)
				os << poly.poly[i] << "x";
			if (poly.poly[i] > 0)
				os << "+" << poly.poly[i] << "x";
		}
		else {
			if (poly.poly[i] < 0)
				os << poly.poly[i] << "x^" << i;
			if (poly.poly[i] > 0)
				os << "+" << poly.poly[i] << "x^" << i;
		}
	}
	os << endl;
	return os;
}//end of operator<<

//check if input is an int
int PolyHandler::validInput()
{
	int num;
	cin >> num;
	// detect if input isn't an int.
	while (std::cin.fail())
	{
		// clear input and ignore what was entered
		// no matter the size.
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Bad entry.  Enter an INTEGER: ";
		// get new input
		cin >> num;
	}
	return num;
}// end of validInput

//check if input is greater or equal than zero
int PolyHandler::validPosInput()
{
	int num;
	cin >> num;
	//detect if input isn't an int or less than 0.
	while (cin.fail() || num < 0)
	{
		// clear input and ignore what was entered
		// no matter the size.
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Bad entry.  Enter a POSITIVE INTEGER: ";
		// get new input
		cin >> num;
	}
	return num;
}//end of validPosInput
