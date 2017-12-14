#include <iostream>
#include <random>
#include <sstream>
#include <cctype>
#include <vector>
#include <locale>	// Convert characters to uppercase.
using namespace std;

const string QUIT = "QUIT";
const enum rpsChoice { Rock, Paper, Scissors };
const vector<rpsChoice> rpsCompare = { Rock, Paper, Scissors };

// Prompts a user to choose from rock, papers, or scissors;
void prompt(string &input) {
	// Ask for user to pick from rock, papers, scissors.
	cout << "Pick rock, paper, or scissor. (Type your choice)" << endl;

	// Add that QUIT needs to be typed to quit game.
	cout << "Type 'QUIT' to quit game." << endl;
	getline(cin, input); cout << endl << endl;
}


// Converts a string to uppercase.
string toUpper(string s) {
	// Initiate the string to be returned.
	string toReturn = ""; 
	
	for each (char ch in s)
	{
		// Convert each character to uppercase.
		toReturn += toupper(ch);
	}
	
	return toReturn;
}

// Converts a string to an RPS choice.
rpsChoice toRPS(string S) {
	if (S == "ROCK") return Rock;
	if (S == "PAPER") return Paper;
	if (S == "SCISSORS") return Scissors;

	else
	{
		throw exception("S is not an RPS choice.");
	}
}

int main() {
	string input;
	prompt(input);

	// Repeat until input == QUIT.
	while (toUpper(input) != QUIT) {

	}
	
	// Repeat Q if user does not pick one of three.

	// Get computer to select from RPS

	// Update wins, losses, and draws.

}