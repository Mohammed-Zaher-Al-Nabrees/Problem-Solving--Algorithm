#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;

short calculateVacationActualDays(sDate from, sDate to) {

	int counter = 0;
	if (!isDate1LessThanDate2(from, to)) {
		swapDates(from, to);
	}

	while (isDate1LessThanDate2(from, to)) {
		if (isBusinessDay(from))
			counter++;
		from = increaseDateByOneDay(from);
	}

	return counter;
}

void calculateVacationDays() {
	cout << "Vacation Starts :\n";
	sDate from;
	from = read::readDate();
	cout << "\n";
	cout << "Vacation Ends :\n";
	sDate to;
	to = read::readDate();
	cout << "\n";

	cout << "Vacation from: " << getWeekDayName(getOrderWeekDayOfDate(from)) << ", " << from.day << "/" << from.month << "/" << from.year << "\n";
	cout << "Vacation to: " << getWeekDayName(getOrderWeekDayOfDate(to)) << ", " << to.day << "/" << to.month << "/" << to.year << "\n\n";
	cout << "Actual vacation day(s) : " << calculateVacationActualDays(from, to) << "\n\n";
}
int main() {
	calculateVacationDays();

	return 0;
}
