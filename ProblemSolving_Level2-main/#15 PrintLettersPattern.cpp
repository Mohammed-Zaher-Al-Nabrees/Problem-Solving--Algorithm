#include<iostream>
#include"myLibrary.h"
using namespace std;



void printLettersPattern(int number) {
	for (int i = 1; i <= number;i++) {
		for (int j = i; j > 0;j--)
			cout << (char)(i+64);
		cout << "\n";
	}
}


int main() {
	int number = readPositiveNumber();
	printLettersPattern(number);
	return 0;
}
