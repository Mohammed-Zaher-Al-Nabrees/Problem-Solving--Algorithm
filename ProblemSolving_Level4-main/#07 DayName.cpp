#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

short orderWeekDayOfDate(short day, short month, short year) {
	short a = floor((14 - month) / 12);
	short y = year - a;
	short m = month + 12 * a - 2;
	short d = day + y + floor(y / 4) - floor(y / 100) + floor(y / 400) + floor(31 * m / 12);
	//short d = 5 + day + y + floor(y / 4) + floor(31 * m / 12);
	d = d % 7;
	return d;
}

string weekDayName(short dayOrder) {
	string weekDays[] = { "Sun", "Mon", "Tue", "Wed", "Thurs", "Fri", "Sat" };
	return weekDays[dayOrder];
}

void printDayOfDate() {
	short year = read::readPositiveNumberMsg("Please enter year :");
	cout << "\n";
	short month = read::readNumberInRangeMsg("Please enter month :", 1, 12);
	cout << "\n";
	short day = read::readNumberInRangeMsg("Please enter day :", 1, calendar::countDaysInMonth(year, month));
	cout << "\n";

	cout << "Date	   :" << day << "/" << month << "/" << year << "\n";
	short orderDay = orderWeekDayOfDate(day, month, year);
	cout << "Day Order :" << orderDay << "\n";
	cout << "Day Name  :" << weekDayName(orderDay);
	cout << "\n";
}
int main() {
	printDayOfDate();

	return 0;
}
