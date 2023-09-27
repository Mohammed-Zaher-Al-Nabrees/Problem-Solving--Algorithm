#include<iostream>
#include"myLibrary.h"
using namespace std;

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };
enum enDifficultyLevel { Easy = 1, Med = 2, Hard = 3, MixDif = 4 };
struct stQuestion {
	enOperationType Operation = enOperationType::Add;
	enDifficultyLevel Difficulty = enDifficultyLevel::Easy;
	int ID = 0;
	int Order = 0;
	int Operand1 = 0;
	int Operand2 = 0;
	int TrueAnswer = 0;
};
struct stQuiz {
	enOperationType Operation = enOperationType::Mix;
	enDifficultyLevel Difficulty = enDifficultyLevel::MixDif;
	stQuestion Questions[100];
	int QuestionsNumbers = 0;
	int TotalScore = 0;
};
enOperationType matchOperationType(int opr) {
	switch (opr)
	{
	case 1:
		return enOperationType::Add;
	case 2:
		return enOperationType::Sub;
	case 3:
		return enOperationType::Mul;
	case 4:
		return enOperationType::Div;
	default:
		return enOperationType::Mix;
	}
}
enDifficultyLevel matchDifficulties(int level) {
	switch (level)
	{
	case 1:
		return enDifficultyLevel::Easy;
	case 2:
		return enDifficultyLevel::Med;
	case 3:
		return enDifficultyLevel::Hard;
	default:
		return enDifficultyLevel::MixDif;
	}
}
string matchOperationTypeName(enOperationType op) {
	switch (op)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mul:
		return "*";
	case enOperationType::Div:
		return  "/";
	case enOperationType::Mix:
		return  "Mix";
	default:
		return  "Mix";
	}
}
string matchDifficultiesName(enDifficultyLevel level) {
	switch (level)
	{
	case enDifficultyLevel::Easy:
		return "Easy";
	case enDifficultyLevel::Med:
		return "Med";
	case enDifficultyLevel::Hard:
		return "Hard";
	case enDifficultyLevel::MixDif:
		return  "Mix";
	default:
		return  "Mix";
	}
}
int wrongAnswersNumbers(stQuiz& Quiz) {
	return Quiz.QuestionsNumbers - Quiz.TotalScore;
}
void printQuizSummary(stQuiz& Quiz){
	string tabs = "   ";
	cout << tabs << "Number of questions : " << Quiz.QuestionsNumbers << "\n";
	cout << tabs << "Questions level: " << matchDifficultiesName(Quiz.Difficulty) << "\n";
	cout << tabs << "OpType : " << matchOperationTypeName(Quiz.Operation) << "\n";
	cout << tabs << "Number of right answers : " << Quiz.TotalScore << "\n";
	cout << tabs << "Number of wrong answers : " << wrongAnswersNumbers(Quiz) << "\n";
}
bool isPass(stQuiz& Quiz) {
	return Quiz.TotalScore > (Quiz.QuestionsNumbers / 2);
}
void printQuizResult(stQuiz& Quiz){
	cout << "\n_____________________________________________________\n\n";
	cout << "   Final Result is ";

	if (isPass(Quiz)) {
		cout << "Pass :)\n";
		system("color 2F");
	}
	else {
		cout << "Fail :(\n";
		system("color 4F");
		cout << "\a";
	}
	cout << "\n_____________________________________________________\n";
}
void printQuestionResult(bool isCorrect,int trueAnswer) {
	if (isCorrect) {
		cout << "Right Answer :)\n";
		system("color 2F");
	}
	else
	{

		cout << "Wrong Answer :(\n";
		cout << "The right answer is: "<< trueAnswer<<"\n";
		system("color 4F");
		cout << "\a";
	}
}
bool correctAnswer(stQuiz& Quiz, stQuestion& Question, int Answer) {
	if (Answer == Question.TrueAnswer) {
		Quiz.TotalScore++;
		return true;
	}
	else {
		return false;
	}
}
int readAnswer() {
	return readNumberMsg("");
}
void printQuestionBody(stQuestion& Question) {
	cout << "\n";
	cout << Question.Operand1;
	cout << "\n";
	cout << Question.Operand2 << "  " << matchOperationTypeName(Question.Operation);
	cout << "\n_______________\n";
}
int calculateTrueAnswer(stQuestion& Question) {
	switch (Question.Operation)
	{
	case enOperationType::Add:
		return Question.Operand1 + Question.Operand2;
	case enOperationType::Sub:
		return Question.Operand1 - Question.Operand2;
	case  enOperationType::Mul:
		return Question.Operand1 * Question.Operand2;
	case  enOperationType::Div:
		return Question.Operand1 / Question.Operand2;
	default:
		return Question.Operand1 + Question.Operand2;
	}
}
int chooseOperand(enDifficultyLevel Difficulty) {
	switch (Difficulty)
	{
	case Easy:
		return generateRandomNumbers(1, 10);
	case Med:
		return generateRandomNumbers(10, 50);
	case Hard:
		return generateRandomNumbers(50, 100);
	default:
		return generateRandomNumbers(1, 10);
	}
}
void setupQuestion(stQuiz& Quiz, stQuestion& Question,int QuestionOrder) {
	Question.ID = QuestionOrder;
	Question.Order = QuestionOrder;
	if (Quiz.Difficulty != enDifficultyLevel::MixDif) {
		Question.Difficulty = Quiz.Difficulty;
	}
	else
	{
		Question.Difficulty = matchDifficulties(generateRandomNumbers(enDifficultyLevel::Easy, enDifficultyLevel::Hard));
	}
	if (Quiz.Operation != enOperationType::Mix) {
		Question.Operation = Quiz.Operation;
	}
	else
	{
		Question.Operation = matchOperationType(generateRandomNumbers(enOperationType::Add, enOperationType::Div));
	}
	Question.Operand1 = chooseOperand(Question.Difficulty);
	Question.Operand2 = chooseOperand(Question.Difficulty);
	Question.TrueAnswer = calculateTrueAnswer(Question);
}
void printQuestionTitle(stQuiz& Quiz, stQuestion& Question) {
	cout << "\nQuestion [" << Question.Order << "/" << Quiz.QuestionsNumbers << "]\n";
}
void startQuestions(stQuiz& Quiz) {
	stQuestion& currentQuestion= Quiz.Questions[0];
	for (int counter = 0;counter < Quiz.QuestionsNumbers;counter++) {
		currentQuestion = Quiz.Questions[counter];
		setupQuestion(Quiz, currentQuestion, counter + 1);
		printQuestionTitle(Quiz, currentQuestion);
		printQuestionBody(currentQuestion);
		printQuestionResult(correctAnswer(Quiz, currentQuestion, readAnswer()), currentQuestion.TrueAnswer);
	}
}
void setupQuiz(stQuiz& Quiz) {
	Quiz.QuestionsNumbers = readNumberInRangeMsg("How many questions do you want to answer [1-100] ?", 1, 100);
	Quiz.Operation = matchOperationType(readNumberInRangeMsg("Enter operation type [1]Add [2]Sub [3]Mul [4]Div [5]Mix ? ", 1, 5));
	Quiz.Difficulty = matchDifficulties(readNumberInRangeMsg("Enter questions level [1]Easy [2]Med [3]Hard [4]Mix ? ", 1, 4));
}
void startQuiz() {
	stQuiz Quiz;
	setupQuiz(Quiz);
	startQuestions(Quiz);
	printQuizResult(Quiz);
	printQuizSummary(Quiz);
}
bool wantPlayAgain() {
	char playAgain = 'N';
	cout << "\n\nDo you want to play again? Y / N \n";
	cin >> playAgain;
	if (playAgain == 'Y' || playAgain == 'y') {
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
void startProgram() {
	do {
		resetScreen();
		startQuiz();
	} while (wantPlayAgain());
}
int main() {
	srand(time(NULL));
	startProgram();
	return 0;
}
