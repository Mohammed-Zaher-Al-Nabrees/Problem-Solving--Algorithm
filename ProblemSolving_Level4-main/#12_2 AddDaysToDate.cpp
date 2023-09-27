#include<iostream>
#include<string>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;


struct sDate { short year;short month;short day; };

sDate addDays(sDate date, short days) {
	short remainingDays = days + calendar::countDaysFromBeginingOfYear(date.year, date.month, date.day);
	date.month = 1;
	short monthDays;
	while (true) {
		 monthDays = calendar::countDaysInMonth(date.year, date.month);

		if (remainingDays > monthDays) {
			remainingDays = remainingDays - monthDays;
			date.month++;
			if (date.month > 12) {
				date.month = 1;
				date.year++;
			}
		}
		else {
			date.day = remainingDays;
			break;
		}
	
	}

	return date;
}
sDate readDate() {
	sDate date;
	date.day = read::readPositiveNumberMsg("Please enter a day :");
	cout << "\n";
	date.month = read::readPositiveNumberMsg("Please enter a month :");
	cout << "\n";
	date.year = read::readPositiveNumberMsg("Please enter a year :");
	cout << "\n";
	return date;
}
int main() {
	sDate date= readDate();
	short days = read::readPositiveNumberMsg("How many days to add ?");

	date = addDays(date, days);
	cout << "\nDate after adding [" << days << "] days is :" << date.day << "/" << date.month << "/" << date.year<<"\n\n";
	return 0;
}
