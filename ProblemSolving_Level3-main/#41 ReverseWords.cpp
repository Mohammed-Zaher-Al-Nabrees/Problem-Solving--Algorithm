#include<iostream>
#include<iomanip>
#include <vector>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

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
string join(vector<string>& words, string delimiter = " ") {
	string result;
	for (string& word : words) {
		result = result + delimiter + word;
	}
	return result.substr(delimiter.length(), result.length() - 1);
}
string reverseString(string &s) {
	vector<string>words;
	words = split(s);
	short counter = 0, reverseCounter = words.size() - 1;
	string temp;
	for (;counter < reverseCounter;counter++, reverseCounter--) {
		temp = words.at(counter);
		words.at(counter) = words.at(reverseCounter);
		words.at(reverseCounter) = temp;
	}
	return join(words, " ");
}
int main() {
	string s = readText("Enter your statement to reverse it : ");
	cout << "Your statement in reverse order: \n";
	cout << reverseString(s);

	system("pause > 0");
}
