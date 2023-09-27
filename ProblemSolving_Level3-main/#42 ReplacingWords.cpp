#include<iostream>
#include<iomanip>
#include <vector>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

void replace(string& fullStatement,string oldPart,string newPart) {
	short fromIndex = fullStatement.find(oldPart);
	fullStatement.erase(fromIndex, oldPart.length());
	fullStatement.insert(fromIndex,newPart);
}
void replaceBuildIn(string& fullStatement, string oldPart, string newPart) {
	short fromIndex = fullStatement.find(oldPart);
	fullStatement = fullStatement.replace(fromIndex, oldPart.length(),newPart);
}

int main() {
	string s = "This is world of text";//readText("Enter your statement to reverse it : ");
	cout << "Before Replace : " << s << endl;
	replaceBuildIn(s,"world","word");
	cout << "After Replace : " << s << endl;
	system("pause > 0");
	return 0;
}
