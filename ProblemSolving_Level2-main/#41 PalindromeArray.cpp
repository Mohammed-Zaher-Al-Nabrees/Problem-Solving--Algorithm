#include<iostream>
#include"myLibrary.h"
using namespace std;


void printArrayElements(int arr[], int& arrLength) {
	for (int i = 0;i < arrLength;i++) {
		cout << arr[i] << "  ";
	}
	cout << "\n";
}

void fillArray(int arr[100], int& arrLength) {
	arrLength = 10;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	arr[5] = 40;
	arr[6] = 30;
	arr[7] = 20;
	arr[8] = 10;
	arr[9] = 10;
}
bool isPalindromeArray(int arr[100], int& arrLength) {
	int counter = 0, reverse_counter = arrLength - 1;
	bool isPalindrome = true;
	while (counter < reverse_counter) {
		if (arr[counter] != arr[reverse_counter]) {
			isPalindrome = false;
			break;
		}
		counter++;
		reverse_counter--;
	}
	return isPalindrome;
}
int main() {
	const int maxLength = 100;
	int arr[maxLength];
	int arrLength = 0;
	fillArray(arr, arrLength);

	cout << "Array Elements : ";
	printArrayElements(arr, arrLength);

	if (isPalindromeArray(arr, arrLength)) {
		cout << "Yes array is palindrome";
	}
	else {
		cout << "No array is not palindrome";
	}

	return 0;
}
