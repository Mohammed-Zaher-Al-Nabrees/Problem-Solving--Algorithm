#include<iostream>
#include"myLibrary.h"
using namespace std;

float getDecimalPart(float num) {
	return num - int(num);
}

int myCeil(float num) {
	if (num > 0 && getDecimalPart(abs(num)) > 0)
		return int(num) + 1;
	else
		return int(num);
}
int main() {
	srand(time(NULL));
	float user_num = readFloatNumberMsg("Please enter any Number: ");
	cout << "My  Ceil : " << myCeil(user_num) << "\n";
	cout << "C++ Ceil : " << ceil(user_num);
	return 0;
}
