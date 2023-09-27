#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByOneWeek(calendar::sDate date)
{
	for (short i = 1;i <= 7;i++) {
		date = addOneDayToDate(date);
	}
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	//short days = read::readPositiveNumberMsg("Enter the number of days to add :");
	date = increaseDateByOneWeek(date);
	cout << "\n\nThe date after one week " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
