#include<iostream>
#include<iomanip>
#include <vector>
#include <cctype>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

struct stCustomer {
	string AccountNo = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AccountBalance = 0.0;
};
string convertRecordToOneline(stCustomer customerData, string delimiter) {
	string dataOneLine = "";
	dataOneLine += customerData.AccountNo + delimiter;
	dataOneLine += customerData.PinCode + delimiter;
	dataOneLine += customerData.Name + delimiter;
	dataOneLine += customerData.Phone + delimiter;
	dataOneLine += to_string(customerData.AccountBalance);

	return dataOneLine;
}
vector<string> split(string& s, string delimiter = " ") {
	vector<string> words;
	short currentIndex = 0;
	string word = "";
	s = s + delimiter;
	while ((currentIndex = s.find(delimiter)) != s.npos) {
		word = s.substr(0, currentIndex);
		s.erase(0, currentIndex + delimiter.length());
		if (word != "" && word != delimiter)
			words.push_back(word);
	}
	return words;
}
stCustomer convertLineToRecord(string customerData, string delimiter) {
	stCustomer customer;
	short counter = 0;
	vector<string>vCustomer = split(customerData, delimiter);
	customer.AccountNo = vCustomer.at(0);
	customer.PinCode = vCustomer.at(1);
	customer.Name = vCustomer.at(2);
	customer.Phone = vCustomer.at(3);
	customer.AccountBalance = stof(vCustomer.at(4));

	return customer;
}
void readCustomerData(stCustomer& c) {
	c.AccountNo = readText("Please enter your Account No. : ");
	cout << "\n";

	c.PinCode = readText("Please enter your Pin Code  : ");
	cout << "\n";

	c.Name = readText("Please enter your Name : ");
	cout << "\n";

	c.Phone = readText("Please enter your Phone : ");
	cout << "\n";

	c.AccountBalance = readFloatNumberMsg("Please enter your Account Balance : ");
	cout << "\n";
}
void printCustomer(stCustomer& c) {
	cout << "Account No.     : " << c.AccountNo;
	cout << "\n";
	cout << "Pin Code        : " << c.PinCode;
	cout << "\n";
	cout << "Name            : " << c.Name;
	cout << "\n";
	cout << "Phone           : " << c.Phone;
	cout << "\n";
	cout << "Account Balance : " << c.AccountBalance;
	cout << "\n";
}
int main() {
	stCustomer c1;
	string delimiter = "#//#";
	readCustomerData(c1);
	string data = convertRecordToOneline(c1, delimiter);
	cout << "Customer Data in One Line :\n" << data;
	stCustomer c2 = convertLineToRecord(data, delimiter);
	cout << "\n--------------------------------\nCustomer 2 : \n";
	printCustomer(c2);
	return 0;
}
