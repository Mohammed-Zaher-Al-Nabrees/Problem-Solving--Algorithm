#include<iostream>
#include<iomanip>
#include<vector>
#include<cctype>
#include<fstream>
#include"myLibrary.h"
using namespace std;
using namespace myLibrary;

struct stUser {
	string username = "";
	string password = "";
	int rights = 0;
	bool MarkForDelete = false;
};
struct stClient {
	string accountNo = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AccountBalance = 0.0;
	bool MarkForDelete = false;
};
enum enMenuOptions { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transactions = 6, ManageUsers = 7, Exit = 8 };
enum enTransactions { Deposite = 1, Withdraw = 2, TotalBalances = 3, MainMenu = 4 };
enum enUsers { ShowUsers = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, BackToMainMenu = 6 };
enum enScreenRights {
	scShowClients = 1,
	scAddNewClient = 2,
	scDeleteClient = 4,
	scUpdateClient = 8,
	scFindClient = 16,
	scTransactions = 32,
	scManageUsers = 64,
	scShowUsers = 128,
	scAddNewUser = 256,
	scDeleteUser = 512,
	scUpdateUser = 1024,
	scFindUser = 2048,
	scDeposite = 4096,
	scWithdraw = 8192,
	scTotalsBalances = 16384
};
const string usersFileName = "users.txt";
const string clientFileName = "clients.txt";
const string delimiter = "#//#";
stUser currentUser;

