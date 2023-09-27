#include<iostream>
#include<iomanip>
#include<vector>
#include<cctype>
#include<fstream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

const string fileName = "clients.txt";
const string delimiter = "#//#";

struct stClient {
	string AccountNo = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AccountBalance = 0.0;
	bool MarkForDelete = false;
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
vector<stClient> generateClientsList(string fileName) {
	vector<string> clientsLines = readClientsFromFile(fileName);
	vector<stClient> clientsList;
	for (string line : clientsLines) {
		stClient c;
		c = convertLineToRecord(line, delimiter);
		clientsList.push_back(c);
	}
	return clientsList;
}
void refreshClientsList(vector<stClient>& clients, string fileName) {
	clients = generateClientsList(fileName);
}
void rewriteClientsFile(string lines, string fileName) {
	fstream File;
	File.open(fileName, ios::out);
	if (File.is_open()) {
		File << lines;
		File.close();
	}
}
string convertRecordToLine(stClient clientData, string delimiter) {
	string dataOneLine = "";
	dataOneLine += clientData.AccountNo + delimiter;
	dataOneLine += clientData.PinCode + delimiter;
	dataOneLine += clientData.Name + delimiter;
	dataOneLine += clientData.Phone + delimiter;
	dataOneLine += to_string(clientData.AccountBalance);

	return dataOneLine;
}
string generateClientsLines(vector<stClient>& clients) {
	string lines = "";
	for (stClient& element : clients) {
		if (!element.MarkForDelete) {
			lines += convertRecordToLine(element, delimiter) + "\n";
		}
	}

	return lines;
}
void updateClientData(string AccountNo, vector<stClient>& clients) {
	for (stClient& element : clients) {
		if (element.AccountNo == AccountNo) {
			cout << "Please enter your Pin Code : ";
			getline(cin >> ws, element.PinCode);
			cout << "\n";

			element.Name = readText("Please enter your Name : ");
			cout << "\n";

			element.Phone = readText("Please enter your Phone : ");
			cout << "\n";

			element.AccountBalance = readFloatNumberMsg("Please enter your Account Balance : ");
			cout << "\n";

			return;
		}
	}
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
bool searchByAccountNo(string AccountNo, vector<stClient>& clients, stClient& client) {
	for (stClient& element : clients) {
		if (element.AccountNo == AccountNo) {
			client = element;
			return true;
		}
	}
	return false;
}
void updateClientByAccountNo(string AccountNo, vector<stClient>& clients) {
	stClient client;
	if (searchByAccountNo(AccountNo, clients, client)) {
		cout << "\nThe following are the client details :\n";
		printClient(client);
		if (doYouQuestion("\nAre you sure you want to update this client ? ")) {
			updateClientData(AccountNo, clients);
			rewriteClientsFile(generateClientsLines(clients), fileName);
			cout << "\nClient updated successfully.\n";
			refreshClientsList(clients, fileName);
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNo << ") Not Found\n";
	}
}

int main() {
	string AccountNo = readText("Please enter Account No. : ");
	vector<stClient> clients = generateClientsList(fileName);
	updateClientByAccountNo(AccountNo, clients);
	return 0;
}
