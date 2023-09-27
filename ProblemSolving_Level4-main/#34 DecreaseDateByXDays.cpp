#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

sDate decreaseDateByXDay(sDate date, short days) {
	for (short i = 1;i <= days;i++) {
		date = decreaseDateByOneDay(date);
	}
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	short days = read::readPositiveNumberMsg("Enter days you want to decrease :");
	date = decreaseDateByXDay(date,days);
	cout << "Date after decrease "<<days<<" day(s): " << date.day << "/" << date.month << "/" << date.year<<"\n\n";

	return 0;
}
