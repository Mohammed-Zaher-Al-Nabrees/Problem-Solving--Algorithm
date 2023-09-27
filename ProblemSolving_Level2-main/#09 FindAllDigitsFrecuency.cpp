#include <iostream>
#include "myLibrary.h"
using namespace std;


int frequancyofDigits(int number, int digit) {
	int position = 0, freqNo = 0;
	while (number > 0) {
		position = number % 10;
		if (position == digit) freqNo++;
		number = number / 10;

	}

	return freqNo;
}
void frequancyofAllDigits(int number) {
	int frequancy = 0;
	for (int i = 0;i < 10;i++) {
		frequancy = frequancyofDigits(number,i);
		if (frequancy > 0) {
			cout << "Digit " << i << " frequency is " << frequancy << " time(s) \n";
		}
	}
}

int main() {
	frequancyofAllDigits(readPositiveNumber());
	return 0;
}
