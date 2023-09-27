#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByOneDecade(calendar::sDate date)
{
	date.year += 10;
	return date;
}

int main() {
	calendar::sDate date;
	date = read::readDate();
	//short years = read::readPositiveNumberMsg("Enter the number of years to add :");
	date = increaseDateByOneDecade(date);
	cout << "\n\nThe date after " <<"" << "decade " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
