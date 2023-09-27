#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

sDate decreaseDateByXMonth(sDate date, short months)
{
	for (int i = 1; i <= months;i++) {
		date = decreaseDateByOneMonth(date);
	}
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	short months = read::readPositiveNumberMsg("Enter months you want to decrease :");
	date = decreaseDateByXMonth(date);
	cout << "Date after decrease " << months << "month(s) : " << date.day << "/" << date.month << "/" << date.year << "\n\n";

	return 0;
}
