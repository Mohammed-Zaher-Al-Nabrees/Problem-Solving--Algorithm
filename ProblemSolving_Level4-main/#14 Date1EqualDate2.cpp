#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

bool isDate1EqualDate2(calendar::sDate date1, calendar::sDate date2) {
	return date1.year == date2.year && date1.month == date2.month&& date1.day == date2.day;
}
int main() {
	cout << "Date1: \n";
	calendar::sDate date1 = read::readDate();
	cout << "Date2: \n";
	calendar::sDate date2 = read::readDate();

	if (isDate1EqualDate2(date1, date2))
		cout << "Yes, Date1 is Equal Date2";
	else
		cout << "No, Date1 is NOT equal Date2";


	cout << "\n\n";
	return 0;
}
