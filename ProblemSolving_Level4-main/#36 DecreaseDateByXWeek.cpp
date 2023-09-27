#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

sDate decreaseDateByXWeek(sDate date, short weeks)
{
	for (short i = 1;i <= weeks;i++) {
		date = decreaseDateByOneWeek(date);
	}
	return date;
}


int main() {
	calendar::sDate date;
	date = read::readDate();
	short weeks = read::readPositiveNumberMsg("Enter weeks you want to decrease :");
	date = decreaseDateByXWeek(date,weeks);
	cout << "Date after decrease "<<weeks<< "week(s) : " << date.day << " / " << date.month << " / " << date.year << "\n\n";

	return 0;
}
