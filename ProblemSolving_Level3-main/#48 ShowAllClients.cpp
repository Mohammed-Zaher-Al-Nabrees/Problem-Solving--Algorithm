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
string tabsGenerator(short total = 0) {
	string tabs = "";
	while (total != 0) {
		tabs += " ";
		total--;
	}
	return tabs;
}
string lineGenerator(short total = 0) {
	string line = "";
	while (total != 0) {
		line += "_";
		total--;
	}
	return line;
}
void printColumn(string content,int width){
	cout << left << "| " << setw(width) <<content;
}
void printHeader(int clientsTotal = 0) {
	cout << setw(50) << tabsGenerator(25) << "Clients List (" << clientsTotal << ") Clients \n";
	cout << lineGenerator(115)<<" \n";
	printColumn("Account Number" , 20);
	printColumn("Pin Code" , 15);
	printColumn("Client Name" , 35);
	printColumn("Phone" , 15);
	printColumn("Balance" , 15);
	cout << "\n";
	cout << lineGenerator(115)<<" \n";
	cout << "\n";
}
void printClient(stClient& c) {
	printColumn(c.AccountNo, 20);
	printColumn(c.PinCode, 15);
	printColumn(c.Name, 35);
	printColumn(c.Phone, 15);
	printColumn(to_string(c.AccountBalance), 15);
	cout << "\n";
}
void showClients() {
	vector<string> clientsLines = readClientsFromFile(fileName);
	printHeader(clientsLines.size());
	for (string line : clientsLines) {
		stClient c;
		c = convertLineToRecord(line, "#//#");
		printClient(c);
	}
	cout << lineGenerator(115) << " \n";
}

int main() {
	showClients();
	return 0;
}
