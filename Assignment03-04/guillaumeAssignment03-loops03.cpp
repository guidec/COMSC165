/***************************************************************
Problem#: Assignment 3 - #3

Write a program that prompts the user to enter a string and displays the number of the uppercase letters in the string.
Here is a sample run:
Enter a string: Programming Is Fun
The number of uppercase letters is 3
Restriction: only one loop and No conditions allowed (if / switch / ?: )

Name: Guillaume de Cannart
ID: 1685028
Date: 02/17/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

int main()
{
	string input;
	int count = 0;
	char letter;

	cout << "Enter a string: ";
	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		letter = input[i];
		count = count + (isupper(letter));
	}

	cout << endl << "The number of uppercase letters is " << count << endl;

	return 0;
}

