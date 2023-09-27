#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

int calculateAgeInDays(calendar::sDate  date) {
	return calendar::getDifferenceDays(date,calendar::getSystemDate(), true);
} 



int main() {
	cout << "Please enter your date of birth :\n";
	calendar::sDate date = read::readDate();

	cout << "Your age is " << calculateAgeInDays(date) << " Day(s).";
	cout << "\n\n";
	return 0;
}
