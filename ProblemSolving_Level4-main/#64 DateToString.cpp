#include <iostream>
#include "myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;


string dateToString(sDate date) {
	string stringDate;
	stringDate = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	return stringDate;
}

int main() {

	sDate date = read::readDate();
	cout << "Date as String : " << dateToString(date) << "\n";
	cout << "\n" << endl;
	return 0;
}

