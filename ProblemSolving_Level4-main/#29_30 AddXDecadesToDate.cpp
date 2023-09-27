#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByXDecade(calendar::sDate date, short decades)
{
	date.year += (10 * decades);
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	short decades = read::readPositiveNumberMsg("Enter the number of decades to add :");
	date = increaseDateByXDecade(date,decades);
	cout << "\n\nThe date after " << decades << "decade(s) " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
