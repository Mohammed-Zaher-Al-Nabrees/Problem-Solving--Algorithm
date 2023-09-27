#include<iostream>
#include"myLibrary.h"
using namespace std;

void fillTheArray(int arr[], int arrLength) {
	cout << "Please enter the array elements :\n";
	string msg = "";
	for (int i = 0;i < arrLength;i++) {
		msg = "Element [" + to_string(i+1);
		msg = msg + "]: ";
		arr[i] = readNumberMsg(msg);
	}
}

int checkRepeation(int arr[], int arrLength, int target) {
	int count = 0;
	for (int i = 0;i < arrLength;i++) {
		if (arr[i] == target) count++;
	}
	return count;
}

int main() {
	srand(time(NULL));
	int arr[100] = { 0 };
	int arrLength = readNumberMsg("Please enter the array size:\n");
	fillTheArray(arr, arrLength);
	int target = readNumberMsg("Please enter the number you want to check:\n");
	int repeatitions = checkRepeation(arr, arrLength,target);
	cout << target << " is repeated " << repeatitions << " time(s)\n";
	return 0;
}
