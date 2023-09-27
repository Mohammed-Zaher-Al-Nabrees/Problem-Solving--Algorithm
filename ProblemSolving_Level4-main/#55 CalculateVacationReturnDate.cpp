#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;


sDate calculateVacationReturnDate(sDate from, short days) {
	if (!isWeekend(from))
		days--;

	while (days > 0) {
		from = increaseDateByOneDay(from);
		if (!isWeekend(from))
			days--;	
	}

	return from;
}
void printDate(sDate date) {
	cout << date.day << "/" << date.month << "/" << date.year;
}

void runVacationReturnDate() {
	cout << "Vacation Starts :\n";
	sDate from;
	from = read::readDate();
	cout << "\n";
	sDate to = calculateVacationReturnDate(from, read::readPositiveNumberMsg("Please enter vacation days :"));
	cout << "Vacation Ends :\n";
	cout << getWeekDayName(getOrderWeekDayOfDate(to)) << " , ";
	printDate(to);
	cout << "\n";
	cout << "\n";
}
int main() {
	runVacationReturnDate();
	return 0;
}
