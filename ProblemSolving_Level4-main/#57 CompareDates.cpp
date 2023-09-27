#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;

enum enCompareDate { Before = -1, Equal = 0, After = 1 };
bool compareDates(sDate date1, sDate date2) {
	return isDate1BeforeDate2(date1, date2) ? enCompareDate::Before :
		isDate1EqualDate2(date1, date2) ? enCompareDate::Equal :
		enCompareDate::After;
}

int main() {
	sDate date1 = read::readDate();
	sDate date2 = read::readDate();

	switch (compareDates(date1, date2)) {
	case enCompareDate::Equal:
		cout << "Date1 Equal Date2.\n";
		break;
	case enCompareDate::Before:
		cout << "Date1 Before Date2.\n";
		break;
	case enCompareDate::After:
		cout << "Date1 After Date2.\n";
		break;
	}
	return 0;
}
