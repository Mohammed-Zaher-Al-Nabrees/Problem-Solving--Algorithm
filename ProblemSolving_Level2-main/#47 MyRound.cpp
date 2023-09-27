#include<iostream>
#include"myLibrary.h"
using namespace std;

float getDecimalPart(float num){
	return num - int(num);
}
float myRound(float num) {
	float result;
	int intPart = abs(num);
	float decimalPart = getDecimalPart(abs(num));

	if (decimalPart >= .5)
		result = intPart + 1;
	else
		result = intPart;
	if (num < 0) 
		return result * -1;
	else
		return result;
}
int main() {
	srand(time(NULL));
	float user_num = readFloatNumberMsg("Please enter any Number: ");
	cout << "My  Round : " << myRound(user_num) << "\n";
	cout << "C++ Round : " << round(user_num);
	return 0;
}
