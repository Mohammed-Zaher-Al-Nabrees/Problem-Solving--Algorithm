#include<iostream>
#include<string>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

short countDaysInYear(short year) {
	return (years::isLeapYear(year)) ? 366 : 365;
}
short countHoursInYear(short year) {
	return countDaysInYear(year) * 24;
}
int countMinutesInYear(short year) {
	return countDaysInYear(year) * 60;
}
int countSecondsInYear(short year) {
	return countDaysInYear(year) * 60;
}
short countDaysInMonth(short year, short month) {
	if (month < 1 || month > 12) 
		return 0;

	switch (month) {
	case 1:case 3: case 5: case 7: case 8:case 10:case 12:
		return 31;
	case 2:
		return years::isLeapYear(year) ? 29 : 28;
	default: 
		return 30;
	}
}
short countHoursInMonth(short year, short month) {
	return countDaysInMonth(year, month) * 24;
}
int countMinutesInMonth(short year, short month) {
	return countHoursInMonth(year, month) * 60;
}
int countSecondsInMonth(short year,short month) {
	return countMinutesInMonth(year, month) * 60;
}

int main() {
	short year = read::readPositiveNumberMsg("Please enter year :");
	short month = read::readPositiveNumberMsg("Please enter month :");
	cout << "\n\nNumber of days in month [" << month << "] :" << countDaysInMonth(year, month);
	cout << "\nNumber of hours in month [" << month << "] :" << countHoursInMonth(year, month);
	cout << "\nNumber of minutes in month [" << month << "] :" << countMinutesInMonth(year, month);
	cout << "\nNumber of seconds in month [" << month << "] :" << countSecondsInMonth(year, month);
	return 0;
}
