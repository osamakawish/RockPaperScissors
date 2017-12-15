#include <iostream>
#include <random>
#include <map>
#include <iterator>
#include <locale>	// Convert characters to uppercase.
using namespace std;

const string QUIT = "QUIT";
const enum rpsChoice { Rock, Paper, Scissors };
const map<string, rpsChoice> stringRPS = { { "ROCK", Rock } , { "PAPER" , Paper } , {"SCISSORS", Scissors } };

bool contains(map<string, rpsChoice> M, string x) {
	auto iterate = M.begin(); 
	auto toFind = M.find(x);

	while (iterate != M.end()) {
		if (iterate == toFind) { return true; }
		iterate++;
	}

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
	cout << "Pick rock, paper, or scissor. (Type your choice)" << endl;

	// Add that QUIT needs to be typed to quit game.
	cout << "Type 'QUIT' to quit game." << endl;
	getline(cin, input); cout << endl << endl;

	// Update Input
	Input = toUpper(input);
}

int main() {
	// input: The input provided by the user.
	// Input: An all uppercase string of input, to make the game case insensitive.
	string input; string Input; 
	prompt(input, Input); Input = toUpper(input);

	// Repeat until input == QUIT.
	while (Input != QUIT || contains(stringRPS, Input)) {
		prompt(input, Input); Input = toUpper(input);

		// Get computer to select from RPS

		// Update wins, losses, and draws.

	}
}