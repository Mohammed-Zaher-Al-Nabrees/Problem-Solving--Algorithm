#include<iostream>
#include<iomanip>
#include <vector>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void readWordsIntoVector(vector<string>& words) {
	string word = readText("Enter your words ( ** for stop)");

	while (word != "**") {
		words.push_back(word);
		word = readText("");
	}
}
string join(vector<string>& words, string delimiter) {
	string result;
	for (string& word : words) {
		result = result + delimiter + word;
	}
	return result.substr(delimiter.length(), result.length() - 1);
}
int main() {
	//string s = readText("Please enter the statement :");
	vector<string> words;
	readWordsIntoVector(words);
	cout << "\nYour words after join them : \n" << join(words, readText("Enter the seperator you want ")) << endl;
}
