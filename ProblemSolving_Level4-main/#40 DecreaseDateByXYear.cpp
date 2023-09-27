#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;


sDate decreaseDateByXYear(sDate date, short years)
{
	date.year -= years;
	date.year < 0 ? date.year++ : date.year;
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	short years = read::readPositiveNumberMsg("Enter months you want to decrease :");
	date = decreaseDateByXYear(date,years);
	cout << "Date after decrease " << years << " year(s) : " << date.day << "/" << date.month << "/" << date.year << "\n\n";

	return 0;
}
