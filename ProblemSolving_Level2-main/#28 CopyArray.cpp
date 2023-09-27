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
	cout << "\n";
}

void copyArray(int original_arr[], int& arrLength, int copy_arr[]) {
	for (int i = 0;i < arrLength;i++) {
		copy_arr[i] = original_arr[i];
	}
}

int main() {
	srand(time(NULL));
	int arr[100] = { 0 }, copy_arr[100] = { 0 };
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr, arrLength);
	printArrayElements(arr, arrLength);
	copyArray(arr,arrLength, copy_arr);
	cout << "Copied Array ";
	printArrayElements(copy_arr,arrLength);
	return 0;
}
