#include<iostream>
#include<iomanip>
#include<vector>
#include<cctype>
#include<fstream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

struct stClient {
	string accountNo = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AccountBalance = 0.0;
	bool MarkForDelete = false;
};
enum enMenuOptions { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Exit = 6 };

const string fileName = "clients.txt";
const string delimiter = "#//#";

void goBackToMenu();
void drawMenu();
void controlsMenu();
bool searchByAccountNo(string accountNo, stClient& client, vector<stClient>& clientsList);

void getScreenReady(string title = "", char lineShape = '=') {
	system("cls");
	cout << draw::generateLine(50, lineShape) << endl;
	cout << draw::generateTabs(9) << title << "\n";
	cout << draw::generateLine(50, lineShape) << endl;
}
stClient convertLineToRecord(string clientData, string delimiter = " ") {
	stClient client;
	short counter = 0;
	vector<string>vClient = manipulators::split(clientData, delimiter);
	client.accountNo = vClient.at(0);
	client.PinCode = vClient.at(1);
	client.Name = vClient.at(2);
	client.Phone = vClient.at(3);
	client.AccountBalance = stof(vClient.at(4));

	return client;
}
string convertRecordToLine(stClient clientData, string delimiter = " ") {
	string dataOneLine = "";
	dataOneLine += clientData.accountNo + delimiter;
	dataOneLine += clientData.PinCode + delimiter;
	dataOneLine += clientData.Name + delimiter;
	dataOneLine += clientData.Phone + delimiter;
	dataOneLine += to_string(clientData.AccountBalance);

	return dataOneLine;
}
void printClient(stClient& c) {
	cout << "Account No.     : " << c.accountNo;
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
void rewriteClientsFile(string lines, string fileName) {
	fstream File;
	File.open(fileName, ios::out);
	if (File.is_open()) {
		File << lines;
		File.close();
	}
}
bool searchByAccountNo(string accountNo, stClient& client, vector<stClient>& clientsList) {
	for (stClient& element : clientsList) {
		if (element.accountNo == accountNo) {
			client = element;
			return true;
		}
	}
	return false;
}
bool doesAccountNoExists(string accountNo) {
	fstream MyFile;
	MyFile.open(fileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		stClient Client;
		while (getline(MyFile, Line)) {
			Client = convertLineToRecord(Line,delimiter);
			if (Client.accountNo == accountNo)
			{
				MyFile.close();
				return true;
			}
			MyFile.close();
		}
		return false;
	}
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
string generateClientsLines(vector<stClient>& clients) {
	string lines = "";
	for (stClient& element : clients) {
		if (!element.MarkForDelete) {
			lines += convertRecordToLine(element, delimiter) + "\n";
		}
	}

	return lines;
}

namespace showing {
	void printColumn(string content, int width) {
		cout << left << "| " << setw(width) << content;
	}
	void printHeader(int clientsTotal = 0) {
		cout << setw(50) << draw::generateTabs(25) << "Clients List (" << clientsTotal << ") Clients \n";
		cout << draw::generateLine(115) << " \n";
		printColumn("Account Number", 20);
		printColumn("Pin Code", 15);
		printColumn("Client Name", 35);
		printColumn("Phone", 15);
		printColumn("Balance", 15);
		cout << "\n";
		cout << draw::generateLine(115) << " \n";
		cout << "\n";
	}
	void printClientColumn(stClient& c) {
		printColumn(c.accountNo, 20);
		printColumn(c.PinCode, 15);
		printColumn(c.Name, 35);
		printColumn(c.Phone, 15);
		printColumn(to_string(c.AccountBalance), 15);
		cout << "\n";
	}
	void showClientsList() {
		system("cls");
		cout << endl;
		vector<stClient>clientsList = generateClientsList(fileName);
		printHeader(clientsList.size());
		for (stClient client : clientsList) {
			printClientColumn(client);
		}
		cout << draw::generateLine(115) << " \n";
	}
}
namespace adding {
	void readClientData(stClient& c) {
		cout << "Please enter your Account No. : ";
		getline(cin >> ws, c.accountNo);
		cout << "\n";
		while (doesAccountNoExists(c.accountNo)) {
			cout << "This account number already exists ,Please enter another one :";
			getline(cin >> ws, c.accountNo);
			cout << "\n";
		}
		c.PinCode = read::readText("Please enter your Pin Code : ");
		cout << "\n";

		c.Name = read::readText("Please enter your Name : ");
		cout << "\n";

		c.Phone = read::readText("Please enter your Phone : ");
		cout << "\n";

		c.AccountBalance = read::readFloatNumberMsg("Please enter your Account Balance : ");
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
	void addNewClient() {
		string data = "";
		do {
			getScreenReady("Add New Client", '=');
			stClient c;
			readClientData(c);
			data = convertRecordToLine(c, delimiter);
			addClientToFile(data, fileName);
		} while (doYouQuestion("Do you want to add more ?"));
	}
}
namespace deleting {
	void markClientForDelete(string accountNo, vector<stClient>& clients) {
		for (stClient& element : clients) {
			if (element.accountNo == accountNo) {
				element.MarkForDelete = true;
				return;
			}
		}
	}
	void deleteClientByAccountNo(string accountNo, vector<stClient>& clients) {
		stClient client;
		vector<stClient>clientsList = generateClientsList(fileName);
		if (searchByAccountNo(accountNo, client, clientsList)) {
			cout << "\nThe following are the client details :\n";
			printClient(client);
			if (doYouQuestion("\nAre you sure you want to delete this client ? ")) {
				markClientForDelete(accountNo, clients);
				rewriteClientsFile(generateClientsLines(clients), fileName);
				cout << "\nClient deleted successfully.\n";
			}
		}
		else {
			cout << "\nClient with Account Number (" << accountNo << ") Not Found\n";
		}
	}
	void deleteClient() {
		getScreenReady("Delete Client", '=');
		string accountNo;
		cout << "Please enter your Account No. : ";
		getline(cin >> ws, accountNo);
		vector<stClient>clientsList = generateClientsList(fileName);
		deleteClientByAccountNo(accountNo, clientsList);
	}
}
namespace updating {
	void updateClientData(string accountNo, vector<stClient>& clients) {
		for (stClient& element : clients) {
			if (element.accountNo == accountNo) {
				cout << "Please enter your Pin Code : ";
				getline(cin >> ws, element.PinCode);
				cout << "\n";

				element.Name = read::readText("Please enter your Name : ");
				cout << "\n";

				element.Phone = read::readText("Please enter your Phone : ");
				cout << "\n";

				element.AccountBalance = read::readFloatNumberMsg("Please enter your Account Balance : ");
				cout << "\n";

				return;
			}
		}
	}
	void updateClientByAccountNo(string accountNo, vector<stClient>& clients) {
		stClient client;
		if (searchByAccountNo(accountNo, client, clients)) {
			cout << "\nThe following are the client details :\n";
			printClient(client);
			if (doYouQuestion("\nAre you sure you want to update this client ? ")) {
				updateClientData(accountNo, clients);
				rewriteClientsFile(generateClientsLines(clients), fileName);
				cout << "\nClient updated successfully.\n";
			}
		}
		else {
			cout << "\nClient with Account Number (" << accountNo << ") Not Found\n";
		}
	}
	void updateClient() {
		getScreenReady("Update Client", '=');
		string accountNo;
		cout << "Please enter your Account No. : ";
		getline(cin >> ws, accountNo);
		vector<stClient>clientsList = generateClientsList(fileName);
		updateClientByAccountNo(accountNo, clientsList);
	}
}
namespace searching {
	void searchClient() {
		getScreenReady("Find Client", '=');
		vector<stClient>clientsList = generateClientsList(fileName);
		stClient client;
		string accountNo;
		cout << "Please enter your Account No. : ";
		getline(cin >> ws, accountNo);

		if (searchByAccountNo(accountNo, client, clientsList)) {
			cout << "\nThe following are the client details :\n";
			printClient(client);
		}
		else {
			cout << "\nClient with Account Number (" << accountNo << ") Not Found\n";
		}
	}
}
void controlsMenu() {
	switch (read::readNumberMsg("Choose what do you want to do? [1 to 6]")) {
	case enMenuOptions::Show: {
		showing::showClientsList();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Add: {
		adding::addNewClient();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Delete: {
		deleting::deleteClient();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Update: {
		updating::updateClient();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Find: {
		searching::searchClient();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Exit:
	default:
		getScreenReady("Program Ends :-)", '-');
	}

}
void drawMenu() {
	getScreenReady("Main Menu Screen", '=');
	cout << setw(9) << draw::generateTabs(9) << "[1] Show Clients List.\n";
	cout << setw(9) << draw::generateTabs(9) << "[2] Add New Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[3] Delete Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[4] Update Client Info.\n";
	cout << setw(9) << draw::generateTabs(9) << "[5] Find Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[6] Exit.\n";
	cout << draw::generateLine(50, '=') << "\n";
	controlsMenu();
}
void goBackToMenu() {
	cout << "\n\nPress any key to go back to Menu...";
	system("pause > 0");
	system("cls");
	drawMenu();
}
int main() {
	drawMenu();
	return 0;
}
