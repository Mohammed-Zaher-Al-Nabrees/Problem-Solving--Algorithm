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
		for (short col = 0; col < rows; col++) {
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
int findMinimumNumberInMatrix(int arr[rows][cols], int rows, int cols) {
	int min = arr[0][0];
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			if (arr[row][col] < min)min = arr[row][col];
		}
	}
	return min;
}
int findMaximumNumberInMatrix(int arr[rows][cols], int rows, int cols) {
	int max = arr[0][0];
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			if (arr[row][col] > max)max = arr[row][col];
		}
	}
	return max;
}
int main() {
	srand(time(NULL));
	int arr[rows][cols];// = { {1,0,0},{5,3,0},{0,0,0} };
	fill2DArrayRandomly(arr, rows, cols);
	cout << "Matrix 1: \n";
	print2DArrayElements(arr, rows, cols);


	cout << "\n\nMinimum Number In Matrix: ";
	cout << setw(3) ;
	printf("%0*d", 2, findMinimumNumberInMatrix(arr, rows, cols));

	cout << "\n\nMaximum Number In Matrix: ";
	cout << setw(3);
	printf("%0*d", 2, findMaximumNumberInMatrix(arr, rows, cols));
	cout << endl;
}
