#include<iostream>
#include"myLibrary.h"
using namespace std;

enum randomOptions { smallLetter, capitalLetter, specialCharacter, digit };

int generateRandomNumbers(int from, int to) {
	//in main call 	srand(time(NULL));
	return rand() % (to - from + 1) + from;
}
void getRandomCharachter(randomOptions randomType) {
	switch (randomType) {
	case randomOptions::smallLetter:
		cout << char(generateRandomNumbers(int('a'), int('z')));
		break;
	case randomOptions::capitalLetter:
		cout << char(generateRandomNumbers(int('A'), int('Z')));
		break;
	case randomOptions::specialCharacter:
		cout << (char)generateRandomNumbers(int('Z') + 1, 128);
		break;
	case randomOptions::digit:
		cout << generateRandomNumbers(48, 57);
		break;
	}
}
int main() {
	srand(time(NULL));
	getRandomCharachter(randomOptions::smallLetter);
	getRandomCharachter(randomOptions::capitalLetter);
	getRandomCharachter(randomOptions::specialCharacter);
	getRandomCharachter(randomOptions::digit);
	return 0;
}
