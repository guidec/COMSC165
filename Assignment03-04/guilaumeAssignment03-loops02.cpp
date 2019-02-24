/***************************************************************
Problem#: Assignment 3 - #2 

Write a program that generates a random number between 1...100 and asks the user to guess what the number is. If the
user's guess is higher than the random number, the program should display “Too high, try again”. If the user s guess is
lower than the random number, the program should display “Too low, try again”. The program should use a loop that
repeats until the user correctly guesses the random number.
The program will keep a count of the number of guesses that the user makes. When the user correctly guesses the
random number, the program should display the number of guesses.

Name: Guillaume de Cannart
ID: 1685028
Date: 02/17/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include <time.h> 

using namespace std;


int main()
{
	int randomNumber, guess, count = 1, state = 1;
	string input;

	cout << "I'm going to generate a number from 1 to 100! Can you "
		<< "guess what it is?" << endl;
	
	srand((unsigned int)time(NULL));
	randomNumber = rand() % 100 + 1;

	while(state == 1) {
		cout << "Pick a number: ";
		getline(cin, input);
		istringstream(input) >> guess;

		switch (static_cast<int>(randomNumber == guess)) {
		case 1:
			cout << endl << "You guessed it!";
			cout << "You made " << count 
			  << " guesses until you got it right. " << endl;
			state = 0;
			break;
		case 0:
			switch (static_cast<int>(guess > randomNumber)) {
			case 1:
				cout << "Too high, try again. " << endl;
				break;
			case 0:
				cout << "Too low, try again." << endl;
			}	
		}
		count++;
	}
	return 0;
}

