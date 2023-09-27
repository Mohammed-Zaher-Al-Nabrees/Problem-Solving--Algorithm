#include<iostream>
#include"myLibrary.h"
using namespace std;


void printArrayElements(int arr[], int& arrLength) {
	for (int i = 0;i < arrLength;i++) {
		cout << arr[i] << "  ";
	}
	cout << "\n";
}
void addArray(int newElement, int arr[], int& arrLength) {
	arr[arrLength] = newElement;
	arrLength++;
}
void fillArraySimiDynamic(int arr[], int& arrLength, int maxLength) {
	int addMore = 0;
	do {
		addArray(readNumberMsg("Please enter a number : "), arr, arrLength);
		addMore = readNumberMsg("Do you want to add another number? [0]No [1]Yes :  ");

	} while (arrLength < maxLength && addMore > 0);
}

int main() {
	srand(time(NULL));
	const int maxLength = 100;
	int arr[maxLength];
	int arrLength = 0;
	fillArraySimiDynamic(arr, arrLength, maxLength);
	cout << "Array Length " << arrLength << "\n";
	printArrayElements(arr, arrLength);
	return 0;
}
