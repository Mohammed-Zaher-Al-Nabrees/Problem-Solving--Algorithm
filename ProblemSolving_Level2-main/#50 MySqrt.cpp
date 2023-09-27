
#include<iostream>
#include"myLibrary.h"
using namespace std;


float mySqrt(float num) {
		return pow(num,0.5);
}
int main() {
	srand(time(NULL));
	float user_num = readFloatNumberMsg("Please enter any Number: ");
	cout << "My  Sqrt : " << mySqrt(user_num) << "\n";
	cout << "C++ Sqrt : " << sqrt(user_num);
	return 0;
}
