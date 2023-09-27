#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

const short rows = 3, cols = 3;

void fill2DArrayRandomly(int arr[rows][cols], int rows, int cols) {
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
			arr[row][col] = generateRandomNumbers(1, 10);
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

void multiplication2Arrays(int arr1[rows][cols], int arr2[rows][cols], int result[rows][cols], short rows, short cols) {
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
			result[row][col] = arr1[row][col]*arr2[row][col];
		}

}

int main() {
	int arr1[rows][cols], arr2[rows][cols], multiplied[rows][cols];
	fill2DArrayRandomly(arr1, rows, cols);
	fill2DArrayRandomly(arr2, rows, cols);
	
	cout << "Matrix 1: \n";
	print2DArrayElements(arr1, rows, cols);
	cout << "\n\nMatrix 2: \n";
	print2DArrayElements(arr2, rows, cols);

	multiplication2Arrays(arr1,arr2,multiplied,rows,cols);

	cout << "\n\nResults of multiplication: \n";
	print2DArrayElements(multiplied, rows, cols);

	//system("pause > 0");
}
