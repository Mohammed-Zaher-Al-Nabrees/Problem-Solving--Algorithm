#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void lowercase(string &statement) {
	bool isFirstLetter = true;
	for (int i = 0;i < statement.length();i++) {
		if (isFirstLetter && statement[i] != ' ') {
			statement[i] = tolower(statement[i]);
		}
		isFirstLetter = (statement[i]==' '?true : false);
	}
}
int main() {
	string s = readText("Enter the whole statement ");
	lowercase(s);
	cout << "\n Lowercase String: \n"<<s<<"\n";
}
