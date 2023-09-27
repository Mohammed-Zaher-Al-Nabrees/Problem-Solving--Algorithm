#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;

int countOverlapsDays(sPeriod period1, sPeriod period2) {
	if (isPeriodsOverlap(period1, period2))
	{
		if (compareDates(period1.fromDate, period2.fromDate) != enCompareDate::After)
			period1.fromDate = period2.fromDate;
		if (compareDates(period1.toDate, period2.toDate) != enCompareDate::Before)
			period1.toDate = period2.toDate;

		return periodLength(period1, true);
	}
	else
		return 0;
}

int main() {
	sPeriod period = read::readPeriod();
	sPeriod period2 = read::readPeriod();

	cout << "Overlaps Days Count is " << countOverlapsDays(period, period2) << "\n";

	return 0;
}
