#include<iostream>
#include<iomanip>
#include "myLibrary.h"
using namespace std;
using namespace myLibrary;

void fill2DArrayRandomly(int arr[3][3]) {
	for (short row = 0; row < 3; row++)
		for (short j = 0; j < 3; j++) {
			arr[row][j] = generateRandomNumbers(0, 20);
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
void printSumMatrixColElements(int arr[3][3], int rows, int cols) {
	for (short col = 0; col < cols; col++) {
		cout << "Column " << col + 1 << " Sum : " << setw(5) << colSum(arr, rows, col) << "\n";
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];
	fill2DArrayRandomly(arr);
	cout << "The following is a 3 * 3 random matrix: \n";
	print2DArrayElements(arr);

	cout << "\n\n\nThe following are the sum of each column: \n";
	printSumMatrixColElements(arr, 3, 3);
	system("pause > 0");
}