void goBackToMenu();
void drawMenu();
void controlsMenu();

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
	bool hasRights(enScreenRights screenRights) {
		return (currentUser.rights == -1 || (currentUser.rights & screenRights));
	}
	void showAccessDeniedScreen() {
		getScreenReady("Access Denied", '=');
		cout << "\n You don't have premmission ,\n Please contact your admin.";
	}
}
namespace GeneralClients {
	string convertClientRecordToLine(stClient clientData, string delimiter = " ") {
		string dataOneLine = "";
		dataOneLine += clientData.accountNo + delimiter;
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
		client.accountNo = vClient.at(0);
		client.PinCode = vClient.at(1);
		client.Name = vClient.at(2);
		client.Phone = vClient.at(3);
		client.AccountBalance = stof(vClient.at(4));

		return client;
	}
	string generateClientsLines(vector<stClient>& clients) {
		string lines = "";
		for (stClient& element : clients) {
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
}
namespace SearchClientScreen {
	bool searchByAccountNo(string accountNo, stClient& client, vector<stClient>& clientsList) {
		for (stClient& element : clientsList) {
			if (element.accountNo == accountNo) {
				client = element;
				return true;
			}
		}
		return false;
	}
	void searchClient() {
		General::getScreenReady("Find Client", '=');
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientFileName);
		stClient client;
		string accountNo;
		cout << "Please enter account number : ";
		getline(cin >> ws, accountNo);

		if (searchByAccountNo(accountNo, client, clientsList)) {
			cout << "\nThe following are the client details :\n";
			GeneralClients::printClient(client);
		}
		else {
			cout << "\nClient with (" << accountNo << ") does not exist\n";
		}
	}
}
namespace ClientsListScreen {
	void printHeader(int clientsTotal = 0) {
		cout << setw(50) << draw::generateTabs(25) << "Clients List (" << clientsTotal << ") Clients \n";
		cout << draw::generateLine(115) << " \n";
		General::printColumn("Account Number", 20);
		General::printColumn("Pin Code", 15);
		General::printColumn("Client Name", 35);
		General::printColumn("Phone", 15);
		General::printColumn("Balance", 15);
		cout << "\n";
		cout << draw::generateLine(115) << " \n";
		cout << "\n";
	}
	void printClientColumn(stClient& c) {
		General::printColumn(c.accountNo, 20);
		General::printColumn(c.PinCode, 15);
		General::printColumn(c.Name, 35);
		General::printColumn(c.Phone, 15);
		General::printColumn(to_string(c.AccountBalance), 15);
		cout << "\n";
	}
	void showClientsList() {
		system("cls");
		cout << endl;
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientFileName);
		printHeader(clientsList.size());
		for (stClient client : clientsList) {
			printClientColumn(client);
		}
		cout << draw::generateLine(115) << " \n";
	}
}
namespace BalancesListScreen {
	void printBalanceHeader(int clientsTotal = 0) {
		cout << draw::generateTabs(20) << "Balances List (" << clientsTotal << ") Clients \n";
		cout << draw::generateLine(70) << " \n";
		General::printColumn("Account Number", 20);
		General::printColumn("Client Name", 35);
		General::printColumn("Balance", 15);
		cout << "\n";
		cout << draw::generateLine(70) << " \n";
		cout << "\n";
	}
	void printBalanceColumn(stClient& c) {
		General::printColumn(c.accountNo, 20);
		General::printColumn(c.Name, 35);
		General::printColumn(to_string(c.AccountBalance), 15);
		cout << "\n";
	}
	void showBalancesList() {
		system("cls");
		cout << endl;
		float totalBalances = 0.0;
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientFileName);
		printBalanceHeader(clientsList.size());
		for (stClient client : clientsList) {
			printBalanceColumn(client);
			totalBalances = totalBalances + client.AccountBalance;
		}
		cout << draw::generateLine(70) << " \n";
		cout << draw::generateTabs(45) << "Total Balances: " << totalBalances << "\n";
	}
}
namespace AddClientScreen {
	bool doesAccountNoExists(string accountNo) {
		fstream MyFile;
		MyFile.open(clientFileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			stClient Client;
			while (getline(MyFile, Line)) {
				Client = GeneralClients::convertClientLineToRecord(Line, delimiter);
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
			General::getScreenReady("Add New Client", '=');
			stClient c;
			readClientData(c);
			data = GeneralClients::convertClientRecordToLine(c, delimiter);
			addClientToFile(data, clientFileName);
		} while (doYouQuestion("Do you want to add more ?"));
	}
}
namespace DeleteClientScreen {
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
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientFileName);
		if (SearchClientScreen::searchByAccountNo(accountNo, client, clientsList)) {
			cout << "\nThe following are the client details :\n";
			GeneralClients::printClient(client);
			if (doYouQuestion("\nAre you sure you want to delete this client ? ")) {
				markClientForDelete(accountNo, clients);
				General::rewriteFile(GeneralClients::generateClientsLines(clients), clientFileName);
				cout << "\nClient deleted successfully.\n";
			}
		}
		else {
			cout << "\nClient with (" << accountNo << ") does not exist\n";
		}
	}
	void deleteClient() {
		General::getScreenReady("Delete Client", '=');
		string accountNo;
		cout << "Please enter account number : ";
		getline(cin >> ws, accountNo);
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientFileName);
		deleteClientByAccountNo(accountNo, clientsList);
	}
}
namespace UpdateClientScreen {
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
		if (SearchClientScreen::searchByAccountNo(accountNo, client, clients)) {
			cout << "\nThe following are the client details :\n";
			GeneralClients::printClient(client);
			if (doYouQuestion("\nAre you sure you want to update this client ? ")) {
				updateClientData(accountNo, clients);
				General::rewriteFile(GeneralClients::generateClientsLines(clients), clientFileName);
				cout << "\nClient updated successfully.\n";
			}
		}
		else {
			cout << "\nClient with (" << accountNo << ") does not exist\n";
		}
	}
	void updateClient() {
		General::getScreenReady("Update Client", '=');
		string accountNo;
		cout << "Please enter account number : ";
		getline(cin >> ws, accountNo);
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientFileName);
		updateClientByAccountNo(accountNo, clientsList);
	}
}
namespace TransactionsScreen {
	void drawTransactionsMenu();
	void goBackToTransactionsMenu();
	void controlsTransactionsMenu();

