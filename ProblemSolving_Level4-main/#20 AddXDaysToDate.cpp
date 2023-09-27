#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByXDate(calendar::sDate date,short days){
	for (short i = 1;i <= days;i++) {
		date = calendar::addOneDayToDate(date);
	}
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	short days = read::readPositiveNumberMsg("Enter the number of days to add :");
	date = increaseDateByXDate(date,days);
	cout << "\n\nThe date after adding "<<date.day<<"/"<<date.month<<"/"<<date.year<<"\n\n";
	return 0;
}
