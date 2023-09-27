#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

sDate decreaseDateByOneMonth(sDate date)
{
	if (date.month == 1)
	{
		date.month = 12;
		date.year--;
	}
	else {
		date.month--;
	}

	short days = countDaysInMonth(date.year, date.month);
	if (days < date.day) {
		date.day = days;
	}
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	//short weeks = read::readPositiveNumberMsg("Enter weeks you want to decrease :");
	date = decreaseDateByOneMonth(date);
	cout << "Date after decrease "<<""<< "one month : " << date.day << " / " << date.month << " / " << date.year << "\n\n";

	return 0;
}
