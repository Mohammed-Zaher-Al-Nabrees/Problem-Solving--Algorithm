
#include<iostream>
#include"myLibrary.h"
using namespace std;

void fillTheArrayRandomly(int arr[], int& arrLength) {
	for (int i = 0;i < arrLength;i++) {
		arr[i] = generateRandomNumbers(1, 100);
	}
}
void printArrayElements(int arr[], int& arrLength) {
	cout << "Array Elements : ";
	for (int i = 0;i < arrLength;i++) {
		cout << arr[i] << "  ";
	}
}

int findTheMax(int arr[], int& arrLength) {
	int max = arr[0];
	for (int i = 1;i < arrLength;i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

int main() {
	srand(time(NULL));
	int arr[100] = { 0 };
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr, arrLength);
	printArrayElements(arr, arrLength);
	cout << "\nMax Number is " << findTheMax(arr, arrLength);
	return 0;
}