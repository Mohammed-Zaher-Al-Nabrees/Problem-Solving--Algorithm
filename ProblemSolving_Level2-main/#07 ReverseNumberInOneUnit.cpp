#include <iostream>
#include "myLibrary.h"
using namespace std;

void reverseNumberAsInt_usingLog(int number) {
	int reversed = 0, power = (int)(log10(number));
	int location = pow(10, power);
	while (number > 0) {
		reversed += (number % 10) * location;
		number = number / 10;
		location /= 10;
	}
	cout << reversed << '\n';
}

void reverseNumberAsInt(int number) {
	int reversed = 0;
	while (number > 0) {
		reversed = reversed * 10 + (number % 10);
		number = number / 10;
		
	}
	cout << reversed << '\n';
}

int main() {
	reverseNumberAsInt(readPositiveNumber());
	return 0;
}
