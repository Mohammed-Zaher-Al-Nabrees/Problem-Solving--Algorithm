#include <iostream>
#include "myLibrary.h"
using namespace std;



void printInvertedLettersPattern(int number) {
	for (int i = number; i > 0;i--) {
		for (int j = i; j > 0;j--)
			cout << (char)(i+64);
		cout << "\n";
	}
}
int main() {
	int number = readPositiveNumber();
	printInvertedLettersPattern(number);
	return 0;
}
