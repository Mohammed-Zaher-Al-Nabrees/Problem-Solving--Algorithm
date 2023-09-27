#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;
void capitalization(string& statement) {
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
short countSpecificLetter(string& s, char& target) {
	short count = 0;
	for (short i = 0;i < s.length();i++) {
		if (target == s[i]) count++;
	}
	return count;
}
int main() {
	string s = readText("Enter your statement  : ");
	char letter = readChar("Enter the letter to count it:");
	if (!doYouQuestion("Do you want case sensitive counter ?"))
	{
		if (islower(letter))
			smallization(s);
		else
			capitalization(s);

	}
	cout << "\nThe Letter '" << letter << "' Count = " << countSpecificLetter(s, letter) << "\n";

}
