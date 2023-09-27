#include <iostream>
#include "myLibrary.h"
using namespace std;

void guessThePassword(string password) {
	string temp = "";
	int attemp = 0;
	for (int i = 65; i <= 90;i++) {
		for (int j = 65; j <= 90;j++)
		{
			for (int c = 65; c <= 90;c++) {
				temp = "";
				attemp++;
				temp = temp + char(i);
				temp = temp + char(j);
				temp = temp + char(c);
				if(temp == password){
					cout << "The Password is ("<<temp << ")\n";
					cout << "Found after " << attemp << " trail(s)"<<endl;
					return;
				}

			}
		}
	}
	cout << "Couldn't found" << endl;
}
int main() {
	guessThePassword(readPassword());
	return 0;
}
