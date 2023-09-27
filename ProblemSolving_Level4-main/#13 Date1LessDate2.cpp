#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

bool isDate1LessThanDate2(calendar::sDate date1, calendar::sDate date2) {
	return (date1.year < date2.year) ? true :
			(date1.year == date2.year) ? (date1.month < date2.month) ? true :
			(date1.month == date2.month) ? (date1.day < date2.day)  : false: false;
}
int main() {
	cout << "Date1: \n";
	calendar::sDate date1 = read::readDate();
	cout << "Date2: \n";
	calendar::sDate date2 = read::readDate();

	if (isDate1LessThanDate2(date1, date2))
		cout << "Yes, Date1 is less than Date2";
	else
		cout << "No, Date1 is greater than Date2";


	return 0;
}
