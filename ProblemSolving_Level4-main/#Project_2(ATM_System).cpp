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
	bool MarkForDelete = false;
};
enum enMenuOptions { QuickWithdraw = 1, NormalWithdraw = 2, Deposit = 3, CheckBalance = 4, Exit = 5 };
enum enOperationStatus { Success = 1, Failed = -1, NoTransaction = 0 };

const string clientsFileName = "clients.txt";
const string delimiter = "#//#";
stClient currentClient;
void goBackToMenu();
void controlsMenu();
void drawMenu();

namespace General {
	void getScreenReady(string title = "", char lineShape = '=') {
		system("cls");
		cout << draw::generateLine(50, lineShape) << endl;
		cout << draw::generateTabs(9) << title << "\n";
		cout << draw::generateLine(50, lineShape) << endl;
	}
	vector<string> readFromFile(string fileName) {
		fstream File;
		vector<string> lines;
		File.open(fileName, ios::in);
		if (File.is_open()) {
			string line = "";
			while (getline(File, line)) {
				if (!line.empty() && line != " ")
					lines.push_back(line);
			};
			File.close();
		}
		return lines;
	}
	void printColumn(string content, int width) {
		cout << left << "| " << setw(width) << content;
	}
	void rewriteFile(string lines, string fileName) {
		fstream File;
		File.open(fileName, ios::out);
		if (File.is_open()) {
			File << lines;
			File.close();
		}
	}
}
namespace GeneralClients {
	string convertClientRecordToLine(stClient clientData, string delimiter = " ") {
		string dataOneLine = "";
		dataOneLine += clientData.AccountNo + delimiter;
		dataOneLine += clientData.PinCode + delimiter;
		dataOneLine += clientData.Name + delimiter;
		dataOneLine += clientData.Phone + delimiter;
		dataOneLine += to_string(clientData.AccountBalance);

		return dataOneLine;
	}
	stClient convertClientLineToRecord(string clientData, string delimiter = " ") {
		stClient client;
		short counter = 0;
		vector<string>vClient = manipulators::split(clientData, delimiter);
		client.AccountNo = vClient.at(0);
		client.PinCode = vClient.at(1);
		client.Name = vClient.at(2);
		client.Phone = vClient.at(3);
		client.AccountBalance = stof(vClient.at(4));

		return client;
	}
	string generateClientsLines(vector<stClient>& clientsList) {
		string lines = "";
		for (stClient& element : clientsList) {
			if (!element.MarkForDelete) {
				lines += convertClientRecordToLine(element, delimiter) + "\n";
			}
		}
		return lines;
	}
	vector<stClient> generateClientsList(string clientFileName) {
		vector<string> clientsLines = General::readFromFile(clientFileName);
		vector<stClient> clientsList;
		for (string line : clientsLines) {
			stClient c;
			c = convertClientLineToRecord(line, delimiter);
			clientsList.push_back(c);
		}
		return clientsList;
	}
	bool searchByAccountNo(string accountNo, stClient& client, vector<stClient>& clientsList) {
		for (stClient& element : clientsList) {
			if (element.AccountNo == accountNo) {
				client = element;
				return true;
			}
		}
		return false;
	}
	void findCurrentClientOnList(vector<stClient>& clientsList) {
		for (stClient& element : clientsList) {
			if (element.AccountNo == currentClient.AccountNo) {
				element = currentClient;
				return;
			}
		}
	}
	void updateCurrentClientData() {
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientsFileName);
		findCurrentClientOnList(clientsList);
		General::rewriteFile(GeneralClients::generateClientsLines(clientsList), clientsFileName);
	}
}
namespace GeneralATM {
	enOperationStatus withdraw(int amount) {
		if (amount <= currentClient.AccountBalance) {
			if (doYouQuestion("Are you sure you want to perform this transaction?"))
			{
				currentClient.AccountBalance -= amount;
				GeneralClients::updateCurrentClientData();
				return enOperationStatus::Success;
			}
		}
		else
			return enOperationStatus::Failed;

		return enOperationStatus::NoTransaction;
	}
	enOperationStatus deposit(int amount) {
		if (amount > 0) {
			if (doYouQuestion("Are you sure you want to perform this transaction?"))
			{
				currentClient.AccountBalance += amount;
				GeneralClients::updateCurrentClientData();
				return enOperationStatus::Success;
			}
		}
		else
			return enOperationStatus::Failed;

		return enOperationStatus::NoTransaction;
	}
}
namespace LoginScreen {
	bool isValidClient(stClient& client) {
		string pincode = client.PinCode;
		vector<stClient>clients = GeneralClients::generateClientsList(clientsFileName);
		if (GeneralClients::searchByAccountNo(client.AccountNo, client, clients) && pincode == client.PinCode)
			return true;
		return false;
	}
	void login() {
		General::getScreenReady("Login Screen", '=');
		stClient client;
		client.AccountNo = read::readTextWithoutWs("Enter Account Number ?");
		client.PinCode = read::readTextWithoutWs("Enter PinCode ?");

		while (!isValidClient(client)) {
			system("cls");
			General::getScreenReady("Login Screen", '=');
			cout << "Invalid Account Number/PinCode !\n";
			client.AccountNo = read::readTextWithoutWs("Enter Account Number ?");
			client.PinCode = read::readTextWithoutWs("Enter PinCode ?");
		}
		currentClient = client;
		drawMenu();
	}
}
namespace CheckBalanceScreen {
	float getBalance() {
		return currentClient.AccountBalance;
	}
	void drawCheckingBalanceScreen() {
		General::getScreenReady("Login Screen", '=');
		cout << "Your Balance is " << getBalance();
	}
}
namespace QuickWithdrawScreen {
	void quickWithdrawCtrl() {
		int choice = read::readNumberInRangeMsg("Choose what to withdraw from the list above ?", 1, 9);
		if (choice == 9) return;
		int amount[8] = { 20,50,100,200,400,600,800,1000 };
		enOperationStatus result = GeneralATM::withdraw(amount[choice - 1]);
		if (result == enOperationStatus::Success) {
			cout << "Done Successfully.";
			cout << "Your Balance is " << CheckBalanceScreen::getBalance() << "\n";
		}
		if (result == enOperationStatus::Failed) {
			cout << "The amount exceed your balance , make another choice.\n";
			quickWithdrawCtrl();
		}
	}
	void drawQuickWithdrawScreen() {
		General::getScreenReady("Quick Withdraw Screen", '=');
		cout << draw::generateTabs(3) << "[1] 20 " << draw::generateTabs(3) << "[2] 50 " << "\n";
		cout << draw::generateTabs(3) << "[3] 100" << draw::generateTabs(3) << "[4] 200" << "\n";
		cout << draw::generateTabs(3) << "[5] 400" << draw::generateTabs(3) << "[6] 600" << "\n";
		cout << draw::generateTabs(3) << "[7] 800" << draw::generateTabs(3) << "[8] 1000" << "\n";
		cout << draw::generateTabs(3) << "[9] Exit" << "\n";
		cout << draw::generateLine(50, '\n ') << endl;
		cout << "Your Balance is " << CheckBalanceScreen::getBalance() << "\n";
		quickWithdrawCtrl();
	}
}
namespace NormalWithdrawScreen {
	void normalWithdrawCtrl() {
		int amount = 0;
		do { amount = read::readPositiveNumberMsg("Enter an amount  multiply of 5's ?"); } while (amount % 5 != 0);
		enOperationStatus result = GeneralATM::withdraw(amount);
		if (result == enOperationStatus::Success) {
			cout << "Done Successfully.";
			cout << "Your Balance is " << CheckBalanceScreen::getBalance() << "\n";
		}
		if (result == enOperationStatus::Failed) {
			cout << "The amount exceed your balance , make another choice.\n";
			normalWithdrawCtrl();
		}
	}
	void drawNormalWithdrawScreen() {
		General::getScreenReady("Normal Withdraw Screen", '=');
		normalWithdrawCtrl();

	}
}
namespace DepositScreen {
	void depositCtrl() {
		int amount =  read::readPositiveNumberMsg("Enter a deposit positive amount ?"); 
	
		enOperationStatus result = GeneralATM::deposit(amount);
		if (result == enOperationStatus::Success) {
			cout << "Done Successfully.";
			cout << "Your Balance is " << CheckBalanceScreen::getBalance() << "\n";
		}
		if (result == enOperationStatus::Failed) {
			cout << "Something wrong please try again.\n";
			depositCtrl();
		}
	}
	void drawDepositScreen() {
		General::getScreenReady("Deposit Screen", '=');
		depositCtrl();
	}
}
void controlsMenu() {
	switch (read::readNumberMsg("Choose what do you want to do? [1 to 5]")) {
	case enMenuOptions::QuickWithdraw: {
		QuickWithdrawScreen::drawQuickWithdrawScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::NormalWithdraw: {
		NormalWithdrawScreen::drawNormalWithdrawScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Deposit: {
		DepositScreen::drawDepositScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::CheckBalance: {
		CheckBalanceScreen::drawCheckingBalanceScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Exit: {
		LoginScreen::login();
		break;
	}
	default:
		General::getScreenReady("Program Ends :-)", '-');
	}
}
void drawMenu() {
	General::getScreenReady("Main Menu Screen", '=');
	cout << setw(9) << draw::generateTabs(9) << "[1] Quick Withdraw\n";
	cout << setw(9) << draw::generateTabs(9) << "[2] Normal Withdraw.\n";
	cout << setw(9) << draw::generateTabs(9) << "[3] Deposit.\n";
	cout << setw(9) << draw::generateTabs(9) << "[4] CheckBalance.\n";
	cout << setw(9) << draw::generateTabs(9) << "[5] Logout.\n";
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
	LoginScreen::login();
	return 0;
}
