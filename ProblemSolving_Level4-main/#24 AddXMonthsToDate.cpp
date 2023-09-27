#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByXMonth(calendar::sDate date,short months)
{
	for (int i = 1; i <= months;i++) {
		date = calendar::increaseDateByOneMonth(date);
	}
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	short months = read::readPositiveNumberMsg("Enter the number of months to add :");
	date = increaseDateByXMonth(date,months);
	cout << "\n\nThe date after"<<months<<" month(s) " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