	void drawTransactionsMenu() {
		General::getScreenReady("Transactions Menu", '=');
		//if (currentUser.rights == -1 || (currentUser.rights & enScreenRights::scDeposite))
		cout << setw(9) << draw::generateTabs(9) << "[1] Deposite.\n";
		cout << setw(9) << draw::generateTabs(9) << "[2] Withdraw.\n";
		cout << setw(9) << draw::generateTabs(9) << "[3] Totals Balances.\n";
		cout << setw(9) << draw::generateTabs(9) << "[4] Main Menu.\n";
		cout << draw::generateLine(50, '=') << "\n";
		controlsTransactionsMenu();
	}
	void transaction(string title, int factor = 1) {
		General::getScreenReady(title + " Screen", '-');
		vector<stClient>clientsList = GeneralClients::generateClientsList(clientFileName);
		stClient client;
		string accountNo;
		cout << "Please enter account number : ";
		getline(cin >> ws, accountNo);

		while (!SearchClientScreen::searchByAccountNo(accountNo, client, clientsList)) {
			cout << "\nClient with (" << accountNo << ") does not exist.\n";
			cout << "Please enter account number : ";
			getline(cin >> ws, accountNo);

		}
		cout << "\nThe following are the client details :\n";
		GeneralClients::printClient(client);

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
			General::rewriteFile(GeneralClients::generateClientsLines(clientsList), clientFileName);
			cout << "\nThe transaction performed successfully.\n";

		}
	}
	void deposite() {
		transaction("Deposite", 1);
	}
	void withdraw() {
		transaction("Withdraw", -1);
	}
	void goBackToTransactionsMenu() {
		cout << "\n\nPress any key to go back to Transactions Menu...";
		system("pause > 0");
		system("cls");
		drawTransactionsMenu();
	}
	void controlsTransactionsMenu() {
		switch (read::readNumberMsg("Choose what do you want to do? [1 to 4]")) {
		case enTransactions::Deposite: {
			(General::hasRights(enScreenRights::scDeposite)) ? TransactionsScreen::deposite() : General::showAccessDeniedScreen();
			goBackToTransactionsMenu();
			break;
		}
		case enTransactions::Withdraw: {
			(General::hasRights(enScreenRights::scWithdraw)) ? TransactionsScreen::withdraw() : General::showAccessDeniedScreen();
			goBackToTransactionsMenu();
			break;
		}
		case enTransactions::TotalBalances: {
			(General::hasRights(enScreenRights::scTotalsBalances)) ? BalancesListScreen::showBalancesList() : General::showAccessDeniedScreen();
			goBackToTransactionsMenu();
			break;
		}
		case enTransactions::MainMenu:
		default:
			goBackToMenu();
		}
	}
}
namespace GeneralUsers {
	stUser convertUserLineToRecord(string userData, string delimiter = " ") {
		stUser user;
		short counter = 0;
		vector<string>vUser = manipulators::split(userData, delimiter);
		user.username = vUser.at(0);
		user.password = vUser.at(1);
		user.rights = stof(vUser.at(2));

		return user;
	}
	string convertUsersRecordToLine(stUser userData, string delimiter = " ") {
		string dataOneLine = "";
		dataOneLine += userData.username + delimiter;
		dataOneLine += userData.password + delimiter;
		dataOneLine += to_string(userData.rights);

		return dataOneLine;
	}
	string generateUsersLines(vector<stUser>& users) {
		string lines = "";
		for (stUser& element : users) {
			if (!element.MarkForDelete) {
				lines += convertUsersRecordToLine(element, delimiter) + "\n";
			}
		}
		return lines;
	}
	vector<stUser> generateUsersList(string usersFileName) {
		vector<string> usersLines = General::readFromFile(usersFileName);
		vector<stUser> usersList;
		for (string line : usersLines) {
			stUser user;
			user = convertUserLineToRecord(line, delimiter);
			usersList.push_back(user);
		}
		return usersList;
	}
	void printUser(stUser& user) {
		cout << draw::generateLine(30, '-');
		cout << "\nUsername     : " << user.username;
		cout << "\n";
		cout << "Password        : " << user.password;
		cout << "\n";
		cout << "Rights            : " << user.rights;
		cout << "\n";
		cout << draw::generateLine(30, '-');
	}
	int getUserNewRights() {
		if (doYouQuestion("Do you want to give this user full access ?"))
			return -1;
		cout << "Do you want to give access to :\n";
		int rights = 0;
		if (doYouQuestion("Show Clients List ?"))rights += enScreenRights::scShowClients;
		if (doYouQuestion("Add New Client ?"))rights += enScreenRights::scAddNewClient;
		if (doYouQuestion("Delete Client ?"))rights += enScreenRights::scDeleteClient;
		if (doYouQuestion("Update Client ?"))rights += enScreenRights::scUpdateClient;
		if (doYouQuestion("Find Client ?"))rights += enScreenRights::scFindClient;

		if (doYouQuestion("Transactions ?"))
		{
			rights += enScreenRights::scTransactions;
			//if (doYouQuestion("Deposite ?"))rights += enScreenRights::scDeposite;
			//if (doYouQuestion("Withdraw ?"))rights += enScreenRights::scWithdraw;
			//if (doYouQuestion("Show Total Balances ?"))rights += enScreenRights::scTotalsBalances;
		}

		if (doYouQuestion("Manage Users ?"))
		{
			rights += enScreenRights::scManageUsers;
			/*if (doYouQuestion("Show Users List ?"))rights += enScreenRights::scShowUsers;
			if (doYouQuestion("Add New User ?"))rights += enScreenRights::scAddNewUser;
			if (doYouQuestion("Delete User ?"))rights += enScreenRights::scDeleteUser;
			if (doYouQuestion("Update User ?"))rights += enScreenRights::scUpdateUser;
			if (doYouQuestion("Find User ?"))rights += enScreenRights::scFindClient;*/
		}

		return rights;
	}
}
namespace SearchUsersScreen {
	bool searchByUsername(stUser& user, vector<stUser>usersList) {
		for (stUser& element : usersList) {
			if (manipulators::smallization(element.username) == manipulators::smallization(user.username)) {
				user = element;
				return true;
			}
		}
		return false;
	}
	void searchUser() {
		General::getScreenReady("Find User", '=');
		stUser user;
		cout << "Please enter username : ";
		getline(cin >> ws, user.username);
		vector<stUser>users = GeneralUsers::generateUsersList(usersFileName);
		if (searchByUsername(user, users)) {
			cout << "\nThe following are the user details :\n";
			GeneralUsers::printUser(user);
		}
		else {
			cout << "\nUser with (" << user.username << ") does not exist\n";
		}
	}
}
namespace LoginScreen {
	bool isValidUser(stUser& user) {
		string password = user.password;
		vector<stUser>users = GeneralUsers::generateUsersList(usersFileName);
		if (SearchUsersScreen::searchByUsername(user, users) && password == user.password)
			return true;
		return false;
	}
	void login() {
		General::getScreenReady("Login Screen", '=');
		stUser user;
		user.username = read::readText("Enter Username ?");
		user.password = read::readText("Enter Password ?");

		while (!isValidUser(user)) {
			system("cls");
			General::getScreenReady("Login Screen", '=');
			cout << "Invalid Usename/Password!\n";
			user.username = read::readText("Enter Username ?");
			user.password = read::readText("Enter Password ?");
		}
		currentUser = user;
		drawMenu();
	}
}
namespace UsersListScreen {
	void printHeader(int usersTotal = 0) {
		cout << setw(50) << draw::generateTabs(25) << "Users List (" << usersTotal << ") Users \n";
		cout << draw::generateLine(115) << " \n";
		General::printColumn("Username", 20);
		General::printColumn("Password", 15);
		General::printColumn("Rights", 35);
		cout << "\n";
		cout << draw::generateLine(115) << " \n";
		cout << "\n";
	}
	void printUserColumn(stUser& c) {
		General::printColumn(c.username, 20);
		General::printColumn(c.password, 15);
		General::printColumn(to_string(c.rights), 35);
		cout << "\n";
	}
	void showUsersList() {
		system("cls");
		cout << endl;
		vector<stUser>usersList = GeneralUsers::generateUsersList(usersFileName);
		printHeader(usersList.size());
		for (stUser user : usersList) {
			printUserColumn(user);
		}
		cout << draw::generateLine(115) << " \n";
	}
}
namespace AddUserScreen {
	bool doesUsernameExists(string username) {
		fstream MyFile;
		MyFile.open(usersFileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			stUser User;
			while (getline(MyFile, Line)) {
				User = GeneralUsers::convertUserLineToRecord(Line, delimiter);
				if (User.username == username)
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
	void readUserData(stUser& c) {
		cout << "Please enter username : ";
		getline(cin >> ws, c.username);
		cout << "\n";
		while (doesUsernameExists(c.username)) {
			cout << "This username already exists ,Please enter another one :";
			getline(cin >> ws, c.username);
			cout << "\n";
		}
		c.password = read::readText("Please enter password : ");
		cout << "\n";
		c.rights = GeneralUsers::getUserNewRights();
		cout << "\n";
	}
	void addUserToFile(string data, string file) {
		fstream File;
		File.open(file, ios::out | ios::app);
		if (File.is_open()) {
			File << "\n";
			File << data;
			File.close();
		}
	}
	void addNewUser() {
		string data = "";
		do {
			General::getScreenReady("Add New User", '=');
			stUser c;
			readUserData(c);
			data = GeneralUsers::convertUsersRecordToLine(c, delimiter);
			addUserToFile(data, usersFileName);
		} while (doYouQuestion("Do you want to add more ?"));
	}
}
namespace DeleteUserScreen {
	void markUserForDelete(string username, vector<stUser>& users) {
		for (stUser& element : users) {
			if (element.username == username) {
				element.MarkForDelete = true;
				return;
			}
		}
	}
	void deleteUserByUsername(string username) {
		stUser user;
		user.username = username;
		vector<stUser>users = GeneralUsers::generateUsersList(usersFileName);
		if (SearchUsersScreen::searchByUsername(user, users)) {
			cout << "\nThe following are the user details :\n";
			GeneralUsers::printUser(user);
			if (doYouQuestion("\nAre you sure you want to delete this user ? ")) {
				markUserForDelete(username, users);
				General::rewriteFile(GeneralUsers::generateUsersLines(users), usersFileName);
				cout << "\nUser deleted successfully.\n";
			}
		}
		else {
			cout << "\nUser with (" << username << ") does not exist\n";
		}
	}
	void deleteUser() {
		General::getScreenReady("Delete User", '=');
		string username;
		cout << "Please enter username : ";
		getline(cin >> ws, username);
		deleteUserByUsername(username);
	}
}
namespace UpdateUserScreen {
	void updateUserData(stUser& user) {
		cout << "Please enter password : ";
		getline(cin >> ws, user.password);
		cout << "\n";
		user.rights = GeneralUsers::getUserNewRights();
		cout << "\n";
	}
	void updateUserByUsername(string username, vector<stUser>& users) {
		stUser user;
		user.username = username;
		if (SearchUsersScreen::searchByUsername(user, users)) {
			cout << "\nThe following are the user details :\n";
			GeneralUsers::printUser(user);
			if (doYouQuestion("\nAre you sure you want to update this user ? ")) {
				updateUserData(user);
				for (stUser& element : users) {
					if (element.username == username) {
						element = user;
						break;
					}
				}
				General::rewriteFile(GeneralUsers::generateUsersLines(users), usersFileName);
				cout << "\nUser updated successfully.\n";
			}
		}
		else {
			cout << "\nUser with (" << username << ") does not exist\n";
		}
	}
	void updateUser() {
		General::getScreenReady("Update User", '=');
		string username;
		cout << "Please enter username : ";
		getline(cin >> ws, username);
		vector<stUser>usersList = GeneralUsers::generateUsersList(usersFileName);
		updateUserByUsername(username, usersList);
	}
}
namespace UsersScreen {
	void drawUsersMenu();
	void goBackToUsersMenu();
	void controlsUsersMenu();

	void drawUsersMenu() {
		General::getScreenReady("Users Menu", '=');
		cout << setw(9) << draw::generateTabs(9) << "[1] List Users.\n";
		cout << setw(9) << draw::generateTabs(9) << "[2] Add New User.\n";
		cout << setw(9) << draw::generateTabs(9) << "[3] Delete User.\n";
		cout << setw(9) << draw::generateTabs(9) << "[4] Update User.\n";
		cout << setw(9) << draw::generateTabs(9) << "[5] Find User.\n";
		cout << setw(9) << draw::generateTabs(9) << "[6] Main Menu.\n";
		cout << draw::generateLine(50, '=') << "\n";
		controlsUsersMenu();
	}
	void goBackToUsersMenu() {
		cout << "\n\nPress any key to go back to Users Menu...";
		system("pause > 0");
		system("cls");
		drawUsersMenu();
	}
	void controlsUsersMenu() {
		switch (read::readNumberMsg("Choose what do you want to do? [1 to 6]")) {
		case enUsers::ShowUsers: {
			(General::hasRights(enScreenRights::scShowUsers)) ? UsersListScreen::showUsersList() : General::showAccessDeniedScreen();
			goBackToUsersMenu();
			break;
		}
		case enUsers::AddUser: {
			(General::hasRights(enScreenRights::scAddNewUser)) ? AddUserScreen::addNewUser() : General::showAccessDeniedScreen();
			goBackToUsersMenu();
			break;
		}
		case enUsers::DeleteUser: {
			(General::hasRights(enScreenRights::scDeleteUser)) ? DeleteUserScreen::deleteUser() : General::showAccessDeniedScreen();
			goBackToUsersMenu();
			break;
		}
		case enUsers::UpdateUser: {
			(General::hasRights(enScreenRights::scUpdateUser)) ? UpdateUserScreen::updateUser() : General::showAccessDeniedScreen();
			goBackToUsersMenu();
			break;
		}
		case enUsers::FindUser: {
			(General::hasRights(enScreenRights::scFindUser)) ? SearchUsersScreen::searchUser() : General::showAccessDeniedScreen();
			goBackToUsersMenu();
			break;
		}
		case enUsers::BackToMainMenu:
		default:
			goBackToMenu();
		}
	}
}
void controlsMenu() {
	switch (read::readNumberMsg("Choose what do you want to do? [1 to 8]")) {
	case enMenuOptions::Show: {
		(General::hasRights(enScreenRights::scShowClients)) ? ClientsListScreen::showClientsList() : General::showAccessDeniedScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Add: {
		(General::hasRights(enScreenRights::scAddNewClient)) ? AddClientScreen::addNewClient() : General::showAccessDeniedScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Delete: {
		(General::hasRights(enScreenRights::scDeleteClient)) ? DeleteClientScreen::deleteClient() : General::showAccessDeniedScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Update: {
		(General::hasRights(enScreenRights::scUpdateClient)) ? UpdateClientScreen::updateClient() : General::showAccessDeniedScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Find: {
		(General::hasRights(enScreenRights::scFindClient)) ? SearchClientScreen::searchClient() : General::showAccessDeniedScreen();
		goBackToMenu();
		break;
	}
	case enMenuOptions::Transactions: {
		if (General::hasRights(enScreenRights::scTransactions))
			TransactionsScreen::drawTransactionsMenu();
		else {
			General::showAccessDeniedScreen();
			goBackToMenu();
		}
		break;
	}
	case enMenuOptions::ManageUsers: {
		if (General::hasRights(enScreenRights::scManageUsers))
			UsersScreen::drawUsersMenu();
		else {
			General::showAccessDeniedScreen();
			goBackToMenu();
		}
		break;
	}
	case enMenuOptions::Exit:
	default:
		General::getScreenReady("Program Ends :-)", '-');
	}

}
void drawMenu() {
	General::getScreenReady("Main Menu Screen", '=');
	cout << setw(9) << draw::generateTabs(9) << "[1] Show Clients List.\n";
	cout << setw(9) << draw::generateTabs(9) << "[2] Add New Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[3] Delete Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[4] Update Client Info.\n";
	cout << setw(9) << draw::generateTabs(9) << "[5] Find Client.\n";
	cout << setw(9) << draw::generateTabs(9) << "[6] Transactions.\n";
	cout << setw(9) << draw::generateTabs(9) << "[7] Manage Users.\n";
	cout << setw(9) << draw::generateTabs(9) << "[8] Logout.\n";
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
