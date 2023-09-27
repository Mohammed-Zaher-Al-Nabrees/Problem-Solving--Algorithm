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
enum enMenuOptions { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transactions = 6, Exit = 7 };
enum enTransactions { Deposite = 1, Withdraw = 2, TotalBalances = 3, MainMenu = 4 };

const string fileName = "clients.txt";
const string delimiter = "#//#";

void goBackToMenu();
void drawMenu();
void controlsMenu();
void goBackToTransactionsMenu();
void drawTransactionsMenu();
void controlsTransactionsMenu();
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
	cout << draw::generateLine(30, '-');
	cout << "\nAccount No.     : " << c.accountNo;
	cout << "\n";
	cout << "Pin Code        : " << c.PinCode;
	cout << "\n";
	cout << "Name            : " << c.Name;
	cout << "\n";
	cout << "Phone           : " << c.Phone;
	cout << "\n";
	cout << "Account Balance : " << c.AccountBalance;
	cout << "\n";
	cout << draw::generateLine(30, '-');
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
			Client = convertLineToRecord(Line, delimiter);
			if (Client.accountNo == accountNo)
			{
				MyFile.close();
				return true;
			}
			MyFile.close();
		}
		return false;
	}
	return false;
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
	void printBalanceHeader(int clientsTotal = 0) {
		cout << draw::generateTabs(20) << "Balances List (" << clientsTotal << ") Clients \n";
		cout << draw::generateLine(70) << " \n";
		printColumn("Account Number", 20);
		printColumn("Client Name", 35);
		printColumn("Balance", 15);
		cout << "\n";
		cout << draw::generateLine(70) << " \n";
		cout << "\n";
	}
	void printBalanceColumn(stClient& c) {
		printColumn(c.accountNo, 20);
		printColumn(c.Name, 35);
		printColumn(to_string(c.AccountBalance), 15);
		cout << "\n";
	}
	void showBalancesList() {
		system("cls");
		cout << endl;
		float totalBalances = 0.0;
		vector<stClient>clientsList = generateClientsList(fileName);
		printBalanceHeader(clientsList.size());
		for (stClient client : clientsList) {
			printBalanceColumn(client);
			totalBalances = totalBalances + client.AccountBalance;
		}
		cout << draw::generateLine(70) << " \n";
		cout << draw::generateTabs(45) << "Total Balances: " << totalBalances << "\n";
	}
}
namespace adding {
	void readClientData(stClient& c) {
		cout << "Please enter account number : ";
		getline(cin >> ws, c.accountNo);
		cout << "\n";
		while (doesAccountNoExists(c.accountNo)) {
			cout << "This account number already exists ,Please enter another one :";
			getline(cin >> ws, c.accountNo);
			cout << "\n";
		}
		c.PinCode = read::readText("Please enter pin code : ");
		cout << "\n";

		c.Name = read::readText("Please enter name : ");
		cout << "\n";

		c.Phone = read::readText("Please enter phone : ");
		cout << "\n";

		c.AccountBalance = read::readFloatNumberMsg("Please enter account balance : ");
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
			cout << "\nClient with (" << accountNo << ") does not exist\n";
		}
	}
	void deleteClient() {
		getScreenReady("Delete Client", '=');
		string accountNo;
		cout << "Please enter account number : ";
		getline(cin >> ws, accountNo);
		vector<stClient>clientsList = generateClientsList(fileName);
		deleteClientByAccountNo(accountNo, clientsList);
	}
}
namespace updating {
	void updateClientData(string accountNo, vector<stClient>& clients) {
		for (stClient& element : clients) {
			if (element.accountNo == accountNo) {
				cout << "Please enter pin code : ";
				getline(cin >> ws, element.PinCode);
				cout << "\n";

				element.Name = read::readText("Please enter name : ");
				cout << "\n";

				element.Phone = read::readText("Please enter phone : ");
				cout << "\n";

				element.AccountBalance = read::readFloatNumberMsg("Please enter account balance : ");
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
			cout << "\nClient with (" << accountNo << ") does not exist\n";
		}
	}
	void updateClient() {
		getScreenReady("Update Client", '=');
		string accountNo;
		cout << "Please enter account number : ";
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
		cout << "Please enter account number : ";
		getline(cin >> ws, accountNo);

		if (searchByAccountNo(accountNo, client, clientsList)) {
			cout << "\nThe following are the client details :\n";
			printClient(client);
		}
		else {
			cout << "\nClient with (" << accountNo << ") does not exist\n";
		}
	}
}
namespace transactions {
	void transaction(string title, int factor = 1) {
		getScreenReady(title + " Screen", '-');
		vector<stClient>clientsList = generateClientsList(fileName);
		stClient client;
		string accountNo;
		cout << "Please enter account number : ";
		getline(cin >> ws, accountNo);

		while (!searchByAccountNo(accountNo, client, clientsList)) {
			cout << "\nClient with (" << accountNo << ") does not exist.\n";
			cout << "Please enter account number : ";
			getline(cin >> ws, accountNo);

		}

		cout << "\nThe following are the client details :\n";
		printClient(client);

		float amount = read::readFloatNumberMsg("\nPlease enter amount :");
		while (factor < 1 && amount > client.AccountBalance) {
			cout << "Amount exceeds the balance, you can withdraw up to : [" << client.AccountBalance << "]\n";
			amount = read::readFloatNumberMsg("Please enter amount :");
		}
		if (doYouQuestion("Are you sure you want perform this transaction ?")) {
			for (stClient& element : clientsList) {
				if (element.accountNo == client.accountNo) {
					element.AccountBalance = client.AccountBalance + (amount * factor);
					break;
				}
			}
			rewriteClientsFile(generateClientsLines(clientsList), fileName);
			cout << "\nThe transaction performed successfully.\n";

		}
	}
	void deposite() {
		transaction("Deposite", 1);
	}
	void withdraw() {
		transaction("Withdraw", -1);
	}
}
void controlsMenu() {
	switch (read::readNumberMsg("Choose what do you want to do? [1 to 7]")) {
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
	case enMenuOptions::Transactions: {
		drawTransactionsMenu();
		break;
	}
	case enMenuOptions::Exit:
	default:
		getScreenReady("Program Ends :-)", '-');
	}

}
void controlsTransactionsMenu() {
	switch (read::readNumberMsg("Choose what do you want to do? [1 to 4]")) {
	case enTransactions::Deposite: {
		transactions::deposite();
		goBackToTransactionsMenu();
		break;
	}
	case enTransactions::Withdraw: {
		transactions::withdraw();
		goBackToTransactionsMenu();
		break;
	}
	case enTransactions::TotalBalances: {
		showing::showBalancesList();
		goBackToTransactionsMenu();
		break;
	}
	case enTransactions::MainMenu:
	default:
		goBackToMenu();
	}
}
void drawTransactionsMenu() {
	getScreenReady("Transactions Menu", '=');
	cout << setw(9) << draw::generateTabs(9) << "[1] Deposite.\n";
	cout << setw(9) << draw::generateTabs(9) << "[2] Withdraw.\n";
	cout << setw(9) << draw::generateTabs(9) << "[3] Totals Balances.\n";
	cout << setw(9) << draw::generateTabs(9) << "[4] Main Menu.\n";
	cout << draw::generateLine(50, '=') << "\n";
	controlsTransactionsMenu();
}
void drawMenu() {
	getScreenReady("Main Menu Screen", '=');
	cout << setw(9) << draw::generateTabs(9) << "[1] Show Clients List.\n";
	cout << setw(9) << draw::generateTabs(9) << "[2] Add New Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[3] Delete Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[4] Update Client Info.\n";
	cout << setw(9) << draw::generateTabs(9) << "[5] Find Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[6] Transactions.\n";
	cout << setw(9) << draw::generateTabs(9) << "[7] Exit.\n";
	cout << draw::generateLine(50, '=') << "\n";
	controlsMenu();
}
void goBackToTransactionsMenu() {
	cout << "\n\nPress any key to go back to Transactions Menu...";
	system("pause > 0");
	system("cls");
	drawTransactionsMenu();
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
