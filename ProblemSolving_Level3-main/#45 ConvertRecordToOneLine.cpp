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
	string dataOneLine="";
	dataOneLine+=customerData.AccountNo+delimiter;
	dataOneLine+=customerData.PinCode +delimiter;
	dataOneLine+=customerData.Name +delimiter;
	dataOneLine+=customerData.Phone +delimiter;
	dataOneLine += to_string(customerData.AccountBalance);

	return dataOneLine;
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
int main() {
	stCustomer c1;
	readCustomerData(c1);
	cout << "Customer Data in One Line :\n" << convertRecordToOneline(c1, "#//#");
	return 0;
}
