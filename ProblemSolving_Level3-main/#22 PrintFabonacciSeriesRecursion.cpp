#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void printFabonacciSeries(int num,int prev,int afterPrev) {
	int answer = 0;
	if (num > 0) {
		answer = prev + afterPrev;
		afterPrev = prev;
		prev = answer;
		cout << answer << " ";
		printFabonacciSeries(num - 1,prev,afterPrev);
	}

}

int main() {
	printFabonacciSeries(readNumberMsg("Print Fabonacci Series for : "), 0, 1);
}
