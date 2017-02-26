/*
 * Main.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: jacobmb
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

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
double getValue(double finalPos) {
	switch ((int)finalPos) {
	case 0:
	case 8:
		return 100;
	case 1:
	case 7:
		return 500;
	case 2:
	case 6:
		return 1000;
	case 3:
	case 5:
		return 0;
	case 4:
		return 10000;
	default:
		return 0;
	}
}
double dropMultiple(double startPos, int toDrop) {
	double money = 0;
	for (int i = 0; i < toDrop; i++)
		money += getValue(dropChip(startPos, false));
	return money;
}

int main() {
	srand(time(0));
	char option = ' ';
	while (option != '3') {
		cout << "MENU: Please select one of the following options: " << endl;
		cout << "    1 - Drop a single chip into one slot" << endl;
		cout << "    2 - Drop multiple chips into one slot" << endl;
		cout << "    3 - Quit the program" << endl;
		cout << "Enter your selection: ";
		cin >> option;
		if (option == '1') {
			cout << "SIMGLE: please enter where the chip will drop from: " << endl;
			int pos = ' ';
			cin >> pos;
			if (pos < 0 || pos > 8) {
				cout << "INVALID position" << endl;
				continue;
			}
			cout << "Winnings: " << getValue(dropChip(pos, true)) << endl;
		} else if (option == '2') {
			cout << "MULTIPLE: please enter how many chips will be dropped: " << endl;
			int num = 0;
			cin >> num;
			if (num < 1) {
				cout << "INVALID number" << endl;
				continue;
			}
			 cout << "    please enter where the chips will drop from: " << endl;
			int pos = ' ';
			cin >> pos;
			if (pos < 0 || pos > 8) {
				cout << "INVALID position" << endl;
				continue;
			}
			double money = dropMultiple(pos, num);
			cout << "    Total Winnings on " << num << " chips: $" << fixed << setprecision(2) << money << endl;
			cout << "    Average Winnings: $" << fixed << setprecision(2) << money / (double)num << endl;
		} else if (option == '3') {
			cout << "GOODBYE!" << endl;
			break;
		} else {
			cout << "INVALID selection..." << endl;
		}
	}
	return 0;
}

