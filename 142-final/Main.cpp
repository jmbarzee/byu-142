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
#include <cctype>
#include <fstream>
#include <vector>

#include "Property.h"
#include "Residential.h"
#include "Commercial.h"
#include "Farm.h"

using namespace std;

//used to make sure commercial Commercial and COMMERCIAL all build a commercial property
//also true for farm and residential
void toUpper(string & input) {
	for (int i =0; i < input.size(); i++)
		input[i] = toupper(input[i]);
}

int main() {
	vector<Property*> properties;
	cout << "What is the file name? ";
	string fileName;
	cin >> fileName;
	fstream file(fileName.c_str());
	//checks for file opening will exit upon bad file name
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
		//see toUpper function above
		toUpper(type);
		if (ss.fail()) {
			cout << "Bad Unknown input!" << endl;
			cout << "   \"" << input << '\"' << endl;
			file.peek();
			continue;
		}
		if (type == "COMMERCIAL") {
			//begin to extract data for a commercial object
			bool rental;
			double value;
			int lastPayed;
			bool discount;
			double discountRate;
			ss >> rental >> value >> lastPayed >> discount >> discountRate;
			if (!discount)
				discountRate = 0;
			string address;
			getline(ss, address);
			//check if data was bad
			if (ss.fail()) {
				cout << "Bad commercial input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			//add new commercial object to the vector
			properties.push_back(
					new Commercial(address, value, rental, id, discountRate,
							lastPayed));
			id++;
		} else if (type == "RESIDENTIAL") {
			//begin to extract data for a residential object
			bool rental;
			double value;
			int lastPayed;
			bool occupied;
			ss >> rental >> value >> lastPayed >> occupied;
			string address;
			getline(ss, address);
			//check if data was bad
			if (ss.fail()) {
				cout << "Bad residential input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			//add new residential object to the vector
			properties.push_back(
					new Residential(address, value, rental, id, occupied,
							lastPayed));
			id++;
		} else if (type == "FARM") {
			//begin to extract data for a farm object
			bool rental;
			double value;
			int lastPayed;
			ss >> rental >> value >> lastPayed;
			string address;
			getline(ss, address);
			//check if data was bad
			if (ss.fail()) {
				cout << "Bad farm input!" << endl;
				cout << "   \"" << input << '\"' << endl;
				file.peek();
				continue;
			}
			//add new farm object to the vector
			properties.push_back(
					new Farm(address, value, rental, id,
							lastPayed));
			id++;

		} else {
			// data was bad
			cout << "Bad Unknown input!" << endl;
			cout << "   \"" << input << '\"' << endl;
			file.peek();
		}
	}
	//pump ot all the valid properties
	cout << endl << "      #### ALL VALID PROPERTIES ####" << endl;
	for (int i = 0; i < properties.size(); i++) {
		cout << properties[i]->toString() << endl << endl;
	}

	//all sorts are implemented poorley, but do work
	vector<Property*> temp;
	cout << "'1' to sort by taxes" << endl;
	cout << "'2' to sort by address" << endl;
	cout << "'3' to sort by deadline" << endl;
	cout << "'4' to sort by last payment" << endl;
	cout << "'5' to sort by property ID" << endl;
	char option;
	cin >> option;
	if (option == '1') {
		//sort by taxes
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
		//sort by address
		while (properties.size() > 0) {
			string lowest = properties[0]->getAddress();
			int lowestPos = 0;
			for (int i = 1; i < properties.size(); i++) {
				//used to sort by number and then street
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
	} else if(option == '3') {
		//sort by tax deadline
		while (properties.size() > 0) {
			int lowest = properties[0]->getTaxDeadline();
			int lowestPos = 0;
			for (int i = 1; i < properties.size(); i++) {
				if (properties[i]->getTaxDeadline() < lowest) {
					lowestPos = i;
					lowest = properties[i]->getTaxDeadline();
				}
			}
			temp.push_back(properties[lowestPos]);
			properties.erase(properties.begin() + lowestPos);
		}
	} else if(option == '4') {
		//sort by taxes last payed
		while (properties.size() > 0) {
			int lowest = properties[0]->getLastPayed();
			int lowestPos = 0;
			for (int i = 1; i < properties.size(); i++) {
				if (properties[i]->getLastPayed() < lowest) {
					lowestPos = i;
					lowest = properties[i]->getLastPayed();
				}
			}
			temp.push_back(properties[lowestPos]);
			properties.erase(properties.begin() + lowestPos);
		}
	} else if(option == '5') {
		//sort by IDs
		while (properties.size() > 0) {
			int lowest = properties[0]->getId();
			int lowestPos = 0;
			for (int i = 1; i < properties.size(); i++) {
				if (properties[i]->getId() < lowest) {
					lowestPos = i;
					lowest = properties[i]->getId();
				}
			}
			temp.push_back(properties[lowestPos]);
			properties.erase(properties.begin() + lowestPos);
		}
	} else {
		//sort by IDs --- sort of (pun)
		cout << "option not recognized!" << endl;
		cout << "order will remain sorted by ID" << endl;
		temp.swap(properties);
	}
	//place sorted properties back into final vector
	temp.swap(properties);

	// spit out all properties held with computed taxes and future deadline
	for (int i = 0; i < properties.size(); i++) {
		cout << "** Taxes due for the property at:"
				<< properties[i]->getAddress() << endl;
		cout << "\tProperty id:     " << properties[i]->getId() << endl;
		cout << "\tEstimated value: " << properties[i]->getValue() << endl;
		cout << "\tLast Payment     " << properties[i]->getLastPayed() << endl;
		cout << "\tTaxes due are:   " << properties[i]->getTaxes() << endl;
		cout << "\tTaxes due in:    " << properties[i]->getTaxDeadline() << endl;
	}
	return 0;
}
