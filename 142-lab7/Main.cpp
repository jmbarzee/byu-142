/*
 * Main.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: jacobmb
 *
 *      TEST CASE : 1
 *      	commands: 1,6
 *      TEST CASE : 2
 *      	commands: 1,4,4,4,4,4,4,4,4,4,4,5
 *      	During tournament: 1,1,2,1  3,2,1  2
 *      TEST CASE : 2
 *      	commands: 1,2
 *      	Adding: "Denny's"
 *      	commands: 3
 *      	Adding: "Wendey's"
 *      	Commands: 5
 *     		During tournament: 1,3,3,1,2,1  3,2,A,1  5,2
 *
 */

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int find(vector<string>& list, string name) {
	//FIND HERE
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == name)
			return i;
	}
	return -1;
}

void display(vector<string> list) {
	//DISPLAY VECTOR HERE
	for (int i = 0; i < list.size(); i++) {
		cout << list[i];
		if (i < list.size()-1)
			cout << ',';
	}
	cout << endl;
}

void add(vector<string>& list) {
	//ADD VECTOR HERE
	cout << "Please enter the restaurant you would like to add the list"
			<< endl;
	string name;
	cin.ignore();
	getline(cin, name);
	int pos = find(list, name);
	if (pos == -1) {
		list.push_back(name);
		cout << name << " has been added to the list" << endl;
	} else {
		cout << name << " is already in the list" << endl;
	}
}

void remove(vector<string>& list) {
	//ADD VECTOR HERE
	cout << "Please enter the restaurant you would like to add the list"
			<< endl;
	string name;
	cin.ignore();
	getline(cin, name);
	int pos = find(list, name);
	if (pos == -1) {
		cout << name << " is not in the list" << endl;\
	} else {
		list.erase(list.begin() + pos);
		cout << name << " has been removed to the list" << endl;
	}
}

void shuffle(vector<string>& list) {
	//ADD SHUFFLE LIST HERE
	string tempName;
	for (int i = 0; i < list.size() * 2; i++) {
		int pos1 = rand() % list.size();
		int pos2 = rand() % list.size();
		tempName = list[pos1];
		list[pos1] = list[pos2];
		list[pos2] = tempName;
	}
}

bool tournament(vector<string>& list) {
	//ADD TOURNY HERE
	int roundT = 1; // starts at 1 to account for the final match
	int round = 0;
	double i;
	for (i = list.size(); i > 2; i/=2) { // this loop both finds the number of rounds and finds if it is a valid tournament
		roundT++;
	}
	if (i != 2) {
		return false;
	}
	//RUN TOURNAMENT
	while (list.size() > 1) { // this loop runs every time we need to do a round
		round++;
		int matchT = list.size() / 2;
		for (int match = 0; match < matchT; match++) { //  this loop runs every time we need to do a match
			cout << "Match " << match + 1 << '/' << matchT << ", Round "
					<< round << '/' << roundT;
			cout << " --- 1: " << list[match] << " or 2: " << list[match + 1]
					<< '?';
			char winner;
			do {
				cin >> winner;
				if (winner != '1' && winner != '2')
					cout << "Invalid response (" << winner << ")" << endl;
			} while (winner != '1' && winner != '2');
			if (winner == '1') {
				list.erase(list.begin() + match + 1);
			} else if (winner == '2') {
				list.erase(list.begin() + match);
			}
		}
	}
	cout << list[0] << " is the winner!" << endl;
	return true;
}

int main() {
	srand(time(0));
	vector<string> list;
	list.push_back("McDondald's");
	list.push_back("Little Ceaser's");
	list.push_back("Black Sheep Cafe");
	list.push_back("Wendey's");
	list.push_back("Gloria's Little Italy");
	list.push_back("Taco Time");
	list.push_back("Big Jud's");
	list.push_back("Gringo's");
	char command = '_';
	do {
		if (command == '1') {
			cout << "  1 - Display the restaurants" << endl;
			display(list);
		} else if (command == '2') {
			cout << "  2 - Add a restaurants" << endl;
			add(list);
		} else if (command == '3') {
			cout << "  3 - remove a restaurant" << endl;
			remove(list);
		} else if (command == '4') {
			cout << "  4 - shuffle the restaurants" << endl;
			shuffle(list);
		} else if (command == '5') {
			cout << "  5 - begin the tournament" << endl;
			if (tournament(list))
				break;
			cout << "Tournament can't run" << endl;
		} else if (command == '6') {
			break;
		} else {
			cout << "Possible commands are:" << endl;
			cout << "  1 - Display the restaurants" << endl;
			cout << "  2 - Add a restaurants" << endl;
			cout << "  3 - remove a restaurant" << endl;
			cout << "  4 - shuffle the restaurants" << endl;
			cout << "  5 - begin the tournament" << endl;
			cout << "  6 - quit" << endl;
		}
		cout << "please enter a command" << endl;
		cin >> command;
	} while (command != '6');
	cout << "  6 - quit" << endl;
	return 0;
}
