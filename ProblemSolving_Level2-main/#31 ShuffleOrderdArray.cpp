#include<iostream>
#include"myLibrary.h"
using namespace std;
void swap(int& A, int& B) {
	int temp = A;
	A = B;
	B = temp;
}
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
void shuffleArray(int arr[], int& arrLength) {
	int target;
	int j = 0;
	for (int i = 0;i < arrLength;i++) {
		swap(arr[generateRandomNumbers(1, arrLength) - 1], arr[generateRandomNumbers(1, arrLength) - 1]);
	}
}
int main() {
	srand(time(NULL));
	int arr[100] = { 0 };
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillArrayInOrder(arr, arrLength);
	cout << "Array Elements Before Shuffle \n";
	printArrayElements(arr, arrLength);
	shuffleArray(arr, arrLength);
	cout << "Array Elements After Shuffle \n";
	printArrayElements(arr, arrLength);
	return 0;
}
