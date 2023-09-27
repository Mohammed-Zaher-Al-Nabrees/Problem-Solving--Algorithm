#include<iostream>
#include<iomanip>
#include "myLibrary.h"
using namespace std;
using namespace myLibrary;

void fill2DArrayRandomly(int arr[3][3]) {
	for (short row = 0; row < 3; row++)
		for (short j = 0; j < 3; j++) {
			arr[row][j] = generateRandomNumbers(0, 10);
		}

}
void print2DArrayElements(int arr[3][3]) {
	for (short row = 0; row < 3; row++) {
		for (short j = 0; j < 3; j++) {
			cout << setw(3) << arr[row][j] << "   ";
		}
		cout << endl;
	}
}
int colSum(int arr[3][3], int rows, short& currentcol) {
	int result = 0;
	for (short row = 0; row < rows; row++) {
		result += arr[row][currentcol];
	}
	return result;
}
void sumMatrixColElements(int arr[3][3], int result[], int rows, int cols) {
	for (short col = 0; col < cols; col++) {
		result[col] = colSum(arr, rows, col);

	}
}
void printArrayElements(int arr[], int arrLength) {
	for (short col = 0; col < arrLength; col++) {
		cout << "Col " << col + 1 << " Sum : " << setw(5) << arr[col] << "\n";
	}
	cout << endl;
}

int main() {
	srand((unsigned)time(NULL));

	const int rows = 3, cols = 3;
	int arr[rows][cols];
	int sumCols[cols];
	fill2DArrayRandomly(arr);
	cout << "The following is a " << rows << " * " << cols << " random matrix: \n";
	print2DArrayElements(arr);

	sumMatrixColElements(arr, sumCols, rows, cols);
	cout << "\n\nThe following are the sum of each col: \n";
	printArrayElements(sumCols, cols);
	system("pause > 0");
}
