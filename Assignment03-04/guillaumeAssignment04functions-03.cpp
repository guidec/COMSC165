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
	nS = s;
	
	for (int i = 0; i < s.size(); i++) {
		islower(s[i]) ? nS[i] = toupper(nS[i]) : nS[i] = tolower(nS[i]);
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


