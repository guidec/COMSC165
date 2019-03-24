/***************************************************************
Problem#:  Lab 3: DATABASE

Create a database that allows to sort and search through a list of records. 

Name: Guillaume de Cannart
ID: 1685028
Date: 03/23/2019

Status:	(complete) 

Course: COMSC-165-2405
****************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;

struct DataNumber {
	long long int number;
	string name;
	int index;
};

long long int convertToInt(string num1) {

	string  part1, part2, part3;
	long long int num1int;

	stringstream convert(num1);
	getline(convert, part1, '-');
	getline(convert, part2, '-');
	getline(convert, part3, '-');

	num1 = part1 + part2 + part3;

	stringstream convertToLongInt(num1);

convertToLongInt >> num1int;
return num1int;
}

void setRecord(DataNumber &oneField, long long int num, int index) {

	oneField.number = num;
	oneField.index = index;
}

//you are a little piece of garbage. You don't work.
vector <DataNumber> insertionSort(vector <DataNumber> sortVector) {
	long long int firstVal;
	int compare;

	for (int i = 1; i < sortVector.size(); i++) {

		firstVal = sortVector.at(i).number;
		compare = i - 1;
		while (compare > -1 && sortVector.at(compare).number > firstVal) {

			sortVector.at(compare + 1) = sortVector.at(compare);
			compare--;
		}
		sortVector.at(compare + 1) = sortVector.at(i);
	}
	return sortVector;
}

void swap(DataNumber *num1, DataNumber *num2)
{
	DataNumber temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//you work! But you're super slow. 
vector <DataNumber> bubbleSort(vector <DataNumber> sortVector) {
	int length;
	length = sortVector.size();

	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++)
			if (sortVector.at(j).number > sortVector.at(j + 1).number)
				swap(&sortVector.at(j), &sortVector.at(j + 1));
	}
	return sortVector;
}

//this works but its also slow slow slow slow
void insertField(DataNumber field1, vector <DataNumber> &numberBase) {

	double midVal;
	int midValInt;
	
	midVal = numberBase.size() / 2;
	midValInt = static_cast<int>(ceil(midVal));

	int maxInt = numberBase.size();

	if (field1.number > numberBase.at(midValInt).number) {
		for (int i = midValInt; i < numberBase.size(); i++) {
			if (field1.number < numberBase.at(i).number) {
				numberBase.insert(numberBase.begin() + i, field1);
				i = numberBase.size();
			}
			if (field1.number > numberBase.at(maxInt - 1).number) {
				numberBase.insert(numberBase.begin() + (maxInt), field1);
				i = numberBase.size();
			}
		}
	}
	else {
		for (int i = 0; i < midValInt; i++) {
			if (field1.number < numberBase.at(i).number) {
				numberBase.insert(numberBase.begin() + i, field1);
				i = midValInt;
			}
			if (field1.number > numberBase.at(maxInt - 1).number) {
				numberBase.insert(numberBase.begin() + (maxInt), field1);
				i = midValInt;
			}
		}
	}
}

void sortNumberData(string choice, string outFileAppend) {
	fstream inFile;
	fstream outFile;
	
	string line, num1, num2;
	int index = 0;
	double progress;
	long long int num1int, num2int;
	vector <DataNumber> numberBase;
	vector <DataNumber> unsortedNumberBase;
	DataNumber field1, field2;

	inFile.open(choice + ".csv", ios::in);
	outFile.open("database" + outFileAppend + ".txt", ios::out);

	if (inFile) {
		(getline(inFile, line));  //clear first line of data. 
		while (getline(inFile, line)) {
			index++;
			stringstream ss(line);
			for (int i = 0; i <= 8; i++) {
				getline(ss, num1, ',');
			}
			getline(ss, num2, ',');

			//convert phone numebrs to long ints
			num1int = convertToInt(num1);
			num2int = convertToInt(num2);

			//plug the number into struct1
			setRecord(field1, num1int, index);
			//plug the number into struct2
			setRecord(field2, num2int, index);

			// if statement for first time 
			if (index == 1) {
				numberBase.push_back(field1);
				if (field2.number > numberBase.at(0).number) {
					numberBase.insert(numberBase.begin() + 1, field2);
				}
				else {
					numberBase.insert(numberBase.begin(), field2);
				}
			}
			else {
				insertField(field1, numberBase);
				insertField(field2, numberBase);
			}

			progress = (index / stod(outFileAppend)) * 100;
			cout << progress << "%" << "\r";
		}

		for (int i = 0; i < numberBase.size(); i++) {
			outFile << numberBase.at(i).index << " " << numberBase.at(i).number << endl;
		}

		inFile.close();
		outFile.close();
	}

}

int binarySearchIndex(vector<DataNumber> indexVector, long long int searchInt) {
	int l, r;
	int returnVal;
	bool flag = false;

	l = 0;
	r = indexVector.size() - 1;

	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid 
		if (indexVector.at(m).number == searchInt) {
			returnVal = m;
			flag = true;
		}
		// If x greater, ignore left half 
		if (indexVector.at(m).number < searchInt) {
			l = m + 1;
		}
		// If x is smaller, ignore right half 
		else {
			r = m - 1;
		}

	}

	//if not found
	if (flag == false) {
		returnVal = -1;
	}

	return returnVal;
}

void retrieveRecord(int recordIndex) {
	fstream inFile;
	string line;
	struct Record {
		string first_name;
		string last_name;
		string company_name;
		string address;
		string city;
		string county;
		string state;
		string zip;
		string phone1;
		string phone2;
		string email;
		string web;
	};

	Record person;

	inFile.open("us-50000C.csv", ios::in);

	for (int i = 0; i < recordIndex; i++) {
		getline(inFile, line);
	}


	getline(inFile, line);
	stringstream recordLine(line);

	getline(recordLine, person.first_name, ',');
	getline(recordLine, person.last_name, ',');
	getline(recordLine, person.company_name, ',');
	getline(recordLine, person.address, ',');
	getline(recordLine, person.city, ',');
	getline(recordLine, person.county, ',');
	getline(recordLine, person.state, ',');
	getline(recordLine, person.zip, ',');
	getline(recordLine, person.phone1, ',');
	getline(recordLine, person.phone2, ',');
	getline(recordLine, person.email, ',');
	getline(recordLine, person.web, ',');

	cout << "--------------------------------------------------" << endl;
	cout << "|" << setw(16) << "First Name: " << person.first_name << endl;
	cout << "|" << setw(16) << "Last Name: " << person.last_name << endl;
	cout << "|" << setw(16) << "Company name: " << person.company_name << endl;
	cout << "|" << setw(16) << "Address: " << person.address << endl;
	cout << "|" << setw(16) << "City: " << person.city << endl;
	cout << "|" << setw(16) << "Zip: " << person.zip << endl;
	cout << "|" << setw(16) << "Phone 1: " << person.phone1 << endl;
	cout << "|" << setw(16) << "Phone 2: " << person.phone2 << endl;
	cout << "|" << setw(16) << "Email: " << person.email << endl;
	cout << "|" << setw(16) << "Web: " << person.web << endl;
	cout << "--------------------------------------------------" << endl;

	cout << endl;
	inFile.close();
}

void searchRecord(string number, vector<DataNumber> searchVector) {
	int indexPos, recordIndex;
	long long int searchInt;

	searchInt = convertToInt(number);
	indexPos = binarySearchIndex(searchVector, searchInt);

	if (indexPos != -1) {
		recordIndex = searchVector.at(indexPos).index;
		retrieveRecord(recordIndex);
	}
	else {
		cout << "No record available. Please setup a new account" << endl;
	}
}

void readNumFile(string file, vector<DataNumber> &dataVector) {
	DataNumber field;
	fstream inFile;
	string line, searchNumber;
	int index;
	long long int number;

	inFile.open(file, ios::in);
	if (inFile) {

		while (getline(inFile, line)) {

			stringstream ss(line);
			ss >> index >> number;

			field.index = index;
			field.number = number;

			dataVector.push_back(field);
		}
		inFile.close();

		cout << "Enter a phone number to retrieve user data (Format:"
			" xxx-xxx-xxxx):" << endl;
		cout << "(example: 908-877-8409)" << endl << ">> ";

		getline(cin, searchNumber);
		searchRecord(searchNumber, dataVector);

	}
	else {
		cout << "This database hasn't been set up yet." << endl;
		cout << "Sort data before commencing search." << endl;
	}
}



void menu(string &file, string &outFileAppend, vector<DataNumber>searchVector) {
	string input, number;
	int choice;
	
	cout <<  "Would you like to sort data, or find a record?: " << endl;
	cout << "1. Sort data" << endl;
	cout << "2. Find record" << endl << ">> ";
	getline(cin, input);
	stringstream(input) >> choice;

	switch (choice) {
	case 1:
		cout << "What file would you like to sort: " << endl;
		cout << "1. 500 Records" << endl;
		cout << "2. 50K Records (please be patient, I haven't yet mastered binary sort)" << endl << ">> ";
		getline(cin, input);
		stringstream(input) >> choice;
		switch (choice) {
		case 1:
			file = "us-500C";
			outFileAppend = "500";
			break;
		case 2:
			file = "us-50000C";
			outFileAppend = "50000";
			break;
		}
		sortNumberData(file, outFileAppend);
		cout << "Done sorting!" << endl;
		cout << endl;
		break;
	case 2:
		cout << "Retrieve your data by: " << endl;
		cout << "1. Phone Number" << endl;
		cout << "2. Name (not yet functional)" << endl << ">> ";

		getline(cin, input);
		stringstream(input) >> choice;

		switch (choice) {
		case 1:
			cout << "1. Database 500" << endl;
			cout << "2. Database 50000" << endl << ">> ";
			getline(cin, input);
			stringstream(input) >> choice;
			switch (choice) {
			case 1:
				readNumFile("database500.txt", searchVector);
				break;
			case 2:
				readNumFile("database50000.txt", searchVector);
				break;
			}
			break;
		case 2:
			cout << "Website under construction. Please check again later" << endl;
			//readFile("names.txt");
			break;
		}
		break;
	}


}


int main() {

	string file, outFileAppend, input;
	vector<DataNumber> searchVector;
	
	while (true) {

		menu(file, outFileAppend, searchVector);
	}
	
	return 0;
}