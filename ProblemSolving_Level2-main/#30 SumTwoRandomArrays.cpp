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

void sumTwoArrays(int arr1[], int arr2[],int arr_sum[], int& arrLength) {
	for (int j = 0;j < arrLength;j++) {
			arr_sum[j] = arr1[j] + arr2[j];
	}
}

int main() {
	srand(time(NULL));
	int arr1[100] = { 0 };
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr1, arrLength);
	cout << "First Array ";
	printArrayElements(arr1, arrLength);

	int arr2[100] = { 0 };
	fillTheArrayRandomly(arr2, arrLength);
	cout << "Second Array ";
	printArrayElements(arr2, arrLength);

	int arr_sum[100] = { 0 };
	sumTwoArrays(arr1,arr2,arr_sum, arrLength);
	cout << "Summation ";
	printArrayElements(arr_sum, arrLength);

	return 0;
}
