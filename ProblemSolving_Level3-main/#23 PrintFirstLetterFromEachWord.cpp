#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void findWordFirstLetter(string statement) {
	bool isFirstLetter = true;
	for (int i = 0;i < statement.length();i++) {
		if (isFirstLetter && statement[i] != ' ') {
			cout << statement[i]<<"\n";
		}
		isFirstLetter = (statement[i]==' '?true : false);
	}
}
int main() {
	findWordFirstLetter(readText("enter the whole statement "));
}
