/*
 * main.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: jacobmb
 *
 *      Extra Credit! the hybrid must get atleast 166.6--- miles per gallon
 *
 *      TEST CASE 1: 10000, 2.5, 15000, 25, 11250, 32000, 166.6, 24000, gas
non-hybrid:
    gas: 2000
    cost: 8750
hybrid:
    gas: 300.012
    cost: 8750.03
 *      TEST CASE 2: 0, 10000, 0, 2.5, 0, 15000, 0, 25, 0, 11250, 0, 32000, 0, 166.6, 0, 24000, gas
non-hybrid:
    gas: 2000
    cost: 8750
hybrid:
    gas: 300.012
    cost: 8750.03
 *      TEST CASE 3: 10000, 100, 1, 1000, 1, 2, 500, 1, Cost
hybrid:
    gas: 5
    cost: 500
non-hybrid:
    gas: 10
    cost: 1001

 *
 */

#include <iostream>

using namespace std;

int main() {
	int miles = 0;
	double gasPrice = 0;
	// declare all the variables used by the hybrid
	double hybridPrice = 0, hybridEff = 0, hybridSale = 0;
	// declare all the variables used by the non-hybrid
	double carPrice = 0, carEff = 0, carSale = 0;
	// initialize criterion to an empty string
	string criterion = "";
	cout << "What is the estimated miles driven per year" << endl;
	cin >> miles;
	if (cin.fail() || miles < 1) {
		cout << "Bad input!" << endl;
		cout << "What is the estimated miles driven per year" << endl;
		cin >> miles;
	}
	cout << "What is the estimated price of a gallon of gas" << endl;
	cin >> gasPrice;
	if (cin.fail() || gasPrice < 1) {
		cout << "Bad input!" << endl;
		cout << "What is the estimated miles driven per year" << endl;
		cin >> miles;
	}
	cout << "What is the initial cost of a hybrid car" << endl;
	cin >> hybridPrice;
	if (cin.fail() || hybridPrice < 1) {
		cout << "Bad input!" << endl;
		cout << "What is the initial cost of a hybrid car" << endl;
		cin >> hybridPrice;
	}
	cout << "What is the efficiency of the hybrid car in miles per gallon"
			<< endl;
	cin >> hybridEff;
	if (cin.fail() || hybridEff < 1) {
		cout << "Bad input!" << endl;
		cout << "What is the efficiency of the hybrid car in miles per gallon"
				<< endl;
		cin >> hybridEff;
	}
	cout << "What is the estimated resale value for a hybrid" << endl;
	cin >> hybridSale;
	if (cin.fail() || hybridSale < 1) {
		cout << "Bad input!" << endl;
		cout << "What is the estimated resale value for a hybrid" << endl;
		cin >> hybridSale;

	}
	cout << "What is the initial cost of a non-hybrid car" << endl;
	cin >> carPrice;
	if (cin.fail() || carPrice < 1) {
		cout << "Bad input!" << endl;
		cout << "What is the initial cost of a non-hybrid car" << endl;
		cin >> carPrice;
	}
	cout << "What is the efficiency of the non-hybrid car in miles per gallon"
			<< endl;
	cin >> carEff;
	if (cin.fail() || carEff < 1) {
		cout << "Bad input!" << endl;
		cout
				<< "What is the efficiency of the non-hybrid car in miles per gallon"
				<< endl;
		cin >> carEff;
	}
	cout << "What is the estimated resale value for a non-hybrid" << endl;
	cin >> carSale;
	if (cin.fail() || carSale < 1) {
		cout << "Bad input!" << endl;
		cout << "What is the estimated resale value for a non-hybrid" << endl;
		cin >> carSale;

	}
	cout << "What is the buying criterion, either 'Gas' or 'Total'" << endl;
	cin >> criterion;
	int years = 5;
	double hybridGas = miles * years / hybridEff;
	double carGas = miles * years / carEff;
	double hybridCost = hybridPrice - hybridSale + hybridGas * gasPrice;
	double carCost = carPrice - carSale + carGas * gasPrice;
	// check to see how the data should be printed
	if (criterion == "Gas") {
		if (hybridGas < carGas) {
			//print out hybrid first
			cout << "hybrid:" << endl;
			cout << "    gas: " << hybridGas << endl;
			cout << "    cost: " << hybridCost << endl;
			cout << "non-hybrid: " << endl;
			cout << "    gas: " << carGas << endl;
			cout << "    cost: " << carCost << endl;
		} else {
			//print out non-hybrid first
			cout << "non-hybrid: " << endl;
			cout << "    gas: " << carGas << endl;
			cout << "    cost: " << carCost << endl;
			cout << "hybrid:" << endl;
			cout << "    gas: " << hybridGas << endl;
			cout << "    cost: " << hybridCost << endl;
		}

	} else if (criterion == "Total") {
		if (hybridCost < carCost) {
			//print out hybrid first
			cout << "hybrid:" << endl;
			cout << "    gas: " << hybridGas << endl;
			cout << "    cost: " << hybridCost << endl;
			cout << "non-hybrid: " << endl;
			cout << "    gas: " << carGas << endl;
			cout << "    cost: " << carCost << endl;
		} else {
			//print out non-hybrid first
			cout << "non-hybrid: " << endl;
			cout << "    gas: " << carGas << endl;
			cout << "    cost: " << carCost << endl;
			cout << "hybrid:" << endl;
			cout << "    gas: " << hybridGas << endl;
			cout << "    cost: " << hybridCost << endl;
		}

	}
	return 0;
}

