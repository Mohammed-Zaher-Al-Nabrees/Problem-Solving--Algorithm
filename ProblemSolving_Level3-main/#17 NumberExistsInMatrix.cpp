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
int main() {
	srand(time(NULL));
	int arr[rows][cols];// = { {1,0,0},{5,3,0},{0,0,0} };
	fill2DArrayRandomly(arr,rows,cols);
	print2DArrayElements(arr, rows, cols);
	if (IsExistsInMatrix(arr,rows, cols,readNumberMsg("Enter the number to search on it:")))
		cout << "It is Exists :) \n";
	else
		cout << "Not Found :(\n";
}
