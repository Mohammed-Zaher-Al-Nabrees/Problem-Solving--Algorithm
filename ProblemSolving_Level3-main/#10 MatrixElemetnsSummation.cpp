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

int sumOfMatrix(int arr[rows][cols], short rows, short cols) {
	int sum = 0;
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
		sum = sum + arr[row][col];
	}
	return sum;
}
int main() {
	int arr[rows][cols];
	fill2DArrayRandomly(arr, rows, cols);
	
	cout << "Matrix : \n";
	print2DArrayElements(arr, rows, cols);
	
	cout << "\n\nSummation of matrix elements: ";
	printf(" %0*d ",2,sumOfMatrix(arr,rows,cols));

	cout << endl;
	//system("pause > 0");
}
