
#include<iostream>
#include"myLibrary.h"
using namespace std;


string generateWord(randomOptions charType, int lettersCount) {
	string word = "";
	for (int i = 4;i != 0; i--) {
		word = word + getRandomCharachter(charType);
	}
	return word;
}
string generateKey(int wordsCount) {
	string key = "";
	for (int i = wordsCount;i != 0; i--) {
		key = key + generateWord(randomOptions::capitalLetter, 4);
		if (i != 1)
			key = key + "-";
	}
	return key;
}
void generateKeysInArray(string arr[], int &keyCount) {
	for (int i = 0; i < keyCount;i++) {
		 arr[i] = generateKey(4);
	}

}
void printStringArrayElements(string arr[], int& arrLength) {
	for (int i = 0;i < arrLength;i++) {
		cout << "Array ["<<i<<"] : " << arr[i] << "\n";
	}
	cout << "\n";
}
int main() {
	srand(time(NULL));
	string arr[100];
	int arrLength = readNumberMsg("Please enter the array size:\n");
	generateKeysInArray(arr, arrLength);
	cout << "Array Elements \n";
	printStringArrayElements(arr, arrLength);

	return 0;
}
