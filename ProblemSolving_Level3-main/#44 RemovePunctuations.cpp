#include<iostream>
#include<iomanip>
#include <cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

string removePunctuations(string s) {
	string punc = ",;.:!?\"\'()", result = "";
	for (short i = 0;i < s.length();i++) {
		if (!ispunct(s[i]))  {
			result = result + s[i];
		}
	}
	return result;
}
int main() {
	string s = readText("Enter your statement : ");
	cout << "\nAfter remove punctuations : \n" << removePunctuations(s) << endl;
	cout<< endl;
	return 0;
}
