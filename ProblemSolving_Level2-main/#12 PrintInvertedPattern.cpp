#include<iostream>
#include"myLibrary.h"
using namespace std;

void printInvertedPattern(int number) {
	for (int i = number; i > 0;i--) {
		for (int j = i; j > 0;j--)
			cout << i;
		cout << "\n";
	}
}

int main() {
	int number = readPositiveNumber();
	printInvertedPattern(number);
	return 0;
}
