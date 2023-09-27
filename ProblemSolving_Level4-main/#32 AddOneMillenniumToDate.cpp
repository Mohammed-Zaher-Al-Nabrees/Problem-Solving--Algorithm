#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;


calendar::sDate increaseDateByOneMillennium(calendar::sDate date)
{
	date.year += 1000;
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	date = increaseDateByOneMillennium(date);
	cout << "\n\nThe date after one millennium " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
