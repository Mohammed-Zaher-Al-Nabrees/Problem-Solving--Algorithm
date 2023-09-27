#include<iostream>
#include<iomanip>
#include<vector>
#include<cctype>
#include<fstream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

struct stClient {
	string AccountNo = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AccountBalance = 0.0;
};
string convertRecordToOneline(stClient clientData, string delimiter) {
	string dataOneLine = "";
	dataOneLine += clientData.AccountNo + delimiter;
	dataOneLine += clientData.PinCode + delimiter;
	dataOneLine += clientData.Name + delimiter;
	dataOneLine += clientData.Phone + delimiter;
	dataOneLine += to_string(clientData.AccountBalance);

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
stClient convertLineToRecord(string clientData, string delimiter) {
	stClient client;
	short counter = 0;
	vector<string>vClient = split(clientData, delimiter);
	client.AccountNo = vClient.at(0);
	client.PinCode = vClient.at(1);
	client.Name = vClient.at(2);
	client.Phone = vClient.at(3);
	client.AccountBalance = stof(vClient.at(4));

	return client;
}
void readClientData(stClient& c) {
	cout << "Please enter your Account No. : ";
	getline(cin >> ws, c.AccountNo);
	cout << "\n";

	c.PinCode = readText("Please enter your Pin Code : ");
	cout << "\n";

	c.Name = readText("Please enter your Name : ");
	cout << "\n";

	c.Phone = readText("Please enter your Phone : ");
	cout << "\n";

	c.AccountBalance = readFloatNumberMsg("Please enter your Account Balance : ");
	cout << "\n";
}
void printClient(stClient& c) {
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
void addClientToFile(string data, string file) {
	fstream File;
	File.open(file, ios::out | ios::app);
	if (File.is_open()) {
		File << data;
		File << "\n";
		File.close();
	}
}
void enterClients() {
	string data = "";
	do {
		system("cls");
		stClient c;
		readClientData(c);
		data = convertRecordToOneline(c, "#//#");
		try {
			addClientToFile(data, "clients.txt");
		}
		catch (exception e) {
			cout << "The client have not added to the file \n" << e.what();
		}

	} while (doYouQuestion("Do you want to add more ?"));

}
int main() {
	enterClients();
	return 0;
}
