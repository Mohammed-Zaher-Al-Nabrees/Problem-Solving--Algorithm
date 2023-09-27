#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

bool isVowel(char& letter) {
	string vowels = "aeoui";
	letter = tolower(letter);
	return (vowels.find(letter) != vowels.npos) ? true : false;
}
bool isVowel_pure(char& letter) {
	letter = tolower(letter);
	return (letter =='a') || (letter =='e') || (letter =='i') || (letter == 'o') ||(letter == 'u');
}
int main() {
	char letter = readChar("Please enter the letter to check it :");
	if (isVowel(letter)) {//if (isVowel_pure(letter)) {
		cout << "\nYes,the Letter '" << letter << "' is vowel\n";
	}
	else {
		cout << "\nNo,the Letter '" << letter << "' is not a vowel\n";
	}

}
