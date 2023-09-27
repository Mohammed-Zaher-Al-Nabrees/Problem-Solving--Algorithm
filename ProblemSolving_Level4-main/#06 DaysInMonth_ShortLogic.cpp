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
	if (month < 1 || month > 12) return 0;
	short days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? ( years::isLeapYear(year) ? 29 : 28) : days[month+1];
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
