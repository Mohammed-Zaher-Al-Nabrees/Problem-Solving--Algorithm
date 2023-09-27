#include <iostream>
#include "myLibrary.h"
using namespace std;
using namespace myLibrary;
using namespace calendar;

string dateFormat(sDate date, string format = "dd/mm/yyyy") {
	string result = format;
	manipulators::replace(result,"dd",to_string(date.day));
	manipulators::replace(result,"mm",to_string(date.month));
	manipulators::replace(result,"yyyy",to_string(date.year));
	return result;
}

int main() {
	sDate date = read::readDate();
	cout << dateFormat(date, "dd/mm/yyyy") << "\n";
	cout << dateFormat(date, "mm/dd/yyyy") << "\n";
	cout << dateFormat(date, "yyyy/mm/dd") << "\n";
	cout << dateFormat(date, "dd-mm-yyyy") << "\n";
	cout << dateFormat(date, "mm-dd-yyyy") << "\n";
	cout << dateFormat(date, "Day:dd, Month:mm, Year:yyyy") << "\n";
	cout << "\n" << endl;
	return 0;
}
