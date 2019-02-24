/***************************************************************
Problem#: Assignment 4 - #3 Swap Case

Write the following function that returns a new string in which the 
uppercase letters are changed to
lowercase and lowercase to uppercase.
string swapCase(const string& s)
Write a test program that prompts the user to enter a string and 
invokes this function, and displays the
return value from this function.

Name: Guillaume de Cannart
ID: 1685028
Date: 02/17/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>

using namespace std;

string swapCase(const string& s) {

	string nS;
	
	for (int i = 0; i < s.length(); i++) {
		islower(s[i]) ? nS += toupper(s[i]) : nS += tolower(s[i]);
	}
	return nS;
}

int main()
{
	string input, newString;

	cout << "Enter a string: ";
	getline(cin, input);

	newString = swapCase(input);
	cout << "The new string is: " << newString << endl;

	return 0;
}


