#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

bool isLastDayInMonth(calendar::sDate date) {
	return date.day == calendar::countDaysInMonth(date.year,date.month);
}
bool isLastMonthInYear(short month) {
	return month == 12;
}
int main() {
	calendar::sDate date = read::readDate();

	if (isLastDayInMonth(date))
		cout << "Yes, date is last day in month";
	else
		cout << "No, date is Not last day in month";
	
	cout << "\n\n";


	if (isLastMonthInYear(date.month))
		cout << "Yes, month is last month in year";
	else
		cout << "No, month is Not last month in year";


	cout << "\n\n";
	return 0;
}
