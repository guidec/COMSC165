/***************************************************************
Problem#: Assignment 2 - Making Decisions
Question:
1. Write a program that calculates a customer痴 monthly bill. It
should ask which package the customer has
purchased and how many hours were used. It should then display the
total amount due.

2. Input Validation:
a. Be sure the user only selects valid package. If you did #1 above,
then use class CPackage for
validating if the package exists
b. Also, the number of hours used in a month cannot exceed the hours
in that given month. Months
with 30 days have 720 hours, and months with 31 days have 744 hours.
February, with 28 days,
has 672 hours. By asking the user for the month (by name), and
validating that the number of
hours entered is not more than the maximum for the entire month.

3. The Program will also display how much money Package A customers
would save if they purchased
packages B or C, and how much money Package B customers would save
if they purchased Package C. If
there would be no savings, no message should be printed.

Name: Guillaume de Cannart
ID: 1685028
Date: 02/07/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include <iostream>	
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

const double BASE_PACKAGE_A = 9.95;
const int MAX_HOURS_A = 10;
const double BASE_PACKAGE_B = 14.95;
const int MAX_HOURS_B = 20;
const double BASE_PACKAGE_C = 19.95;
const int MAX_HOURS_30 = 720;
const int HOURS_IN_A_DAY = 24;
const int HOURS_IN_THREE_DAYS = 72;

int main()
{
	double price, priceB, priceC, savingsB, savingsC, doubleHours;
	string package, hours, month;
	char monthFirstLetter, charPackage;
	int maxHours, found;

	cout << "Enter your purchased package(A, B, or C): ";
	getline(cin, package);
	istringstream(package) >> charPackage;

	cout << "Enter the number of hours used: ";
	getline(cin, hours);
	istringstream(hours) >> doubleHours;

	cout <<"Enter the month: ";
	getline(cin, month);
	cout << endl;
	
	monthFirstLetter = month[0];
	monthFirstLetter = toupper(monthFirstLetter);
	
	found = month.find_first_of(("YGCygc"));
	maxHours = (MAX_HOURS_30 + HOURS_IN_A_DAY*
	(static_cast<int>(found != string::npos)))
	- HOURS_IN_THREE_DAYS*(static_cast<int>(monthFirstLetter == 'F'));

	//validate entered hours for maxHours and charachter input
	switch (static_cast<int>(doubleHours > maxHours) || !isdigit(hours[0])) {
	case 1:
		charPackage = 'I';
	}

	switch (charPackage) {
	case 'I':
		cout << "Invalid number of hours entered." << endl;
		break;
	case 'A':
		switch (static_cast<int>(doubleHours < MAX_HOURS_A)) {
		case 1:
			price = BASE_PACKAGE_A;
			break;
		case 0:
			price = BASE_PACKAGE_A + ((doubleHours - MAX_HOURS_A) * 2);
			priceB = BASE_PACKAGE_B + ((doubleHours - MAX_HOURS_B) * 1);
			priceC = BASE_PACKAGE_C;

			switch (static_cast<int>(priceB < price && priceC < price)) {
			case 1:
				savingsB = price - priceB;
				savingsC = price - priceC;

				cout << "Packages B and C are the cheaper option for you."
					 << " You could have saved $" << savingsB << " with "
					 << "package B, and $" << savingsC << " with "
					 << "package C." << endl;
				break;
			case 0:
				switch (static_cast<int>(priceB < price)) {
				case 1:
					savingsB = price - priceB;
					savingsC = price - priceC;

					cout << "Package B is the cheaper option for you."
						 << " You could have saved $" << savingsB << " with "
						 << "package B." << endl;
				}
			}
		}
		cout << "Your total price is: $" << price << endl;
		break;
	case 'B':
		switch (static_cast<int>(doubleHours < MAX_HOURS_B)) {
		case 1:
			price = BASE_PACKAGE_B;
			break;
		case 0: 
			price = BASE_PACKAGE_B + (doubleHours - MAX_HOURS_B);
			priceC = BASE_PACKAGE_C;
			switch (static_cast<int>(priceC < price)) {
			case 1: 
				savingsC = price - priceC;

				cout << "Package C is the cheaper option for you."
					 << " You could have saved $" << savingsC << " with "
					 << "package C." << endl;
			}
		}
		cout << "Your total price is: $" << price << endl;
		break;
	case 'C':
		price = BASE_PACKAGE_C;
		cout << "Your total price is: $" << price << endl;
		break;
	default:
		cout << "Invalid package entered." << endl;
	}
}

