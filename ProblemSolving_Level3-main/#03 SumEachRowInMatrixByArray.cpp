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
int rowSum(int arr[3][3], int cols, short& currentRow) {
	int result = 0;
	for (short col = 0; col < cols; col++) {
		result += arr[currentRow][col];
	}
	return result;
}
void sumMatrixRowElements(int arr[3][3], int result[],int rows,int cols) {
	for (short row = 0; row < rows; row++) {
		result[row] = rowSum(arr,cols,row);

	}
}
void printArrayElements(int arr[],int arrLength) {
	for (short row = 0; row < arrLength; row++) {
		cout << "Row "<<row + 1<< " Sum : " << setw(5) << arr[row] << "\n";
	}
	cout << endl;
}
int main() {
	srand((unsigned)time(NULL));
	const int rows = 3, cols = 3;
	int arr[rows][cols];
	int sumRows[rows];
	fill2DArrayRandomly(arr);
	cout << "The following is a "<<rows<<" * "<<cols<<" random matrix: \n";
	print2DArrayElements(arr);

	sumMatrixRowElements(arr, sumRows,rows,cols);
	cout << "\n\nThe following are the sum of each row: \n";
	printArrayElements(sumRows,rows);
	return 0;
}
