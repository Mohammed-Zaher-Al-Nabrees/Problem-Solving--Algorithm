#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

int getDifferenceDays(calendar::sDate  date1,calendar::sDate date2,bool includingEndDay=false) {

	int counter = (includingEndDay ? 1 : 0);
	while (calendar::isDate1LessThanDate2(date1, date2)) {
		counter++;
		date1 = calendar::addOneDayToDate(date1);
	}

	return counter;
} 

int main() {
	cout << "Date1 :\n";
	calendar::sDate date1 = read::readDate();
	cout << "Date2 :\n";
	calendar::sDate date2 = read::readDate();

	cout << "Difference is " << getDifferenceDays(date1,date2) << " Day(s).";
	cout << "\n\n";
	cout << "Difference is (Including End Day) " << getDifferenceDays(date1,date2,true)<<" Day(s).";
	cout << "\n\n";
	return 0;
}
