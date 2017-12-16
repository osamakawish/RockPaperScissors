#include <iostream>
#include <random>
#include <time.h>
#include <map>
#include <set>
#include <iterator>
#include <locale>	// Convert characters to uppercase.
using namespace std;





// Recorded statistics of the games played.
int wins = 0; int ties = 0; int losses = 0; int gamesPlayed;

// The quit constant.
const string QUIT = "QUIT"; 

// The Rock-Paper-Scissors Choices.
const enum rpsChoice { Rock, Paper, Scissors };
const map<string, rpsChoice> stringRPS = { { "ROCK", Rock } , { "PAPER", Paper } , {"SCISSORS", Scissors } };

const enum difficulty { Easy, Okay, Hard }; difficulty diff = Easy;
map<string, difficulty> difficulties = { {"EASY", Easy} , {"OKAY", Okay} , {"HARD", Hard} };

const enum result { Loss, Tie, Win };





// Check if the map contains a given key.
template <typename T>
bool contains(map<string, T> M, string x) {
	auto iterate = M.begin(); // Initiates the iterator.
	auto toFind = M.find(x); // The iterator to find.

	// Iterate over M until object is found.
	while (iterate != M.end()) {
		if (iterate == toFind) { return true; }
		iterate++;
	}

	// Return false if the end is reached without finding the object.
	return false;
}

// Converts a string to uppercase.
string toUpper(string s) {
	// Initiate the string to be returned.
	string toReturn = ""; 
	
	// Convert each character to uppercase.
	for each (char ch in s) { toReturn += toupper(ch); }
	
	return toReturn;
}

// Prompts a user to choose from rock, papers, or scissors.
// Then updates input to user's value.
void prompt(string &input, string &Input) {
	// Ask for user to pick from rock, papers, scissors.
	cout << "Pick rock, paper, or scissors. (Type your choice)" << endl;

	// Add that QUIT needs to be typed to quit game.
	cout << "Type 'QUIT' to quit game." << endl;
	getline(cin, input); cout << endl << endl;

	// Update Input
	Input = toUpper(input);
}

string toString(rpsChoice rps) {
	switch (rps)
	{
	case Rock: return "ROCK";
	case Paper: return "PAPER";
	case Scissors: return "SCISSORS";
	}
}

rpsChoice select(int i) {
	switch (i % 3)
	{
	case 0: return Rock; 
	case 1: return Paper;
	case 2: return Scissors;
	}
}

rpsChoice randSelect() {
	// Randomly select a number from 0 to 2.
	int r = rand() % 3;

	// Use the integer to select from RPS.
	return select(r);
}

// Compares choices and updates results.
result compare(rpsChoice mine, rpsChoice comp) {
	int val = mine - comp; 

	if (val % 3 == 0) { ties++; return Tie; }
	else if (val % 3 == 1) { wins++; return Win; }
	else { losses++; return Loss; }

	
}

rpsChoice dumbSelect(rpsChoice prevCompChoice) {
	return prevCompChoice;
}

// Make the smart selection based on previous choice made by the player.
rpsChoice smartSelect(rpsChoice prevPlayerChoice) {
	return prevPlayerChoice;
}

// The computer selects its non-inital choices.
rpsChoice compSelect(rpsChoice prevPlayerChoice, rpsChoice prevCompChoice) {
	int randPercent = rand() % 100;
	switch (diff)
	{
	case Easy: // Selects stronger choice 80% of the time.
		if (randPercent < 80) return dumbSelect(prevCompChoice);
		else return randSelect();
	case Okay: // Selects the random choice 100% of the time.
		return randSelect();
	case Hard:
		if (randPercent < 80) return smartSelect(prevPlayerChoice);
		else return randSelect();
	}
}

// The message returned by the computer's choice.
void compChoice(rpsChoice choice) {
	cout << "The computer picked " << toString(choice) << "." << endl;
}

void setDifficulty(string DIFF) {
	if (DIFF == "EASY") { diff = Easy; return; }
	if (DIFF == "OKAY") { diff = Okay; return; }
	if (DIFF == "HARD") { diff = Hard; return; }
}

void resultsMessage() {
	cout << endl;
	cout << "Wins:   " << wins << endl;
	cout << "Ties:   " << ties << endl;
	cout << "Losses: " << losses << endl << endl;
}

int main() {
	// The string for the difficulty of the game.
	string diffString;
	// Record of player choice and cpu choice to compromise difficulties.
	rpsChoice playerRPS; rpsChoice compRPS;

	// Random seed for RNG. To be used for random computer choice selection.
	srand(time(NULL));

	// Gets user to choose difficulty.
	cout << "Select the difficulty for the game: Easy, Okay, Hard." << endl;
	getline(cin, diffString);
	while (!contains(difficulties, toUpper(diffString)))
	{
		cout << "Select the difficulty for the game: Easy, Okay, Hard." << endl;
	}
	diff = difficulties[diffString]; // Sets the difficulty.

	// input: The input provided by the user.
	// Input: An all uppercase string of input, to make the game case insensitive.
	string input; string Input; 
	prompt(input, Input);

	// Repeat until input == QUIT 
	while (Input != QUIT) { 
		// Check if it is a rock, paper, or scissors string.
		if (contains(stringRPS, Input)) {
			// Store it inside variable.
			playerRPS = stringRPS.at(Input);

			// Computer selects from rock, papers, or scissors.
			if (gamesPlayed == 0) { compRPS = randSelect(); }
			else { compRPS = compSelect(playerRPS, compRPS); }

			// Output computer choice.
			compChoice(compRPS);

			// Update wins, losses, and draws. 
			compare(playerRPS, compRPS); // The compare method updates the results.

			// Display results thus far.
			resultsMessage();
		}

		// Prompt player to input again.
		else {
			cout << "Sorry. You must either QUIT or select from ROCK, PAPER, or SCISSORS." << endl;
			cout << "Your decision is case insensitive." << endl << endl;
		}
		prompt(input, Input);
		cout << endl;
	}
}