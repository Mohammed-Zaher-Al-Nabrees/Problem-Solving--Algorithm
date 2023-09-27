#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
void printFabonacciSeries(int to) {
	int current = 0, prev = 1, afterPrev = 0;
	cout << "\n" << 1 << " ";
	for (int c = 1;c < to;c++) {
		current = prev + afterPrev;
		cout << current << " ";
		afterPrev = prev;
		prev = current;
	}
}

int main() {
	printFabonacciSeries(readNumberMsg("Print Fabonacci Series of "));
}
