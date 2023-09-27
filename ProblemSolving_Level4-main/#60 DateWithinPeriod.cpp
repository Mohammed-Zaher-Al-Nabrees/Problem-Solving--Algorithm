#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;

bool isDateInPeriod(sPeriod period, sDate date) {
	return (compareDates(period.fromDate, date) != enCompareDate::Before || compareDates(date, period.toDate) != enCompareDate::After);
}
int main() {
	sPeriod period = read::readPeriod();
	sDate date = read::readDate();

	if (isDateInPeriod(period, date))
		cout << "Yes , Date is whithin period !";
	else
		cout << "No , Date is not whithin period!";

	return 0;
}
