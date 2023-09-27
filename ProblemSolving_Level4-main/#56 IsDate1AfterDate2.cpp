#include<iostream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;

bool isDate1AfterDate2(sDate date1, sDate date2) {
	return (!isDate1BeforeDate2(date1, date2) );
}

int main() {
	sDate date1= read::readDate(); 
	sDate date2 = read::readDate();
	if (isDate1AfterDate2(date1, date2))
		cout << "Yes Date1 after Date2.\n";
	else 
		cout << "No Date1 is not after Date2.\n";
	return 0;
}
