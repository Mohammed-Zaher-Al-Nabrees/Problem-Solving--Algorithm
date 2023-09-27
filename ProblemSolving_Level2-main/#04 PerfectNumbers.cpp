#include <iostream>
#include "myLibrary.h"

using namespace std;

bool isPerfect(int n) {
	if (n < 6) return false;
	int sum = 0;
	for (int i = 1;i < n;i++) {
		if (n % i == 0) {
			sum = sum + i;
		}
	}
	if (sum == n)
		return true;
	else
		return false;
}

void printPerfectNumbersInRange(int from,int to) {
	for (;from <= to;from++) {
	if (isPerfect(from))
		cout << from << " Is Perfect" << "\n";
	}
}

int main(){
 	int from = readPositiveNumber();
	int to = readPositiveNumber();
	printPerfectNumbersInRange(from, to);
 	return 0;
}
