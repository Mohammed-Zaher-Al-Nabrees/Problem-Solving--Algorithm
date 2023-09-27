#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void capitalization(string &statement) {
	for (int i = 0;i < statement.length();i++) {
		if (statement[i] != ' ') {
			statement[i] = toupper(statement[i]);
		}
	}
}
void smallization(string& statement) {
	for (int i = 0;i < statement.length();i++) {
		if (statement[i] != ' ') {
			statement[i] = tolower(statement[i]);
		}
	}
}
int main() {
	string s = readText("Enter the whole statement ");
	capitalization(s);
	cout << "\n String after capitalization : \n"<<s<<"\n";
	smallization(s);
	cout << "\n String after smallization : \n" << s << "\n";
}
