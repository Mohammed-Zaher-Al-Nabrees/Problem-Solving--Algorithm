#include<iostream>
#include<iomanip>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

vector<string> split(string& s, string delimiter = " ") {
	vector<string> words;
	short currentIndex = 0;
	string word = "";
	s = s + delimiter;
	while ((currentIndex = s.find(delimiter)) != s.npos) {
		word = s.substr(0, currentIndex);
		s.erase(0, currentIndex + delimiter.length());
		if (word != "" && word != delimiter)
			words.push_back(word);
	}
	return words;
}
void printWords(vector<string> words) {
	for (string word : words) {
		cout << word << "\n";
	}
}
int main() {
	string s = readText("Please enter the statement :");
	cout << "Words in your statement \n"; 
	printWords(split(s));
}
