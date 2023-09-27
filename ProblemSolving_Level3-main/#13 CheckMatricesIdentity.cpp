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

void fill2DArrayIdentity(int arr[rows][cols], int rows, int cols) {
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
			if (row == col)
				arr[row][col] = 1;
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

bool checkMatricesIdentity(int arr[rows][cols], short rows, short cols) {
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			if ((row == col && arr[row][col] != 1) || (row != col && arr[row][col] != 0)) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	srand(time(NULL));

	int arr[rows][cols];
	
	//fill2DArrayIdentity(arr,rows, cols);
	fill2DArrayRandomly(arr, rows, cols);


	cout << "Matrix Elements: \n";
	print2DArrayElements(arr, rows, cols);

	cout << "\n\n";

	checkMatricesIdentity(arr, rows, cols) ?
		cout << "Yes : The Matrix is identity." :
		cout << "No : The Matrix is not identity.";

	cout << endl;
	//system("pause > 0");
}
