#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;
struct sPeriod {
	sDate fromDate;
	sDate toDate;
};

bool isOverlapPeriods(sPeriod period1, sPeriod period2) {
	return(compareDates(period2.toDate, period1.fromDate) != enCompareDate::Before && compareDates(period2.fromDate, period1.toDate) != enCompareDate::After);
}
bool isOverlapPeriods_2(sPeriod period1, sPeriod period2) {
	return!(compareDates(period2.toDate, period1.fromDate) == enCompareDate::Before || compareDates(period2.fromDate, period1.toDate) == enCompareDate::After);
}

sPeriod readPeriod() {
	sPeriod period;
	bool first = true;
	do {
		if (!first) cout << "\nWrong entering please reenter the period :\n";else first = false;
		period.fromDate = read::readDate();
		period.toDate = read::readDate();
	} while (isDate1AfterDate2(period.fromDate, period.toDate));
	return period;
}
void runSystem() {
	system("cls");
	cout << "Enter Period 1:\n";
	sPeriod period1 = readPeriod();
	cout << "\n\nEnter Period 2:\n";
	sPeriod period2 = readPeriod();

	if (isOverlapPeriods(period1, period2))
		cout << "Yes periods overlap 1\n";
	else
		cout << "No there is no overlap 1\n";

	if (isOverlapPeriods_2(period1, period2))
		cout << "Yes periods overlap 2\n";
	else
		cout << "No there is no overlap 2\n";
}
int main() {

	do {
		runSystem();
	} while (doYouQuestion("Do you want to enter another test ? "));

	return 0;
}
