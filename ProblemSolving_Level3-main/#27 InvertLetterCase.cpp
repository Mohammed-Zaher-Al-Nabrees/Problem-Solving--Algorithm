#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void invertCaseLetter(char &letter) {
	if (islower(letter))
		letter = toupper(letter);
	else
		letter = tolower(letter);
}
int main() {
	string s = readText("Enter the letter to invert : ");
	char letter = s[0];
	invertCaseLetter(letter);
	cout << "\nLetter After Invert : \n"<<letter<<"\n";
}
