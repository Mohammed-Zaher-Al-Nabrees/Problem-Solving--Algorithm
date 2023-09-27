
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
int findTheMin(int arr[], int& arrLength) {
	int min = arr[0];
	for (int i = 1;i < arrLength;i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
int main() {
	srand(time(NULL));
	int arr[100] = { 0 };
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr, arrLength);
	printArrayElements(arr, arrLength);
	cout << "\nThe minimum Number is " << findTheMin(arr, arrLength);
	return 0;
}
