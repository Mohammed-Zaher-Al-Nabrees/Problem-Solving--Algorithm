#include<iostream>
#include<iomanip>
#include "myLibrary.h"
using namespace std;
using namespace myLibrary;

void fill2DArrayRandomly(int arr[3][3]) {
	for (short row = 0; row < 3; row++)
		for (short j = 0; j < 3; j++) {
			arr[row][j] = generateRandomNumbers(-100, 102);
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
int rowSum(int arr[3][3], int &cols,short &currentRow) {
	int result = 0;
	for (short col = 0; col < cols; col++) {
		result += arr[currentRow][col];
	}
	return result;
}
void printSumMatrixRowElements(int arr[3][3], int rows, int cols) {
	for (short row = 0; row < rows; row++) {
		cout << "Row " << row + 1 << " Sum : " << setw(5) << rowSum(arr,cols,row) << "\n";
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];
	fill2DArrayRandomly(arr);
	cout << "The following is a 3 * 3 random matrix: \n";
	print2DArrayElements(arr);

	cout << "\n\n\nThe following are the sum of each row: \n";
	printSumMatrixRowElements(arr,3,3);
	return 0;
}
