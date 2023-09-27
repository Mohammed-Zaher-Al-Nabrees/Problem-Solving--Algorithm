#include<iostream>
#include<iomanip>
using namespace std;
const short rows = 3, cols = 3;

void fillOrdered2DArray(int arr[rows][cols], short rows, short cols) {
	short counter = 1;
	for (short row = 0; row < rows; row++)
		for (short col = 0; col < cols; col++) {
			arr[row][col] = counter;
			counter++;
		}

}
void transposeMatrix(int original[rows][cols], int result[rows][cols], short rows, short cols) {
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			result[col][row] = original[row][col];
		}
	}

}
void print2DArrayElements(int arr[rows][cols], short rows, short cols) {
	for (short row = 0; row < rows; row++) {
		for (short col = 0; col < cols; col++) {
			cout << setw(3) << arr[row][col] << "   ";
		}
		cout << endl;
	}
}

int main() {
	int arr[rows][cols], transposedArr[rows][cols];
	fillOrdered2DArray(arr,rows,cols);
	cout << "The following is a " << rows << " * " << cols << " ordered matrix: \n";
	print2DArrayElements(arr,rows,cols);

	transposeMatrix(arr,transposedArr,rows,cols);

	cout << "\n\nThe following is a " << rows << " * " << cols << " transposed matrix: \n";
	print2DArrayElements(transposedArr,rows,cols);
	return 0;
	//system("pause > 0");
}
