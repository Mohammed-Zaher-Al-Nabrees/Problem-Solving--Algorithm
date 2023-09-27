#include <iostream>
#include "myLibrary.h"
using namespace std;

void sumDigitsOfNumbers(int number) {
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number = number /10;
	}
	cout << sum;
}

int main() {
	sumDigitsOfNumbers(readPositiveNumber());
	return 0;
}
