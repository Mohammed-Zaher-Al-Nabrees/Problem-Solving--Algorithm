#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void trimRight(string& s) {
	for (short i = s.length() - 1;i >= 0;i--) {
		if (s[i] != ' ') {
			s = s.substr(0, i + 1);
			break;
		}
	}
}
void trimLeft(string& s) {
	for (short i = 0;i < s.length();i++) {
		if (s[i] != ' ') {
			s = s.substr(i, s.length() - 1);
			break;
		}
	}
}
void trim(string &s) {
	trimLeft(s);
	trimRight(s);
}
int main() {
	string s = readText("Please enter the statement :");
	trim(s);
	cout << "Your statement after trim : \n" << "-" << s <<"-" << endl;
}
