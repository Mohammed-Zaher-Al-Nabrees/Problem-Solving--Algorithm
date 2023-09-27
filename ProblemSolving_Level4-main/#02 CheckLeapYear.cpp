#include<iostream>
//#include<iomanip>
#include<string>
#include<cctype>
#include"myLibrary.h"
using namespace std;

bool isLeapYear(short year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;

	return false;
}
int main() {
	short year = myLibrary::read::readNumberMsg("Please enter the year : \n");
	if (isLeapYear(year))
		cout << "Yes, year [" << year << "] is a leap year .\n";
	else
		cout << "No, year [" << year << "] is not a leap year .\n";

	system("pause>0");
	return 0;
}
