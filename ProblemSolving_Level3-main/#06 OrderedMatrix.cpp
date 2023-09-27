#include<iostream>
#include<iomanip>
using namespace std;

void fill2DArray(int arr[3][3]) {
	short counter = 1;
	for (short row = 0; row < 3; row++)
		for (short col = 0; col < 3; col++) {
			arr[row][col] = counter;
			counter++;
		}

}
void print2DArrayElements(int arr[3][3]) {
	for (short row = 0; row < 3; row++) {
		for (short j = 0; j < 3; j++) {
			cout << setw(3) << arr[row][j] << "   ";
		}
		cout << endl;
	}
}

int main() {
	int arr[3][3];
	fill2DArray(arr);
	cout << "The following is a 3 * 3 ordered matrix: \n";
	print2DArrayElements(arr);

	system("pause > 0");
}
