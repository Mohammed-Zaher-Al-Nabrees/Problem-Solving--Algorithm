#include<iostream>
#include<string>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

string getMonthName(short& month) {
	string monthsNames[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return monthsNames[month];
}
void printHeader(short& month) {
	cout << "\n" << draw::generateTabs(2);
	cout << draw::generateLine(15) << getMonthName(month) << draw::generateLine(15) << "\n\n";
	cout << draw::generateTabs(2);
	cout << setw(3) << calendar::getWeekDayName(0) << "  ";
	cout << setw(3) << calendar::getWeekDayName(1) << "  ";
	cout << setw(3) << calendar::getWeekDayName(2) << "  ";
	cout << setw(3) << calendar::getWeekDayName(3) << "  ";
	cout << setw(3) << calendar::getWeekDayName(4) << "  ";
	cout << setw(3) << calendar::getWeekDayName(5) << "  ";
	cout << setw(3) << calendar::getWeekDayName(6) << "  ";
	cout << endl;

}
void printFooter() {
	cout << "\n" << draw::generateTabs(2);
	cout << draw::generateLine(18) << draw::generateLine(15) << "\n\n";
}
void printBody(short& year, short& month) {
	short firstDay = calendar::getOrderWeekDayOfDate(1, month, year);
	short countMonthDays = calendar::countDaysInMonth(year, month);
	short currentDay = 1;

	cout << draw::generateTabs(2);
	for (short i = 0;currentDay <= countMonthDays;i++) {
		if (i >= firstDay) {
			cout << setw(3) << currentDay ;
			currentDay++;
		}
		else {
			cout << setw(3) << " ";
		}
		cout << "  ";
		if ((i+1) % 7 == 0) {
			cout << endl;
			cout << draw::generateTabs(2);
		}
	}
}
void printMonthCalendar(short year, short month) {
	printHeader(month);
	printBody(year,month);
	printFooter();
}

void printYearCalendar(short &year) {
	cout << draw::generateTabs(2) << draw::generateLine(33,'=') << "\n";
	cout << draw::generateTabs(12) << "Calendar - " << year << "\n";
	cout << draw::generateTabs(2) << draw::generateLine(33, '=') << "\n";

	for (short i = 1;i <= 12;i++) {
		printMonthCalendar(year,i);
	}


}
int main() {
	short year = read::readPositiveNumberMsg("Please enter year :");
	cout << "\n";
	printYearCalendar(year);
	return 0;
}
