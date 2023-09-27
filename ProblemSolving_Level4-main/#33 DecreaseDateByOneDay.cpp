#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

sDate decreaseDateByOneDay(sDate date) {
	if (date.day == 1) {
		if (date.month == 1) {
			date.year--;
			date.month = 12;
		}
		else {
			date.month--;
		}
		date.day = countDaysInMonth(date.year, date.month);
	}
	else {
		date.day--;
	}
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	date = decreaseDateByOneDay(date);
	cout << "Date after decrease one day " << date.day << "/" << date.month << "/" << date.year<<"\n\n";

	return 0;
}
