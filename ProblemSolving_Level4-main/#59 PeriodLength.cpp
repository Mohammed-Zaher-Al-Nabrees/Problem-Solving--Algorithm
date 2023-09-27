#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;
short periodLength(sPeriod period,bool includingEndDay = false) {
	return getDifferenceDays(period.fromDate,period.toDate,includingEndDay);
}
int main() {
	sPeriod period = read::readPeriod();
	cout << "\nThe period length " << periodLength(period);
	cout << "\nThe period length (including the end day) " << periodLength(period,true)<<"\n\n";
	return 0;
}
