/*
 * main.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: jacobmb
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Car.h"
/* test cases
 * TEST CASE 1
 * 		commands: 8
 *
 * TEST CASE 2
 * 		commands: 1 6
 * 			file name: cars1.txt
 * 		commands: 1 8
 * TEST CASE 3
 * 		commands: 1 6
 * 			file name: cars1.txt
 * 		commands: 1 5
 * 			file name: cars3.txt
 * 		commands: 1 5
 * 			name: pinto
 * 			color: blue
 * 		commands: 1 8
 */
using namespace std;
// FIND - searches for a car with the same name
int find(string name, vector<Car*> lot) {
	for (int i = 0; i < lot.size(); i++) {
		if (lot[i]->getName() == name)
			//car was found returning position
			return i;
	}
	return -1;
}

int main() {
	double balance = 10000;
	// holds all pointers to wars that are owned by the dealership
	vector<Car*> lot;
	char command = '_';
	do {
		if (command == '1') {
			//selection 1 - show inventory
			cout << " 1 - Show Current Inventory" << endl;
			for (int i = 0; i < lot.size(); i++) {
				cout << lot[i]->toString();
			}
		} else if (command == '2') {
			//selection 2 - show current balance
			cout << " 2 - Show Current Balance" << endl;
			cout << balance;
		} else if (command == '3') {
			//selection 3 - buy a car
			cout << " 3 - Buy a Car" << endl;
			cout << "enter the name of a car: ";
			string name;
			cin >> name;
			cout << "enter the color of the car: ";
			string color;
			cin >> color;
			cout << "enter the cost of the car: ";
			double cost;
			cin >> cost;
			// checks if car is owned
			if (find(name, lot) != -1) {
				cout << "car already owned!" << endl;
			// checks if we have money to by the car
			} else if (cost > balance) {
				cout << "not enough money!" << endl;
			// buys new car
			} else {
				lot.push_back(new Car(name, color, cost));
				balance -= cost;
				cout << "car bought!" << endl;
			}
		} else if (command == '4') {
			//selection 4 - sell a car
			cout << " 4 - Sell a Car" << endl;
			cout << "enter the name of a car: ";
			string name;
			cin >> name;
			int pos = find(name, lot);
			// checks if car is owned so it can be sold
			if (pos == -1) {
				cout << "car not owned!" << endl;
			} else {
				balance += lot[pos]->getPrice();
				delete lot[pos];
				lot.erase(lot.begin() + pos);
				cout << "car sold!" << endl;
			}
		} else if (command == '5') {
			//selection 5 - paint a car
			cout << " 5 - Paint a Car" << endl;
			cout << "enter the name of a car: ";
			string name;
			cin >> name;
			int pos = find(name, lot);
			// checks to see if we own the car
			if (pos == -1) {
				cout << "car not owned!" << endl;
			} else {
				cout << "enter the color of the car: ";
				string color;
				cin >> color;
				lot[pos]->paint(color);
				cout << "car painted!" << endl;
			}
		} else if (command == '6') {
			//selection 6 - add cars from a file
			cout << "enter the file name: ";
			string fileName;
			cin >> fileName;
			ifstream inFile;
			//opens the new dealership file
			inFile.open(fileName.c_str());

			string name;
			string color;
			double cost;
			inFile >> cost;
			balance += cost;
			while (inFile >> name >> color >> cost) {
				lot.push_back(new Car(name, color, cost));
			}
			inFile.close();
			cout << "file read!" << endl;
		} else if (command == '7') {
			cout << "enter the file name: ";
			string fileName;
			cin >> fileName;
			ofstream outFile;
			//opens the file to be saved
			outFile.open(fileName.c_str());
			outFile << balance << endl;
			//looks through the vector and saves each car
			for (int i = 0; i < lot.size(); i++) {
				outFile << lot[i]->getName() << ' ' << lot[i]->getColor() << ' '
						<< lot[i]->getPrice() << endl;
			}
			outFile.close();
			cout << "file created!" << endl;
		} else if (command == '8') {
			cout << " 8 - Quit Program" << endl;
			break;
		}
		// PRINT MENU
		cout << " 1 - Show Current Inventory" << endl;
		cout << " 2 - Show Current Balance" << endl;
		cout << " 3 - Buy a Car" << endl;
		cout << " 4 - Sell a Car" << endl;
		cout << " 5 - Paint a Car" << endl;
		cout << " 6 - Load File" << endl;
		cout << " 7 - Save File" << endl;
		cout << " 8 - Quit Program" << endl;
		cout << "please enter a command" << endl;
		// get user command
		cin >> command;
	} while (command != '8');
	return 0;
}
