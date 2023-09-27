#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByXWeek(calendar::sDate date, short weeks)
{
	for (short i = 1;i <= weeks;i++) {
		date = increaseDateByXWeek(date);
	}
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	short weeks = read::readPositiveNumberMsg("Enter the number of weeks to add :");
	date = increaseDateByXWeek(date,weeks);
	cout << "\n\nThe date after"<<weeks<<" weeks " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
