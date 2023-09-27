#include<iostream>
#include<cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

enum enWhatToCount { All = 0, Lowercase = 1, Uppercase = 2 };

short countLetters(string& s, enWhatToCount WhatToCount = enWhatToCount::All) {
	short count = 0;
	if (WhatToCount == enWhatToCount::All)
		count = s.length();
	else
		if (WhatToCount == enWhatToCount::Lowercase)
			for (short i = 0;i < s.length();i++) {
				if (islower(s[i])) count++;
			}
		else
			for (short i = 0;i < s.length();i++) {
				if (isupper(s[i])) count++;
			}
	return count;
}
int main() {
	string s = readText("Enter your statement  : ");
	cout << "\nString Length : \n" << countLetters(s, enWhatToCount::All) << "\n";
	cout << "\nCount Lowercase Letters : \n" << countLetters(s, enWhatToCount::Lowercase) << "\n";
	cout << "\nCount Uppercase Letters : \n" << countLetters(s, enWhatToCount::Uppercase) << "\n";
}
