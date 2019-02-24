/***************************************************************
Problem#: Assignment 4 - #4 Phone keypads

The international standard letter/number mapping for telephones is shown in the picture.
The following function returns a number given an uppercase letter.
Fill in the blank to complete the function
int getNumber(char uppercaseLetter){
return ___________________________________
}
Restrictions:
- The function's body is 1 line,
- No conditional operators/functions including ternary operator
- Must correctly translate all the letters
Write a test program that prompts the user to enter a phone number as a string. The input number may
contain letters. The program translates a letter (uppercase or lowercase) to a digit and leaves all other
characters intact. Here is a sample run of the program:

Enter a string: 1-800-Flowers
1-800-3569377

Name: Guillaume de Cannart
ID: 1685028
Date: 02/23/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>

using namespace std;

/*To avoid errors with S and V. 1 is subtracted if remainder of division by 
3 is zero. To avoid errors with Y and Z, one is subtracted if result
of division if greater than 7. */
int getNumber(char uppercaseLetter) {

	return (((toupper(uppercaseLetter) - 65) / 3 + 2)) +
		(((((toupper(uppercaseLetter) - 65) / 3) == (6)) ||
		(((toupper(uppercaseLetter) - 65) / 3) == (7))) &&
			(((toupper(uppercaseLetter) - 65) % 3) == 0))*-1
		+ (((toupper(uppercaseLetter) - 65) / 3) > 7)*-1;
}

int printNumber(const string& input) {

	char letter;

	for (int i = 0; i < input.length(); i++) {
		letter = toupper(input[i]);
		switch (letter > 'A' && letter < 'Z') {
		case 1:
			cout << getNumber(letter);
			break;
		default:
			cout << letter;
		}
	}
	return 0;
}

int main() {
	
	string input;

	cout << "Enter a string: ";
	getline(cin, input);
	printNumber(input);

	return 0;
}


