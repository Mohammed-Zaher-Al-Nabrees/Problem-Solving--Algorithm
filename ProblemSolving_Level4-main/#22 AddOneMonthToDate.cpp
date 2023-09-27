#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByOneMonth(calendar::sDate date)
{
	if (date.month >= 12)
	{
		date.month = 1;
		date.year++;
	}
	else {
		date.month++;
	}

	short days = calendar::countDaysInMonth(date.year,date.month);
	if (days < date.day) {
		date.day = days;
	}
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	//short weeks = read::readPositiveNumberMsg("Enter the number of weeks to add :");
	date = increaseDateByOneMonth(date);
	cout << "\n\nThe date after"<<" one month " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
