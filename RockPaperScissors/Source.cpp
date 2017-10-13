#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <cctype>
using namespace std;

const string QUIT = "QUIT";
set<string> OPTIONS = {"ROCK", "PAPER", "SCISSORS"};

void prompt(string &input) {
	cout << "Pick rock, paper, or scissor. (Type your choice)" << endl;
	cout << "Type 'QUIT' to quit game." << endl;
	getline(cin, input); cout << endl << endl;
}

string toUpper(string s) {
	string toReturn;

	for (int i = 0; i < s.length; i++)
	{

	}
	return s;
}

int main() {
	string input;
	prompt(input);

	// Repeat until input == QUIT.
	while (toUpper(input) != QUIT) {

	}
	
	// Ask for user to pick from rock, papers, scissors.
	// Add that QUIT needs to be typed to quit game.

	// Repeat Q if user does not pick one of three.

	// Get computer to select from RPS

	// Update wins, losses, and draws.

}