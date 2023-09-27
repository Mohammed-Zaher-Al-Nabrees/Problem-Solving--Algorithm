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
void copyArray(int sourceArr[],int copyArr[],int &arrLength) {
	for (int i = 0;i < arrLength;) {
		addArray(sourceArr[i],copyArr,i);
	}
}
int main() {
	srand(time(NULL));
	const int maxLength = 100;
	int arr[maxLength],copy_arr[maxLength];
	int arrLength = readNumberMsg("Please enter the array size: ");
	fillTheArrayRandomly(arr, arrLength);
	copyArray(arr,copy_arr,arrLength);
	
	cout << "Source Array Elements : ";
	printArrayElements(arr, arrLength);
	cout << "Copy Array Elements : ";
	printArrayElements(copy_arr, arrLength);

	return 0;
}
