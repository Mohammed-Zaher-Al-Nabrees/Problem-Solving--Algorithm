#include<iostream>
#include"myLibrary.h"
using namespace std;



void printNumberPattern(int number) {
	for (int i = 1; i <= number;i++) {
		for (int j = i; j > 0;j--)
			cout << i;
		cout << "\n";
	}
}
int main() {
	int number = readPositiveNumber();
	printNumberPattern(number);
	return 0;
}
