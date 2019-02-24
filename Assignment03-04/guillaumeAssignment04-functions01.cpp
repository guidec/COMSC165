/***************************************************************
Problem#: Assignment 3 - Functions #1 Palindrome Integer

a) Use the flip function to implement isPalindrome. A number is a 
palindrome if its reversal
is the same as itself. For example, flip(3456) displays 6543..
b) Write a test program that prompts the user to enter an integer and 
reports whether the integer
is a palindrome

Name: Guillaume de Cannart
ID: 1685028
Date: 02/19/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int flip(int number) {
	int flipNum = 0, moduloRem;
	while (number > 0) {
		moduloRem = number % 10;
		flipNum = (flipNum * 10) + moduloRem;
		number = number / 10;
	}
	return flipNum;
}

bool isPalindrome(int number) {
	return (number == flip(number));
}

int main()
{
	string input;
	int num;

	cout << "Enter a number: ";
	getline(cin, input);
	istringstream(input) >> num;

	switch (static_cast<int>(isPalindrome(num))) {
	case 1: 
		cout << "The number is a palindrome!" << endl;
		break;
	default:
		cout << "No palindome here..." << endl;
	}
	
	return 0;
}


