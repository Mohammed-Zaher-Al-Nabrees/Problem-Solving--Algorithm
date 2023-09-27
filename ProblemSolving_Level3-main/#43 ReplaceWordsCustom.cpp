#include<iostream>
#include<iomanip>
#include <vector>
#include <cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

string smallization(string statement) {
	for (int i = 0;i < statement.length();i++) {
		if (statement[i] != ' ') {
			statement[i] = tolower(statement[i]);
		}
	}
	return statement;
}
string join(vector<string>& words, string delimiter) {
	string result;
	for (string& word : words) {
		result = result + delimiter + word;
	}
	return result.substr(delimiter.length(), result.length() - 1);
}
vector<string> split(string& s, string delimtor = " ") {
	vector<string> words;
	short slicer = 0;
	string word = "";
	s = s + delimtor;
	while ((slicer = s.find(delimtor)) != s.npos) {
		word = s.substr(0, slicer);
		s = s.substr(slicer + 1, s.length());
		if (word != "" && word != delimtor)
			words.push_back(word);
	}
	return words;
}
void replace(string& fullStatement, string oldPart, string newPart, bool caseSensitive = true) {
	vector <string> words = split(fullStatement, " ");
	for (string word : words) {
		if (caseSensitive && word == oldPart) {
			word = newPart;
		}
		else if (!caseSensitive) {
			if (smallization(word) == smallization(oldPart))
				word = newPart;
		}

	}
	fullStatement = join(words," ");
}
void replaceBuildIn(string& fullStatement, string oldPart, string newPart) {
	short fromIndex = fullStatement.find(oldPart);
	fullStatement = fullStatement.replace(fromIndex, oldPart.length(), newPart);
}
int main() {
	string s = readText("Enter your statement : ");
	string oldPart = readText("Enter old part : ");
	string newPart = readText("Enter new part : ");
	replace(s, oldPart, newPart, doYouQuestion("With case sensitive?"));
	cout << "\nAfter Replace : \n" << s << endl;
	system("pause > 0");
	return 0;
}
