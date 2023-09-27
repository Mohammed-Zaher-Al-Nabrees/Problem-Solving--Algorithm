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
void fillTheArrayRandomly(int arr[], int arrLength) {
	for (int i = 0;i < arrLength;i++) {
		arr[i] = generateRandomNumbers(1, 100);
	}
}

void copyPrimeElements(int sourceArr[], int copyArr[], int& arrLength, int& copyArrLength) {
	for (int i = 0;i < arrLength;i++) {
		if (isPrime(sourceArr[i])== enPrimStatus::Prime)
			addArray(sourceArr[i], copyArr, copyArrLength);
	}
}
int main() {
	srand(time(NULL));
	const int maxLength = 100;
	int arr[maxLength], copy_arr[maxLength];
	int arrLength = readNumberMsg("Please enter the array size: "), copyArrLength = 0;
	fillTheArrayRandomly(arr, arrLength);
	copyPrimeElements(arr, copy_arr, arrLength, copyArrLength);

	cout << "Source Array Elements : ";
	printArrayElements(arr, arrLength);
	cout << "Prime Array Elements : ";
	printArrayElements(copy_arr, copyArrLength);

	return 0;
}
