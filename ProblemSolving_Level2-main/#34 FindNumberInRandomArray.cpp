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
int searchNumberInArray(int arr[],int arrLength,int target) {
	cout << "Number you are looking for is :" << target << "\n";
	for (int i = 0;i < arrLength;i++) {
		if (arr[i] == target)
			return i;
	}
	return -1;
}
int main() {
	srand(time(NULL));
	int arr[100];
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArrayRandomly(arr, arrLength);
	cout << "Array Elements \n";
	printArrayElements(arr, arrLength);
	int target = readNumberMsg("Please enter a number to search for:\n");
	int result = searchNumberInArray(arr, arrLength, target);
	if( result > -1)
	{ 
		cout << "The number found at position : " << result<<"\n";
		cout << "The number found in order : " << result + 1<<"\n";

	}
	else{
		cout << "The number is not found :-(\n";
	}


	return 0;
}
