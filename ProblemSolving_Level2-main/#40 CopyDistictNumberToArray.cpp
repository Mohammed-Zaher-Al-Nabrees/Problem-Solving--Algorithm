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
int searchNumberInArray(int arr[], int arrLength, int target) {
	//cout << "Number you are looking for is :" << target << "\n";
	for (int i = 0;i < arrLength;i++) {
		if (arr[i] == target)
			return i;
	}
	return -1;
}
bool isExistsNumberInArray(int arr[], int arrLength, int target) {
	return searchNumberInArray(arr, arrLength, target) != -1;
}
void copyDistinctElements(int sourceArr[], int copyArr[], int& arrLength, int& copyArrLength) {
	for (int i = 0;i < arrLength;i++) {
		if (!isExistsNumberInArray(copyArr, arrLength, sourceArr[i]))
			addArray(sourceArr[i], copyArr, copyArrLength);
	}
}
void fillArray(int arr[100], int& arrLength) {
	arrLength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}
int main() {
	srand(time(NULL));
	const int maxLength = 100;
	int arr[maxLength], copy_arr[maxLength];
	int arrLength = 0, copyArrLength = 0;
	fillArray(arr, arrLength);

	cout << "Source Array Elements : ";
	printArrayElements(arr, arrLength);
	copyDistinctElements(arr, copy_arr, arrLength, copyArrLength);
	cout << "Distinct Array Elements : ";
	printArrayElements(copy_arr, copyArrLength);

	return 0;
}
