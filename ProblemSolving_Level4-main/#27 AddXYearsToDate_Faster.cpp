#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByXYearFaster(calendar::sDate date, short years)
{
	date.year += years;
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	short years = read::readPositiveNumberMsg("Enter the number of years to add :");
	date = increaseDateByXYearFaster(date,years);
	cout << "\n\nThe date after " <<years<< " year(s) " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
