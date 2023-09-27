#include<iostream>
using namespace std;



void printAllWordsFromAAAtoZZZ() {
	for (int i = int('A'); i <= int('Z');i++) {
		for (int j = int('A'); j <= int('Z');j++)
		{
			for (int c = int('A'); c <= int('Z');c++)
				cout << (char)(i) << char(j) << char(c) << "-";
			cout << "\n";
		}
	
		cout << "\n";
	}
}
int main() {
	printAllWordsFromAAAtoZZZ();
	return 0;
}
