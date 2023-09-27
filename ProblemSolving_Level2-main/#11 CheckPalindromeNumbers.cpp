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

bool isPalindrome(int number) {
	return number == reverseNumberAsInt(number);
}

int main() {
	int number = readPositiveNumber();
	if (isPalindrome(number))
		cout << number<<" Palindrome Number \n";
	else
		cout << number <<" Not a Palindrome Number \n";
	return 0;
}
