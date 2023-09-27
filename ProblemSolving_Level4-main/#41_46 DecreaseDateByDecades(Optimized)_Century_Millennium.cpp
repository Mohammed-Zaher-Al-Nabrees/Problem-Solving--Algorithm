#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

sDate decreaseDateByOneDecade(sDate date)
{
	date.year -= 10;
	return date;
}
sDate decreaseDateByXDecade(sDate date, short decades)
{
	date.year -= (10 * decades);
	return date;
}
sDate decreaseDateByOneCentury(sDate date)
{
	date.year -= 100;
	return date;
}
sDate decreaseDateByOneMillennium(sDate date)
{
	date.year -= 1000;
	return date;
}
int main() {
	calendar::sDate date;
	date = read::readDate();
	date = decreaseDateByOneDecade(date);
	cout << "Date after decrease one decade : " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	date = decreaseDateByXDecade(date,10);
	cout << "Date after decrease 10 decade : " << date.day << "/" << date.month << "/" << date.year << "\n\n";
	date = decreaseDateByOneCentury(date);
	cout << "Date after decrease one century : " << date.day << "/" << date.month << "/" << date.year << "\n\n";	
	date = decreaseDateByOneMillennium(date);
	cout << "Date after decrease one millennium : " << date.day << "/" << date.month << "/" << date.year << "\n\n";




	return 0;
}
