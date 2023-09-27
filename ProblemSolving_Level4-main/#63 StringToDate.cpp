#include <iostream>
#include "myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;


sDate stringToDate(string stringDate) {
	sDate date;
	try {
		vector<string>dateSliced = manipulators::split(stringDate, "/");
		date.day = stoi(dateSliced.at(0));
		date.month = stoi(dateSliced.at(1));
		date.year = stoi(dateSliced.at(2));
	}
	catch (exception ex) {
		if (!isValidDate(date)) {
			cout << "Wrong input !!!\n";
			date.day = 1;
			date.month = 1;
			date.year = 1900;
		}
	}
	return date;
}


int main() {
	string stringDate;
	cout << "\nEnter the date in one line : ";
	cin >> stringDate;
	sDate date = stringToDate(stringDate);
	cout << "Date as date : ";
	printDate(date);
	cout << "\n" << endl;
	return 0;
}

