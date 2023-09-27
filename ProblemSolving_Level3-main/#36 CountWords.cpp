#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

short countWords(string& s) {
	char delimtor = ' ';
	short count = 0, slicer = 0;
	string word = "";
	s = s + delimtor;
	while (s.find(delimtor) != s.npos) {
		slicer = s.find(delimtor);
		word = s.substr(0, slicer);
		s = s.substr(slicer+1, s.length());
		if (word != "" && word !=" ")
			count++;
	}
	return count;
}
short countWordsPure(string& s) {
	short count = 0;
	s = s + " ";
	for (short i = 1; i < s.length();i++) {
		if (s[i] == ' ' && s[i - 1] != ' ')
			count++;
	}
	return count;
}
int main() {
	string s = readText("Please enter the statement :");
	cout << "# of words in your statement " << countWords(s);
}
