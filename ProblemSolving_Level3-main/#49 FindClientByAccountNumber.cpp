#include<iostream>
#include<iomanip>
#include<vector>
#include<cctype>
#include<fstream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

const string fileName = "clients.txt";

struct stClient {
	string AccountNo = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AccountBalance = 0.0;
};
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
vector<string> readClientsFromFile(string fileName) {
	fstream File;
	vector<string> clientsLines;
	File.open(fileName, ios::in);
	if (File.is_open()) {
		string line = "";
		while (getline(File, line)) {
			clientsLines.push_back(line);
		};
		File.close();
	}
	return clientsLines;
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
vector<stClient> generateClientsList(string fileName) {
	vector<string> clientsLines = readClientsFromFile(fileName);
	vector<stClient> clientsList;
	for (string line : clientsLines) {
		stClient c;
		c = convertLineToRecord(line, "#//#");
		clientsList.push_back(c);
	}
	return clientsList;
}
bool searchByAccountNo(string AccountNo, stClient& client) {
	vector<stClient> clients = generateClientsList(fileName);
	for (stClient element : clients) {
		if (element.AccountNo == AccountNo) {
			client = element;
			return true;
		}
	}
	return false;
}
int main() {
	stClient client;
	string AccountNo = readText("Please enter Account No. : ");
	if (searchByAccountNo(AccountNo, client)) {
		cout << "\nThe following are the client details :\n";
		printClient(client);
	}
	else {
		cout << "\nClient with Account Number (" << AccountNo << ") Not Found\n";
	}
	return 0;
}
