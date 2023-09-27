#include<iostream>
//#include<iomanip>
#include<string>
#include<cctype>
#include"myLibrary.h"
using namespace std;

bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
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
