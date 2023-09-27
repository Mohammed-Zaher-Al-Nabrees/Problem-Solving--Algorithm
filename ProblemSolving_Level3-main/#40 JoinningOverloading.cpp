#include<iostream>
#include<iomanip>
#include <vector>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void readWords(vector<string>& words) {
	string word = readText("Enter your words ( ** for stop)");
	while (word != "**") {
		words.push_back(word);
		word = readText("");
	}
}
void readWords(string words[], short& length) {
	string word = readText("Enter your words ( ** for stop)");
	short i = 0;
	for (;i < length && word != "**";i++) {
		words[i] = word;
		word = readText("");
	}
	length = i + 1;
}
string join(vector<string>& words, string delimiter) {
	string result;
	for (string& word : words) {
		result = result + delimiter + word;
	}
	return result.substr(delimiter.length(), result.length() - 1);
}
string join(string words[], short& length, string delimiter = " ") {
	string result;
	for (short i = 0;i < length - 1;i++) {
		result = result + delimiter + words[i];
	}
	return result.substr(delimiter.length(), result.length() - 1);
}
int main() {
	const short length = 100;
	short actualLength = length;
	string words[length];
	readWords(words, actualLength);
	cout << "actualLength " << actualLength << endl;
	cout << "\nYour words after join them : \n" << join(words, actualLength, readText("Enter the seperator you want ")) << endl;
}
