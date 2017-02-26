/*
 * Main.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: jacobmb
 *
 *      TEST CASE 1: 1, 9, 1, -1, 3
 *      drop 1 chip in slot 9(won't work) drop 1 chip in slot -1 (won't work) quit
 *      TEST CASE 2: 1, 8, 1, 0, 3
 *      drop 1 chip in slot 8, drop 1 chip in slot 0, quit
 *      TEST CASE 3: 2, 50, 0, 2, 100, 8, 2, -1, 2, 1, -1, 3
 *      drop 50 chips in slot 0, drop 100 chips in slot 8, drop 1 chip in slot -1, drop 1 chips in slot 9 quit
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
// drops a single chip, will print chip position if givin "TRUE"
double dropChip(double Pos, bool print) {
	if (print)
		cout << "Path: [";
	for (int i = 0; i < 12; i++) {
		if (print)
			cout << fixed << setprecision(1) << Pos << ' ';
		if (Pos == 8)
			Pos = 7.5;
		else if (Pos == 0)
			Pos = 0.5;
		else if ((rand() % 2) == 0)
			Pos += 0.5;
		else
			Pos -= 0.5;
	}
	if (print)
		cout << setw(3) << Pos << ']' << endl;
	return Pos;
}
//uses a switch case to determine the winnings of a final position
double getValue(double finalPos) {
	int	case0or8 = 100;
	int case1or7 = 500;
	int case2or6 = 1000;
	int case3or5 = 0;
	int case4 = 10000;
	switch ((int)finalPos) {
	case 0:
	case 8:
		return case0or8;
	case 1:
	case 7:
		return case1or7;
	case 2:
	case 6:
		return case2or6;
	case 3:
	case 5:
		return case3or5;
	case 4:
		return case4;
	default:
		return case4;
	}
}
// calls both dropchip() and get getvalue() as many times as needed and will return the total winnings of a player
double dropMultiple(double startPos, int toDrop) {
	double money = 0;
	for (int i = 0; i < toDrop; i++)
		money += getValue(dropChip(startPos, false));
	return money;
}

int main() {
	srand(time(0));
	char option = ' ';
	while (option != '4') {
		cout << "MENU: Please select one of the following options: " << endl;
		cout << "    1 - Drop a single chip into one slot" << endl;
		cout << "    2 - Drop multiple chips into one slot" << endl;
		cout << "    3 - drop equal chips into all slots" << endl;
		cout << "    4 - Quit the program" << endl;
		cout << "Enter your selection: ";
		cin >> option;
		//option 1: single chips - prompts for position to drop from
		if (option == '1') {
			cout << "SINGLE: please enter where the chip will drop from: " << endl;
			int pos = ' ';
			cin >> pos;
			if (pos < 0 || pos > 8 || cin.fail()) {
				cin.clear();
				cout << "INVALID position" << endl;
				continue;
			}
			cout << "Winnings: " << getValue(dropChip(pos, true)) << endl;
		} else if (option == '2') {
			// option 2: multile chips - prompts for both number of chips and position of drop
			cout << "MULTIPLE: please enter how many chips will be dropped: " << endl;
			int num = 0;
			cin >> num;
			if (num < 1 || cin.fail()) {
				cin.clear();
				cout << "INVALID number" << endl;
				continue;
			}
			 cout << "    please enter where the chips will drop from: " << endl;
			int pos = ' ';
			cin >> pos;
			if (pos < 0 || pos > 8 || cin.fail()) {
				cin.clear();
				cout << "INVALID position" << endl;
				continue;
			}
			double money = dropMultiple(pos, num);
			cout << "    Total Winnings on " << num << " chips: $" << fixed << setprecision(2) << money << endl;
			cout << "    Average Winnings: $" << fixed << setprecision(2) << money / (double)num << endl;
		} else if (option == '3') {
			// option 3: all slots - drops equal number of chips into all slots with a for() loop
			cout << "ALL SLOTS: please enter how many chips will be dropped: " << endl;
			int num = 0;
			cin >> num;
			if (num < 1 || cin.fail()) {
				cin.clear();
				cout << "INVALID number" << endl;
				continue;
			}
			for(int i = 0; i<9; i++) {
				double money = dropMultiple(i, num);
				cout << "    Total Winnings in slot: " << i << endl;
				cout << "    With " << num << " chips: $" << fixed << setprecision(2) << money << endl;
				cout << "    Average Winnings: $" << fixed << setprecision(2) << money / (double)num << endl;
			}
		} else if (option == '4') {
			// option 4: quits
			cout << "GOODBYE!" << endl;
			break;
		} else {
			cout << "INVALID selection..." << endl;
		}
	}
	return 0;
}

