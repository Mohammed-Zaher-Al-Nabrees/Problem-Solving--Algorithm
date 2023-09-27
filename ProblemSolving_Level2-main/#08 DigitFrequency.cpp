#include <iostream>
#include "myLibrary.h"

using namespace std;



int frequancyofDigits(int number, int digit) {
	int position=0,freqNo=0;
	while (number > 0) {
		position = number % 10;
		if (position == digit) freqNo++;
		number = number / 10;

	}

	return freqNo;
}

int main() {
	int number = readPositiveNumber();
	int digit = readPositiveNumber();
	cout << "Digit "<<digit<<" frequency is " << frequancyofDigits(number, digit) <<" time(s) \n";
	return 0;
}
