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
		arr[i] = generateRandomNumbers(-100, 100);
	}
}
int countPositiveElements(int arr[], int& arrLength) {
	int count = 0;
	for (int i = 0;i < arrLength;i++) {
		if (arr[i] >= 0)
			count++;
	}
	return count;
}
int main() {
	srand(time(NULL));
	const int maxLength = 100;
	int arr[maxLength];
	int arrLength = readNumberMsg("Please enter the array size: "), copyArrLength = 0;
	fillTheArrayRandomly(arr, arrLength);
	cout << "Array Elements : ";
	printArrayElements(arr, arrLength);
	cout << "Positive numbers count is : " << countPositiveElements(arr,arrLength) ;
	return 0;
}
