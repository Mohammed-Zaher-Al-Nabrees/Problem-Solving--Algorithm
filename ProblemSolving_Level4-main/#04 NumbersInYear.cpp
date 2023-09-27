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

int main() {
	short year = read::readPositiveNumberMsg("Please enter year to count :");
	cout << "\n\nNumber of days in year ["<<year<<"] :" << countHoursInYear(year);
	cout << "\nNumber of hours in year [" << year << "] :" << countHoursInYear(year);
	cout << "\nNumber of minutes in year [" << year << "] :" << countMinutesInYear(year);
	cout << "\nNumber of seconds in year [" << year << "] :" << countSecondsInYear(year);
	return 0;
}
