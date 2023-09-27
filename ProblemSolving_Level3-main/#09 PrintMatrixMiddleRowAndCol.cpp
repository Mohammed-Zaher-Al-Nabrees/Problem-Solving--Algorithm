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
void printMiddleMatrixRow(int arr[rows][cols], short rows, short cols) {
	short mid = rows / 2;
	for (short col = 0; col < cols; col++)
	{
		printf("%0*d", 2, arr[mid][col]);
		cout << setw(4) << "   ";
	}
}
void printMiddleMatrixCol(int arr[rows][cols], short rows, short cols) {
	short mid = cols / 2;
	for (short row = 0;row < rows; row++)
	{
		printf("%0*d", 2, arr[row][mid]);
		cout << setw(4) << "   ";
	}
}
int main() {
	int arr[rows][cols];
	fill2DArrayRandomly(arr, rows, cols);
	
	cout << "Matrix : \n";
	print2DArrayElements(arr, rows, cols);
	
	cout << "\n\nMiddle row of matrix: \n";
	printMiddleMatrixRow(arr, rows, cols);

	cout << "\n\nMiddle row of matrix: \n";
	printMiddleMatrixCol(arr, rows, cols);

	cout << endl;
	//system("pause > 0");
}
