#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void printWords(string& s) {
	for (short i = 0; i < s.length();i++) {
		if (s[i] == ' ')
			cout << endl;
		else
			cout << s[i];
	}

}
int main() {
	string s = readText("Please enter the statement :");
	printWords(s);
}
