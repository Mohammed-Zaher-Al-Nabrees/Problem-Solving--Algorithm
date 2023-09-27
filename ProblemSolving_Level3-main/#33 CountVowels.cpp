#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

bool isVowel(char& letter) {
	letter = tolower(letter);
	return (letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u');
}
short countVowels(string& s) {
	short count = 0;
	for (short i = 0; i < s.length();i++) {
		if (isVowel(s[i])) count++;
	}
	return count;

}
int main() {
	string s = readText("Please enter the statement to count the vowels in it:");
	cout << "\nYou have " << countVowels(s) << " vowel(s)\n";
}
