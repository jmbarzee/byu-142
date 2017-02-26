/*
 * Main.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: jacobmb
 */
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Player.h"

using namespace std;
/* TEST CASE 1
 * 		COMMANDS: 1,4,1,4,6
 * TEST CASE 2
 * 		COMMANDS: 1,2,"NAME1",2,"NAME2,4,3,NAME1,3,NAME2,4,5,4,6
 * TEST CASE 3
 * 		COMMANDS: 2,"NAME1",2,"NAME2,4,3,NAME1,3,NAME1,4,5,4,6
 */
const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;

/* getName
 * @return name with whitespaces
 */
string getName() {
	cout << "What is the name of the player? " << endl;
	string name;
	cin.ignore();
	getline(cin, name);
	return name;
}
/* find
 *  @param vector to be searched
 *  @param player searched for
 */
int find(vector<Player*> &toCheck, string name) {
	for (int i = 0; i < toCheck.size(); i++) {
		if (toCheck[i]->getName() == name) {
			return i;
		}
	}
	return -1;
}
/*	add new player
 * @param players to be added to
 * @param player to be added
 */
bool addNewPlayer(vector<Player*> &players, string name) {
	if (find(players, name) == -1) {
		players.push_back(new Player(name));
		return true;
	}
	return false;
}
/* move player
 * @param players to be taken from
 * @param players to be added to
 * @param player to be moved
 */
bool movePlayer(vector<Player*> &oldPlayers, vector<Player*> &newPlayers,
		string name) {
	int pos = find(oldPlayers, name);
	newPlayers.push_back(oldPlayers[pos]);
	return true;
}
/* Are you really looking at these?....? show players()
 * @param players vector of players to be shown
*/
void showPlayers(vector<Player*> &players) {
	for (int i = 0; i < players.size(); i++) {
		cout << " Position " << i << ": " << players[i]->getName() << endl;
		cout << "        Wins: " << players[i]->getWins() << endl;
		cout << "        Losses: " << players[i]->getLosses() << endl;
		cout << "        Draws: " << players[i]->getDraws() << endl;
		cout << "        Win Record: " << players[i]->getWinRecord() << endl;
	}
}
/* fight
 * @param vector of fighters
 */
bool fight(vector<Player*>& toFight) {
	if (toFight.size() < 2) {
		cout << "less then two players in bracket" << endl;
		return false;
	}
	if (toFight[0] == toFight[1]) {
		toFight[0]->addDraw();
		cout << toFight[0] << " fought himself..." << endl;
		toFight.erase(toFight.begin());
		toFight.erase(toFight.begin());
	} else {
		int player0 = toFight[0]->getRPSThrow();
		int player1 = toFight[1]->getRPSThrow();
		if (player0 == player1) {
			toFight[0]->addDraw();
			toFight[1]->addDraw();
			cout << toFight[0]->getName() << " and " << toFight[1]->getName()
					<< " both drew." << endl;
		} else if (player0 == ROCK) {
			if (player1 == PAPER) {
				cout << toFight[0]->getName() << " threw a rock and lost"
						<< endl;
				cout << toFight[0]->getName() << " threw a paper and won"
						<< endl;
				toFight[0]->addLoss();
				toFight[1]->addWin();
			} else if (player1 == SCISSORS) {
				cout << toFight[0]->getName() << " threw a rock and won"
						<< endl;
				cout << toFight[0]->getName() << " threw a scissor and lost"
						<< endl;
				toFight[0]->addWin();
				toFight[1]->addLoss();
			}
		} else if (player0 == PAPER) {
			if (player1 == SCISSORS) {
				cout << toFight[0]->getName() << " threw a paper and lost"
						<< endl;
				cout << toFight[0]->getName() << " threw a scissor and won"
						<< endl;
				toFight[0]->addLoss();
				toFight[1]->addWin();
			} else if (player1 == ROCK) {
				cout << toFight[0]->getName() << " threw a paper and won"
						<< endl;
				cout << toFight[0]->getName() << " threw a rock and lost"
						<< endl;
				toFight[0]->addWin();
				toFight[1]->addLoss();
			}
		} else if (player0 == SCISSORS) {
			if (player1 == ROCK) {
				cout << toFight[0]->getName() << " threw a scissor and lost"
						<< endl;
				cout << toFight[0]->getName() << " threw a rock and won"
						<< endl;
				toFight[0]->addLoss();
				toFight[1]->addWin();
			} else if (player1 == PAPER) {
				cout << toFight[0]->getName() << " threw a scissor and won"
						<< endl;
				cout << toFight[0]->getName() << " threw a paper and lost"
						<< endl;
				toFight[0]->addWin();
				toFight[1]->addLoss();
			}
		}
		toFight.erase(toFight.begin());
		toFight.erase(toFight.begin());
	}
	return true;
}
int main() {
	srand(time(0));
	vector<Player*> players;
	vector<Player*> queue;
	char command;
	do {
		if (command == '1') {
			cout << "1 - Show Players" << endl;
			showPlayers(players);
		} else if (command == '2') {
			cout << "2 - Add Player" << endl;
			string name = getName();
			if (find(players, name) != -1 || find(queue, name) != -1) {
				cout << "Player already in tournament" << endl;
			} else {
				addNewPlayer(players, name);
				cout << "Player added" << endl;
			}
		} else if (command == '3') {
			cout << "3 - Add To Line-up" << endl;
			string name = getName();
			if (find(players, name) != -1) {
				movePlayer(players, queue, name);
				cout << "Player added" << endl;
			} else {
				cout << "Player already in BRACKET" << endl;
			}
		} else if (command == '4') {
			cout << "4 - Show Line-up" << endl;
			showPlayers(queue);
		} else if (command == '5') {
			cout << "5 - Fight" << endl;
			fight(queue);
		} else if (command == '6') {
			cout << "6 - Quit" << endl;
			break;
		} else {
			cout << "command not recognized..." << endl;
		}
		cout << "1 - Show Players" << endl;
		cout << "2 - Add Player" << endl;
		cout << "3 - Add To Line-up" << endl;
		cout << "4 - Show Line-up" << endl;
		cout << "5 - Fight" << endl;
		cout << "6 - Quit" << endl;
		cout << "Please enter a command" << endl;
		cin >> command;
	} while (command != '6');
	return 0;
}

