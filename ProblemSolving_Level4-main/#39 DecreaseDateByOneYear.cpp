#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;


sDate decreaseDateByOneYear(sDate date)
{
	date.year < 1 ? date.year : date.year--;
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	//short months = read::readPositiveNumberMsg("Enter months you want to decrease :");
	date = decreaseDateByOneYear(date);
	cout << "Date after decrease " << "one " << "year : " << date.day << "/" << date.month << "/" << date.year << "\n\n";

	return 0;
}
