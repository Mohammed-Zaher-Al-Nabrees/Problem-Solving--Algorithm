#include<iostream>
#include<string>
#include<cctype>
using namespace std;

long long int readNumber() {
	long long int userNumber = 0;
	cin >> userNumber;
	while (cin.fail())
	{
		// Explain error
		cout << "ERROR: A Number must be entered:\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> userNumber;
	}
	return  userNumber;
}
long long int readNumberMsg(string msg) {
	long long int number = 0;
	cout << msg << " ";
	number = readNumber();
	return number;
}
string placesWord(short place) {
	if (place % 3 == 0) {
		return "Hundred ";
	}
	if (place == 4) {
		return "Thousand ";
	}
	if (place == 7) {
		return "Million ";
	}
	if (place == 10) {
		return "Billion ";
	}
	if (place == 13) {
		return "Trillion ";
	}
	return"";
}
string partNumberWord(int number) {
	string wordsNumbers[] = { " ","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Ninteen ","Twenty ","Twenty One ","Twenty Two ","Twenty Three ","Twenty Four ","Twenty Five ","Twenty Six ","Twenty Seven ","Twenty Eight ","Twenty Nine ","Thirty ","Thirty One ","Thirty Two ","Thirty Three ","Thirty Four ","Thirty Five ","Thirty Six ","Thirty Seven ","Thirty Eight ","Thirty Nine ","Fourty ","Fourty One ","Fourty Two ","Fourty Three ","Fourty Four ","Fourty Five ","Fourty Six ","Fourty Seven ","Fourty Eight ","Fourty Nine ","Fifty ","Fifty One ","Fifty Two ","Fifty Three ","Fifty Four ","Fifty Five ","Fifty Six ","Fifty Seven ","Fifty Eight ","Fifty Nine ","Sixty ","Sixty One ","Sixty Two ","Sixty Three ","Sixty Four ","Sixty Five ","Sixty Six ","Sixty Seven ","Sixty Eight ","Sixty Nine ","Seventy ","Seventy One ","Seventy Two ","Seventy Three ","Seventy Four ","Seventy Five ","Seventy Six ","Seventy Seven ","Seventy Eight ","Seventy Nine ","Eighty ","Eighty One ","Eighty Two ","Eighty Three ","Eighty Four ","Eighty Five ","Eighty Six ","Eighty Seven ","Eighty Eight ","Eighty Nine ","Ninty ","Ninty One ","Ninty Two ","Ninty Three ","Ninty Four ","Ninty Five ","Ninty Six ","Ninty Seven ","Ninty Eight ","Ninty Nine " };
	return wordsNumbers[number];
}
string convertNumberToText(long long int number) {
	int currentNumber; short place = 1, placeValue = 0;
	string words = "", currentWord = "";
	while (number > 0) {
		if (place % 3 != 0) {
			currentNumber = number % 100;
			number = number / 100;
		}
		else {
			currentNumber = number % 10;
			number = number / 10;

		}
		currentWord = partNumberWord(currentNumber) + placesWord(place) + currentWord;
		placeValue += currentNumber;
		if (number == 0 || place % 3 == 0) {
			if (placeValue > 0)
				words = currentWord + words;
			currentWord = "";
			placeValue = 0;
		}

		if (place % 3 != 0) {
			place = place + 2;
		}
		else {
			place++;
		}
	}

	return words;
}

int main() {
	cout << convertNumberToText(readNumberMsg("Enter number :")) << endl;
	return 0;
}
