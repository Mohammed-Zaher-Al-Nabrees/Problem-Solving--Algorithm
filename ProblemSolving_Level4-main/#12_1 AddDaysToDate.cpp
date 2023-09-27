#include<iostream>
#include<string>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

short countDaysToEndOfYear(short& year, short& month, short day) {
	day = calendar::countDaysInMonth(year, month) - day;
	for (short i = month + 1;i <= 12;i++) {
		day += calendar::countDaysInMonth(year, i);
	}
	return day;
}

void addDays(short givenDays, short& year, short& month, short& day) {
	short daysToEndOfYear = countDaysToEndOfYear(year, month, day);

	if (givenDays > daysToEndOfYear) {//Not In This Year
		short daysInYear = calendar::countDaysInYear(++year);

		while (givenDays > daysInYear) {
			givenDays = givenDays - daysInYear;
			year++;
			daysInYear = calendar::countDaysInYear(year);
		}
	}

	//Calculate Month Days
	short daysToEndOfMonth = calendar::countDaysInMonth(year, month) - day;

	if (givenDays > daysToEndOfMonth)//Not In This Month
	{
		givenDays = givenDays - daysToEndOfMonth;
		short daysInMonth = calendar::countDaysInMonth(year, ++month);

		while (givenDays > daysInMonth)
		{
			givenDays = givenDays - daysInMonth;
			month++;
			daysInMonth = calendar::countDaysInMonth(year, month);
		}
		day = givenDays;
		if (month > 12)month = month % 12;
	}
	else
	{
		day = day + givenDays;
	}

}


int main() {
	short day = read::readPositiveNumberMsg("Please enter a day :");
	cout << "\n";
	short month = read::readPositiveNumberMsg("Please enter a month :");
	cout << "\n";
	short year = read::readPositiveNumberMsg("Please enter a year :");
	cout << "\n";
	short givenDays = read::readPositiveNumberMsg("How many days to add ?");
	cout << "\n";
	addDays(givenDays, year, month, day);
	cout << "Date after adding [" << givenDays << "] days is :" << day << "/" << month << "/" << year;
	cout << "\n";
	cout << "\n";
	return 0;
}
