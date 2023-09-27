#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void uppercase(string &statement) {
	bool isFirstLetter = true;
	for (int i = 0;i < statement.length();i++) {
		if (isFirstLetter && statement[i] != ' ') {
			statement[i] = toupper(statement[i]);
		}
		isFirstLetter = (statement[i]==' '?true : false);
	}
}
int main() {
	string s = readText("Enter the whole statement ");
	uppercase(s);
	cout << "\nUppercase String: \n"<<s<<"\n";
}
