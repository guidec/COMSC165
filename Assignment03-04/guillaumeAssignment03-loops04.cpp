/***************************************************************
Problem#: Assignment 3 - #4 Checking Palindromes
A string is a palindrome if it reads the same forward and backward. 
The words “mom,” “dad,” and “noon,” for example,
are palindromes.
Example: 
Enter a string: abccba
abccba is a palindrome
Enter a string: abca
abca is not a palindrome

Restriction: maximum one loop allowed

Name: Guillaume de Cannart
ID: 1685028
Date: 02/17/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string input, original, reverseCheck;

	while(true) {

		cout << "Enter a string: ";
		getline(cin, input);
		original = input;

		reverse(input.begin(), input.end());
		
		switch (static_cast<int>(original.empty())) {
		case 1:
			cout << "You did not enter any string. ";
			break;
		default:
			switch (original.compare(input)) {
			case 0:
				cout << original << " is a palindrome" << endl;
				cout << endl;
				break;
			default:
				cout << original << " is not palindrome" << endl;
				cout << endl;
			}
		}
	}

	return 0;
}

