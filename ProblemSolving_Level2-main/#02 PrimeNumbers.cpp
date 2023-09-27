#include <iostream>
#include "myLibrary.h"
using namespace std;

bool isPrime(int n) {
	if (n == 1) return true;
	int sqRoot = ceil(sqrt(n));
	for (int i = 2;i <= sqRoot;i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void printPrimesInRange(int from, int to) {
	for (int c = from; c <= to;c++) {
		if (isPrime(c)) cout << c << "\n";
	}
}

void main(){
	int from = readPositiveNumber();
	int to = readPositiveNumber();
	printPrimesInRange(from, to);
}
