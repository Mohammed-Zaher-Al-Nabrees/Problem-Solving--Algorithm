#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;


sDate decreaseDateByOneWeek(sDate date)
{
	for (short i = 1;i <= 7;i++) {
		date = decreaseDateByOneDay(date);
	}
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	//short weeks = read::readPositiveNumberMsg("Enter weeks you want to decrease :");
	date = decreaseDateByOneWeek(date);
	cout << "Date after decrease "<<"" << "one week " << date.day << "/" << date.month << "/" << date.year << "\n\n";

	return 0;
}
