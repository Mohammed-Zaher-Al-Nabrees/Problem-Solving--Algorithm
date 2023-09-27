#include<iostream>
#include"myLibrary.h"
using namespace std;

void printArrayElements(int arr[], int& arrLength) {
	for (int i = 0;i < arrLength;i++) {
		cout << arr[i] << "  ";
	}
	cout << "\n";
}
void fillArrayInOrder(int arr[], int& arrLength) {
	for (int j = 0;j < arrLength;j++) {
		arr[j] = j + 1;
	}
}
void reverseArray(int arr[], int reversed_arr[], int& arrLength) {
	for (int i = 0;i < arrLength;i++) {
		reversed_arr[i] = arr[arrLength -1 -i];
	}
}

int main() {
	srand(time(NULL));
	int arr[100] = { 0 }, reversed_arr[100]={0};
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr, arrLength);
	cout << "Array Elements \n";
	printArrayElements(arr, arrLength);

	reverseArray(arr, reversed_arr,arrLength);
	cout << "Reversed Array Elements \n";
	printArrayElements(reversed_arr, arrLength);

	return 0;
}
