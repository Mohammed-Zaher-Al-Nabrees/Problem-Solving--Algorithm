#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

calendar::sDate increaseDateByOneCentury(calendar::sDate date)
{
	date.year += 100;
	return date;
}


int main() {
	calendar::sDate date;
	date = read::readDate();
	//short decades = read::readPositiveNumberMsg("Enter the number of decades to add :");
	date = increaseDateByOneCentury(date);
	cout << "\n\nThe date after " << "one cetury " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	return 0;
}
