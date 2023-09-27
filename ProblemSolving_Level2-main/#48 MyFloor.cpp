#include<iostream>
#include"myLibrary.h"
using namespace std;

float getDecimalPart(float num) {
	return num - int(num);
}

int myFloor(float num) {
	if (num < 0 && getDecimalPart(abs(num)) > 0)
		return int(num) - 1;
	else
		return int(num);
}

int main() {
	srand(time(NULL));
	float user_num = readFloatNumberMsg("Please enter any Number: ");
	cout << "My  Floor : " << myFloor(user_num) << "\n";
	cout << "C++ Floor : " << floor(user_num);
	return 0;
}
