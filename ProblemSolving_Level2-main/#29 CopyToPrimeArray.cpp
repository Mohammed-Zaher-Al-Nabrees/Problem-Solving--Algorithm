#include<iostream>
#include"myLibrary.h"
using namespace std;

enum enPrimStatus { NotPrime = false, Prime = true };
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
enPrimStatus isPrime(int target) {
	if (target == 1)
		return enPrimStatus::Prime;
	for (int i = 2;i <= sqrt(target);i++) {
		if (target % i == 0) 
			return enPrimStatus::NotPrime;
	}
	return enPrimStatus::Prime;
}
void copyPrimesToArray(int original_arr[], int& arrLength, int copy_arr[], int& copy_arrLength) {
	copy_arrLength = 0;
	for (int j = 0;j < arrLength;j++) {
		if (isPrime(original_arr[j]) == enPrimStatus::Prime) {
			copy_arr[copy_arrLength] = original_arr[j];
			copy_arrLength++;
		}
	}
}

int main() {
	srand(time(NULL));
	int arr[100] = { 0 };
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr, arrLength);
	cout << "Original ";
	printArrayElements(arr, arrLength);

	int copy_arr[100] = { 0 };
	int copy_arrLength = 0;
	copyPrimesToArray(arr, arrLength, copy_arr, copy_arrLength);
	cout << "Prime ";
	printArrayElements(copy_arr, copy_arrLength);
	return 0;
}
