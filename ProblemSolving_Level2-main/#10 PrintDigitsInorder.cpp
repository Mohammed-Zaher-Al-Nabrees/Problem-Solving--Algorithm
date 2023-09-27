#include<iostream>
#include"myLibrary.h"
using namespace std;


int reverseNumberAsInt(int number) {
	int reversed = 0;
	while (number > 0) {
		reversed = reversed * 10 + (number % 10);
		number = number / 10;

	}
	return reversed;
}
void printDigitsofNumber(int number) {
	while (number > 0) {
		cout << number % 10 << '\n';
		number = number / 10;
	}
}

int main() {
	printDigitsofNumber(reverseNumberAsInt(readPositiveNumber()));
	return 0;
}
