#include<iostream>
#include<string>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

short countDaysFromBeginningOfYear(short &year,short &month,short day) {
	for (short i = 1;i < month;i++) {
		day += calendar::countDaysInMonth(year,i);
	}
	return day;
}
int main() {
	short year = read::readPositiveNumberMsg("Please enter year :");
	cout << "\n";
	short month = read::readPositiveNumberMsg("Please enter month :");
	cout << "\n";
	short day = read::readPositiveNumberMsg("Please enter day :");
	cout << "\n";
	cout<<"Number of days from the beginning of the year is "<<countDaysFromBeginningOfYear(year, month, day);
	cout << "\n";
	cout << "\n";
	return 0;
}
