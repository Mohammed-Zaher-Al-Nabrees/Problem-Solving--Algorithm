#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

const short rows = 3, cols = 3;

void fill2DArrayRandomly(int arr[rows][cols], int rows, int cols) {
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
			arr[row][col] = generateRandomNumbers(0, 1);
		}

}

void fill2DArrayScalar(int arr[rows][cols], int rows, int cols) {
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
			if (row == col)
				arr[row][col] = 9;
			else
				arr[row][col] = 0;
		}

}

void print2DArrayElements(int arr[rows][cols], short rows, short cols) {
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			printf("%d", arr[row][col]);
			cout << setw(4) << "   ";
		}
		cout << endl;
	}
}

bool checkMatricesScalar(int arr[rows][cols], short rows, short cols) {
	int diagonalNum = arr[0][0];
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			if ((row == col && arr[row][col] != diagonalNum) || (row != col && arr[row][col] != 0)) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	srand(time(NULL));
	int arr[rows][cols];
	fill2DArrayScalar(arr,rows,cols);
	print2DArrayElements(arr,rows,cols);
	checkMatricesScalar(arr, rows, cols) ? cout << "It's a scalar matrix \n" : cout << "It's not a scalar matrix\n";

}
