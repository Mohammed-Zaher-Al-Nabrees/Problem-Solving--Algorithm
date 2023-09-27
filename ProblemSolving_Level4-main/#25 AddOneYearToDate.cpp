#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByOneYear(calendar::sDate date)
{
	date.year++;
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	//short months = read::readPositiveNumberMsg("Enter the number of months to add :");
	date = increaseDateByOneYear(date);
	cout << "\n\nThe date after one "<<" year " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
