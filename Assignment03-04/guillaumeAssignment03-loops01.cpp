/***************************************************************
Problem#: Assignment 3 - #1 Display Pyramid
Question: Write a program that prompts the user to enter an integer 
from 1 to 9 and displays a pyramid, as shown in the following
sample run:
Pyramid Builders International.
Enter the number of lines: 7

	        1
	      2 1 2
	    3 2 1 2 3
	  4 3 2 1 2 3 4
	5 4 3 2 1 2 3 4 5
  6 5 4 3 2 1 2 3 4 5 6
7 6 5 4 3 2 1 2 3 4 5 6 7

Restrictions: You can use a maximum of:
- Two loops (-- for each extra loop)
- One condition (-- for each additional, ++ for none)

Name: Guillaume de Cannart
ID: 1685028
Date: 02/17/2019
Status:	(complete)
Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;


int main()
{
	string(input);
	int lines, maxLines;

	cout << "Pyramid Builders International." << endl;
	cout << "Enter the number of lines: ";
	getline(cin, input);
	istringstream(input) >> lines;
	lines--;
	maxLines = lines;
	cout << endl;
	
	for(lines; lines >= 0;  lines--){
		cout << string(lines*2, ' ');

		int maxNum = maxLines - (lines - 1);

		for (int count = maxNum; count > 0; count--) {
			cout << count << " ";
		}
		for (int count = 2; count <= maxNum; count++) {
			cout << count << " ";
		}
		cout << endl;
	}

	return 0;
}

