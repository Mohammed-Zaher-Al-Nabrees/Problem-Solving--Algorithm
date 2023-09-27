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
void test1() {
	cout << "============================== Test 1 ======================\n";
	cout << "Period 1:\n";
	sPeriod period1;
	period1.fromDate.day = 1;
	period1.fromDate.month = 5;
	period1.fromDate.year = 2000;
	period1.toDate.day = 15;
	period1.toDate.month = 5;
	period1.toDate.year = 2000;

	printDate(period1.fromDate);
	cout << "-";
	printDate(period1.toDate);


	cout << "\n Period 2:\n";
	sPeriod period2;
	period2.fromDate.day = 2;
	period2.fromDate.month = 5;
	period2.fromDate.year = 2000;
	period2.toDate.day = 15;
	period2.toDate.month = 5;
	period2.toDate.year = 2000;

	printDate(period2.fromDate);
	cout << "-";
	printDate(period2.toDate);

	cout << endl;
	if (isOverlapPeriods(period1, period2))
		cout << "Yes periods overlap 1\n";
	else
		cout << "No there is no overlap 1\n";

	if (isOverlapPeriods_2(period1, period2))
		cout << "Yes periods overlap 2\n";
	else
		cout << "No there is no overlap 2\n";
}
void test2() {
	cout << "============================== Test 2 ======================\n";
	cout << "Period 1:\n";
	sPeriod period1;
	period1.fromDate.day = 1;
	period1.fromDate.month = 5;
	period1.fromDate.year = 2000;
	period1.toDate.day = 15;
	period1.toDate.month = 5;
	period1.toDate.year = 2000;
	printDate(period1.fromDate);
	cout << "-";
	printDate(period1.toDate);

	cout << "\n Period 2:\n";
	sPeriod period2;
	period2.fromDate.day = 20;
	period2.fromDate.month = 4;
	period2.fromDate.year = 2000;
	period2.toDate.day = 6;
	period2.toDate.month = 5;
	period2.toDate.year = 2000;
	printDate(period2.fromDate);
	cout << "-";
	printDate(period2.toDate);
	cout << endl;

	if (isOverlapPeriods(period1, period2))
		cout << "Yes periods overlap 1\n";
	else
		cout << "No there is no overlap 1\n";

	if (isOverlapPeriods_2(period1, period2))
		cout << "Yes periods overlap 2\n";
	else
		cout << "No there is no overlap 2\n";
}
void test3() {
	cout << "============================== Test 3 ======================\n";
	cout << "Period 1:\n";
	sPeriod period1;
	period1.fromDate.day = 1;
	period1.fromDate.month = 5;
	period1.fromDate.year = 2000;
	period1.toDate.day = 15;
	period1.toDate.month = 5;
	period1.toDate.year = 2000;
	printDate(period1.fromDate);
	cout << "-";
	printDate(period1.toDate);

	cout << "\n Period 2:\n";
	sPeriod period2;
	period2.fromDate.day = 20;
	period2.fromDate.month = 4;
	period2.fromDate.year = 2000;
	period2.toDate.day = 17;
	period2.toDate.month = 5;
	period2.toDate.year = 2000;
	printDate(period2.fromDate);
	cout << "-";
	printDate(period2.toDate);
	cout << endl;

	if (isOverlapPeriods(period1, period2))
		cout << "Yes periods overlap 1\n";
	else
		cout << "No there is no overlap 1\n";

	if (isOverlapPeriods_2(period1, period2))
		cout << "Yes periods overlap 2\n";
	else
		cout << "No there is no overlap 2\n";
}
void test4() {
	cout << "============================== Test 4 ======================\n";
	cout << "Period 1:\n";
	sPeriod period1;
	period1.fromDate.day = 1;
	period1.fromDate.month = 5;
	period1.fromDate.year = 2000;
	period1.toDate.day = 15;
	period1.toDate.month = 5;
	period1.toDate.year = 2000;
	printDate(period1.fromDate);
	cout << "-";
	printDate(period1.toDate);

	cout << "\n Period 2:\n";
	sPeriod period2;
	period2.fromDate.day = 14;
	period2.fromDate.month = 5;
	period2.fromDate.year = 2000;
	period2.toDate.day = 17;
	period2.toDate.month = 5;
	period2.toDate.year = 2000;
	printDate(period2.fromDate);
	cout << "-";
	printDate(period2.toDate);
	cout << endl;

	if (isOverlapPeriods(period1, period2))
		cout << "Yes periods overlap 1\n";
	else
		cout << "No there is no overlap 1\n";

	if (isOverlapPeriods_2(period1, period2))
		cout << "Yes periods overlap 2\n";
	else
		cout << "No there is no overlap 2\n";
}
void test5() {
	cout << "============================== Test 5 ======================\n";
	cout << "Period 1:\n";
	sPeriod period1;
	period1.fromDate.day = 1;
	period1.fromDate.month = 5;
	period1.fromDate.year = 2000;
	period1.toDate.day = 15;
	period1.toDate.month = 5;
	period1.toDate.year = 2000;
	printDate(period1.fromDate);
	cout << "-";
	printDate(period1.toDate);

	cout << "\n Period 2:\n";
	sPeriod period2;
	period2.fromDate.day = 17;
	period2.fromDate.month = 5;
	period2.fromDate.year = 2000;
	period2.toDate.day = 25;
	period2.toDate.month = 5;
	period2.toDate.year = 2000;
	printDate(period2.fromDate);
	cout << "-";
	printDate(period2.toDate);

	cout << endl;

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
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
