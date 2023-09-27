#include<iostream>
#include"myLibrary.h"
using namespace std;

void fillTheArrayRandomly(int arr[], int arrLength) {
	for (int i = 0;i < arrLength;i++) {
		arr[i] = generateRandomNumbers(1, 100);
	}
}
void printArrayElements(int arr[], int arrLength) {
	for (int i = 0;i < arrLength;i++) {
		cout << arr[i] << "  ";
	}
	cout << "\n";
}
int searchNumberInArray(int arr[], int arrLength, int target) {
	cout << "Number you are looking for is :" << target << "\n";
	for (int i = 0;i < arrLength;i++) {
		if (arr[i] == target)
			return i;
	}
	return -1;
}
bool isExistsNumberInArray(int arr[], int arrLength, int target) {
	return searchNumberInArray(arr, arrLength, target) != -1;
}
int main() {
	srand(time(NULL));
	int arr[100];
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr, arrLength);
	cout << "Array Elements \n";
	printArrayElements(arr, arrLength);
	int target = readNumberMsg("Please enter a number to search for:\n");

	if (isExistsNumberInArray(arr, arrLength, target))
	{
		cout << "Yes , The number is found :-)\n";
	}
	else {
		cout << "No , The number is not found :-(\n";
	}


	return 0;
}
