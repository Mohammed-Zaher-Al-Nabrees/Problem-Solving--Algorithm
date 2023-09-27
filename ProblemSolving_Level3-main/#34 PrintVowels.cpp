#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

bool isVowel(char& letter) {
	letter = tolower(letter);
	return (letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u');
}
void printVowels(string& s) {
	for (short i = 0; i < s.length();i++) {
		if (isVowel(s[i])) cout<<setw(3)<<s[i];
	}

}
int main() {
	string s = readText("Please enter the statement to print the vowels in it:");
	printVowels(s);
}
