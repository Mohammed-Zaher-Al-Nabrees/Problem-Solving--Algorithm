#include<iostream>
#include"myLibrary.h"
using namespace std;


int myAbs(int num) {
	if (num < 0)
		return num * -1;
	else
		return num;
}
int main() {
	srand(time(NULL));
	int user_num = readNumberMsg("Please enter any Number: ");
	cout << "My Abs : " << myAbs(user_num)<<"\n";
	cout << "C++ Abs : " << abs(user_num);
	return 0;
}
