#include<iostream>
#include"myLibrary.h"
using namespace std;

//Format of Key : ABCD-EFGH-IJKL-MNOP
enum randomOptions { smallLetter, capitalLetter, specialCharacter, digit };

char getRandomCharachter(randomOptions randomType) {
	switch (randomType) {
	case randomOptions::smallLetter:
		return char(generateRandomNumbers(int('a'), int('z')));
		break;
	case randomOptions::capitalLetter:
		return char(generateRandomNumbers(int('A'), int('Z')));
		break;
	case randomOptions::specialCharacter:
		return (char)generateRandomNumbers(int('Z') + 1, 128);
		break;
	case randomOptions::digit:
		return (char)generateRandomNumbers(48, 57);
		break;
	}
}
string generateWord(randomOptions charType,int lettersCount) {
	string word = "";
	for (int i = 4;i != 0; i--) {
		word = word + getRandomCharachter(charType);
	}
	return word;
}
string generateKey(int wordsCount) {
	string key = "";
	for (int i = wordsCount;i != 0; i--) {
		key = key + generateWord(randomOptions::capitalLetter,4);
		if (i != 1)
			key = key + "-";
	}
	return key;
}
void generateKeys(int keyCount) {
	for (int i = 0; i < keyCount;i++) {
		cout << "Key[" << i+1 << "]: " << generateKey(4) << "\n";
	}

}
int main() {
	srand(time(NULL));
	generateKeys(readPositiveNumber());
	return 0;
}
