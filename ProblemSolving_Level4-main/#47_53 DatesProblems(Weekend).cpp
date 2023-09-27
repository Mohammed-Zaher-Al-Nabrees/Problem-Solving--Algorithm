#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;

bool isEndOfWeek(sDate date) {
	return getOrderWeekDayOfDate(date) == 6;
}
bool isWeekend(sDate date) {
	short dateOrder = getOrderWeekDayOfDate(date);
	return dateOrder == 5 || dateOrder == 6;
}
bool isBusinessDay(sDate date) {
	return !isWeekend(date);
}
short countDaysUntilEndOfWeek(sDate date) {
	return 6 - getOrderWeekDayOfDate(date);
}
short countDaysUntilEndOfMonth(sDate date) {
	return (countDaysInMonth(date.year, date.month) - date.day) + 1;
}
short countDaysUntilEndOfYear(sDate date) {
	return (countDaysInYear(date.year) - countDaysFromBeginingOfYear(date)) + 1;
}

int main() {
	sDate date;
	date = read::readDate();

	cout << "Today is " << getWeekDayName(getOrderWeekDayOfDate(date)) << ", " << date.day << "/" << date.month << "/" << date.year << "\n\n";

	cout << "Is it end of week ?\n";
	if (isEndOfWeek(date))cout << "Yes,it is end of week.\n\n";else cout << "No,it is not end of week.\n\n";

	cout << "Is it a weekend ?\n";
	if (isWeekend(date))cout << "Yes,it is weekend.\n\n";else cout << "No,it is not weekend.\n\n";

	cout << "Is it business day ?\n";
	if (isBusinessDay(date))cout << "Yes,it is business day.\n\n";else cout << "No,it is not business day.\n\n";

	cout << "Day(s) until end of week " << countDaysUntilEndOfWeek(date) << " day(s).\n";
	cout << "Day(s) until end of month " << countDaysUntilEndOfMonth(date) << " day(s).\n";
	cout << "Day(s) until end of year " << countDaysUntilEndOfYear(date) << " day(s).\n";


	return 0;
}
