/*
 * Main.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: jacobmb
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

int main() {
	vector<Property*> properties;
	cout << "What is the file name? ";
	string fileName;
	cin >> fileName;
	fstream file(fileName.c_str());
	if (!file.is_open()) {
		cout << "File didn't open!" << endl;
		return 0;
	}
	int id = 0;
	while (!file.eof()) {
		string input;
		getline(file, input);
		stringstream ss(input);
		string type;
		ss >> type;
		if (ss.fail()) {
			cout << "Bad input!" << endl;
			cout << "   \"" << input << '\"' << endl;
			file.peek();
			continue;
		}
		if (type == "Commercial") {
			bool rental;
			ss >> rental;
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			double value;
			ss >> value;
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			bool discount;
			ss >> discount;
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			double discountRate;
			ss >> discountRate;
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			if (!discount)
				discountRate = 0;
			string address;
			getline(ss, address);
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			properties.push_back(
					new Commercial(address, value, rental, id, discountRate));
			id++;

		} else if (type == "Residential") {
			bool rental;
			ss >> rental;
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			double value;
			ss >> value;
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			bool occupied;
			ss >> occupied;
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			string address;
			getline(ss, address);
			if (ss.fail()) {
				cout << "Bad input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			properties.push_back(
					new Residential(address, value, rental, id, occupied));
			id++;
		} else {
			cout << "Bad input!" << endl;
			cout << "   \"" << input << '\"' << endl;
			file.peek();
		}
	}
	cout << endl << "      #### ALL VALID PROPERTIES ####" << endl;
	for (int i = 0; i < properties.size(); i++) {
		cout << properties[i]->toString() << endl << endl;
	}

	vector<Property*> temp;
	cout << "'1' to sort by taxes" << endl << "'2' to sort by address" << endl;
	char option;
	cin >> option;
	if (option == '1') {
		while (properties.size() > 0) {
			double lowest = properties[0]->getTaxes();
			int lowestPos = 0;
			for (int i = 1; i < properties.size(); i++) {
				if (properties[i]->getTaxes() < lowest) {
					lowestPos = i;
					lowest = properties[i]->getTaxes();
				}
			}
			temp.push_back(properties[lowestPos]);
			properties.erase(properties.begin() + lowestPos);
		}
	} else if (option == '2') {
		while (properties.size() > 0) {
			string lowest = properties[0]->getAddress();
			int lowestPos = 0;
			for (int i = 1; i < properties.size(); i++) {
				stringstream ss1(lowest);
				stringstream ss2(properties[i]->getAddress());
				string num1;
				string num2;
				ss1 >> num1;
				ss2 >> num2;
				string let1;
				string let2;
				let1 = ss1.str();
				let2 = ss2.str();
				if (num2 < num1) {
					lowestPos = i;
					lowest = properties[i]->getAddress();
				} else if (num2 == num1) {
					if (let2 < let1) {
						lowestPos = i;
						lowest = properties[i]->getAddress();
					}
				}
			}
			temp.push_back(properties[lowestPos]);
			properties.erase(properties.begin() + lowestPos);
		}
	} else {
		cout << "option not recognized!" << endl;
		cout << "order will remain the same..." << endl;
	}
	temp.swap(properties);

	for (int i = 0; i < properties.size(); i++) {
		cout << "** Taxes due for the property at: " << properties[i]->getAddress() << endl;
		cout << "\tProperty id: " << properties[i]->getId() << endl;
		cout << "\tEstimated value: " << properties[i]->getValue() << endl;
		cout << "\tTaxes due: " << properties[i]->getTaxes();
		cout << endl;
	}
	return 0;
}
