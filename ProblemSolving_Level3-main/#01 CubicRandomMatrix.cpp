#include<iostream>
#include<iomanip>
#include "myLibrary.h"
using namespace std;
using namespace myLibrary;

void fill2DArrayRandomly(int arr[3][3]) {
	for (short i = 0; i < 3; i++)
		for (short j = 0; j < 3; j++) {
			arr[i][j] = generateRandomNumbers(-100, 102);
		}

}
void print2DArrayElements(int arr[3][3]) {
	cout << "The following is a 3 * 3 random matrix: \n";
	for (short i = 0; i < 3; i++) {
		for (short j = 0; j < 3; j++) {
			cout <<setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];
	fill2DArrayRandomly(arr);
	print2DArrayElements(arr);

	return 0;
}
