#include<iostream>
#include"myLibrary.h"
using namespace std;

enum enChoices { Stone = 1, Paper = 2, Scissors = 3 };
struct stPlayer { int ID = 0;string Name = ""; int TotalScore = 0; };
struct stRound {
	int RoundOrder;
	int Winner;
	enChoices player1Choice, player2Choice;
};
struct stGame {
	stRound Rounds[100];
	int roundsCount = 0;
	stPlayer player1;
	stPlayer player2;
};

int calculateDrawTimes(int total, int points1, int points2) {
	return total - (points1 + points2);
}
string findFinalWinner(stGame& game) {
	if (game.player1.TotalScore > game.player2.TotalScore)
		return game.player1.Name;
	if (game.player2.TotalScore > game.player1.TotalScore)
		return game.player2.Name;
	else
		return "No Winner";
}
void endGame(stGame& game) {
	cout << "\n\n";
	cout << "**********************************************************\n\n\n";
	cout << "--------------------------------------------------------\n";
	cout << "                   Game Over                 \n";
	cout << "--------------------------------------------------------\n\n";
	cout << "-------------------Game Result--------------------------\n";
	cout << "	Game Rounds :" << game.roundsCount << "\n";
	cout << "	" << game.player1.Name << " won times:" << game.player1.TotalScore << "\n";
	cout << "	" << game.player2.Name << " won times:" << game.player2.TotalScore << "\n";
	cout << "	Draw times:"
		<< calculateDrawTimes(game.roundsCount, game.player1.TotalScore, game.player2.TotalScore) << "\n";
	cout << "	Final Winner :  [" << findFinalWinner(game) << "]\n";
	cout << "**********************************************************\n\n\n";
}
int computerChoice() {
	return generateRandomNumbers(1, 3);
}
int userChoice() {
	return(readNumberInRangeMsg("Your choice -> [1]:Stone , [2]:Paper , [3] Scissors ?", 1, 3));
}
enChoices matchChoices(int choice) {
	switch (choice)
	{
	case 1:return enChoices::Stone;
	case 2:return enChoices::Paper;
	case 3:return enChoices::Scissors;
	}
}
string matchChoicesNames(int choice) {
	switch (choice)
	{
	case 1:return "Stone";
	case 2:return "Paper";
	case 3:return "Scissors";
	}
}
void findTheWinner(stGame& game, stRound& round) {
	if (round.player1Choice == enChoices::Paper) {
		if (round.player2Choice == enChoices::Stone)
			round.Winner = game.player1.ID;
		else if (round.player2Choice == enChoices::Scissors)
			round.Winner = game.player2.ID;
		else
			round.Winner = -1;
	}
	else if (round.player1Choice == enChoices::Stone) {
		if (round.player2Choice == enChoices::Scissors)
			round.Winner = game.player1.ID;
		else if (round.player2Choice == enChoices::Paper)
			round.Winner = game.player2.ID;
		else
			round.Winner = -1;
	}
	else if (round.player1Choice == enChoices::Scissors) {
		if (round.player2Choice == enChoices::Paper)
			round.Winner = game.player1.ID;
		else if (round.player2Choice == enChoices::Stone)
			round.Winner = game.player2.ID;
		else
			round.Winner = -1;
	}

}
void scoreRoundUp(stGame& game, stRound& round) {
	if (round.Winner == game.player1.ID)
		game.player1.TotalScore++;
	else
		if (round.Winner == game.player2.ID)
			game.player2.TotalScore++;
}
void printRoundResult(stGame& game, stRound& round) {
	cout << "\n----------------------Round [" << round.RoundOrder << "]-------------------------\n";
	cout << game.player1.Name << " Choice : " << matchChoicesNames(round.player1Choice) << "\n";
	cout << game.player2.Name << " Choice : " << matchChoicesNames(round.player2Choice) << "\n";
	if (round.Winner == game.player1.ID) {
		cout << "Round Winner : [" << game.player1.Name << "]\n";
		system("color 2F");
	}
	else if (round.Winner == game.player2.ID) {
		cout << "Round Winner : [" << game.player2.Name << "]\n";
		system("color 4F");
		cout << "\a";
	}
	else {
		cout << "Round Winner : [No Winner] \n";
		system("color 6F");
	}
	cout << "--------------------------------------------------------\n\n";
}
void beginRound(int roundOrder, stRound& round) {
	round.RoundOrder = roundOrder;
	cout << "Round[" << round.RoundOrder << "] begins :\n\n";
	round.player1Choice = matchChoices(userChoice());
	round.player2Choice = matchChoices(computerChoice());
}
void startGame() {
	stGame game;
	game.roundsCount = readNumberInRangeMsg("How many rounds from 1 to 10 ? ", 1, 10);
	cout << endl;
	game.player1.ID = 1;
	game.player2.ID = 2;
	game.player1.Name = "Player 1";
	game.player2.Name = "Computer";
	for (int counter = 0;counter < game.roundsCount;counter++) {
		beginRound(counter + 1, game.Rounds[counter]);
		findTheWinner(game, game.Rounds[counter]);
		scoreRoundUp(game, game.Rounds[counter]);
		printRoundResult(game, game.Rounds[counter]);
	}
	endGame(game);
}
bool wantPlayAgain() {
	char playAgain = 'N';
	cout << "\n\nDo you want to play again? Y / N \n";
	cin >> playAgain;
	if (playAgain == 'Y') {
		return true;
	}
	else
	{
		return false;
	}
}
void resetScreen() {
	system("cls");
	system("color 0F");
}
void startProgram(){
	do {
		resetScreen();
		startGame();
	} while (wantPlayAgain());
}
int main() {
	srand(time(NULL));
  startProgram();
	return 0;
}
