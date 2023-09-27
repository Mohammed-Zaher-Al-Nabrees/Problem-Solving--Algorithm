#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate dateFromDayOrderInYear(short orderInYear, short year) {
	calendar::sDate date;
	date.day = 1, date.month = 1, date.year = year;
	short counter = 1, monthDays = 0;;
	while (true) {
		monthDays = calendar::countDaysInMonth(date.year, date.month);
		if (monthDays < orderInYear) {
			orderInYear -= monthDays;
			date.month++;
		}
		else {
			date.day = orderInYear;
			break;
		}

	}
	return date;
}
int main() {
	short year = read::readPositiveNumberMsg("Please the year :");
	short orderInYears = read::readPositiveNumberMsg("Please the day order in year :");

	calendar::sDate date = dateFromDayOrderInYear(orderInYears, year);
	cout << "\n\n Date from ["<<orderInYears<<"] is " << date.day << "/" << date.month << "/" << date.year<<"\n\n";

	return 0;
}
