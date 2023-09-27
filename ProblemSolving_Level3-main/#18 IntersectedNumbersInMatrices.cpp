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
bool IsExistsInMatrix(int arr[rows][cols], short rows, short cols, int target) {
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			if (target == arr[row][col]) return true;
		}
	}
	return false;
}
void printCommonElementsInTwoMatrices(int arr1[rows][cols],int arr2[rows][cols],int rows,int cols) {
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			if (IsExistsInMatrix(arr2,rows,cols,arr1[row][col])) cout<< arr1[row][col]<<"  ";
		}
	}
}
int main() {
	srand(time(NULL));
	int arr[rows][cols],arr2[rows][cols];
	fill2DArrayRandomly(arr,rows,cols);
	cout << "Matrix 1: \n";
	print2DArrayElements(arr, rows, cols);

	fill2DArrayRandomly(arr2, rows, cols);
	cout << "\n\n\nMatrix 2: \n";
	print2DArrayElements(arr2, rows, cols);

	cout << "\n\n\nCommon Elements: \n";
	printCommonElementsInTwoMatrices(arr, arr2, rows, cols);
	
}
