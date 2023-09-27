#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

const short rows = 3, cols = 3;

void fill2DArrayRandomly(int arr[rows][cols], int rows, int cols) {
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
			arr[row][col] = generateRandomNumbers(0, 10);
		}

}
void print2DArrayElements(int arr[rows][cols], short rows, short cols) {
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			printf("%0*d", 2, arr[row][col]);
			cout << setw(4) << "   ";
		}
		cout << endl;
	}
}
bool isPalindromeArray(int arr[rows][cols], int rows, int cols) {
	bool isPalindrome = true;

	for (short row = 0;row < rows;row++) {
		for (short col = 0; col < cols/2; col++) {
			if (arr[row][col] != arr[row][cols - 1 - col]) {
				isPalindrome = false;
				return false;
			}
		}
	}
	return isPalindrome;
}

int main() {
	srand(time(NULL));
	int arr[rows][cols] = { {1,2,1},{5,3,5},{2,1,2} }; //{ {1,2,1},{5,3,5},{3,1,0} };
	cout << "Matrix 1: \n";
	print2DArrayElements(arr, rows, cols);

	if (isPalindromeArray(arr, rows, cols))
		cout << "\nYes it is palindromic";
	else
		cout << "\nNo it is not palindromic";

}
