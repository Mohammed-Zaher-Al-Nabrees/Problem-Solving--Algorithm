#include<iostream>
#include"myLibrary.h"
using namespace std;



string encrypt(string word, short key) {
	string encrypted = "";
	for (int i = 0; i < word.length();i++) {
		encrypted = encrypted + char(int(word[i]) + key);
	}
	return encrypted;
}
string decrypt(string word, short key) {
	string decrypted = "";
	for (int i = 0; i < word.length();i++) {
		decrypted = decrypted + char(int(word[i]) - key);
	}
	return decrypted;
}
int main() {
	srand(time(NULL));
	short key = rand() + 1;
	cout << " key " << key << endl;
	string original = readText("Please enter a string to encrypt: ");
	cout << "Text Before Encrypt " << original << "\n";
	string encrypted = encrypt(original, key);
	cout << "Text After Encrypt " << encrypted << "\n";
	string decrypted = decrypt(encrypted, key);
	cout << "Text After Decrypt " << decrypted << "\n";
	return 0;
}
