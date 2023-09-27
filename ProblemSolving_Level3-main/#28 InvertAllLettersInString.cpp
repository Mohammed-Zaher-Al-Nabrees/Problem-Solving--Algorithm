#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

char invertCaseLetter(char letter) {
	if (islower(letter))
		letter = toupper(letter);
	else
		letter = tolower(letter);

	return letter;
}
void invertAllLetters(string& s) {
	for(int i = 0;i < s.length();i++) {
		s[i]= invertCaseLetter(s[i]);
	}
}
int main() {
	string s = readText("Enter the letter to invert : ");
	invertAllLetters(s);
	cout << "\nStatement After Invert : \n"<<s<<"\n";
}
