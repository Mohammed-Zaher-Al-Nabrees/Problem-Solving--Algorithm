#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

bool isLastDayInMonth(calendar::sDate date) {
	return date.day == calendar::countDaysInMonth(date.year, date.month);
}
bool isLastMonthInYear(short month) {
	return month == 12;
}

void addOneDayToDate(calendar::sDate& date) {
	if (isLastDayInMonth(date)) {
		if (isLastMonthInYear(date.month)) {
			date.year++;
			date.month = 1;
		}
		else {
			date.month++;
		}
		date.day = 1;
	}
	else {
		date.day++; 
	}


}

int main() {
	calendar::sDate date = read::readDate();
	addOneDayToDate(date);
	cout << "Date after adding one day " << date.day << "/" << date.month << "/" << date.year;
	cout << "\n\n";
	return 0;
}
