/*
 * Main.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: jacobmb
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

void initialize(double plate[20][20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if ((i == 0 || i == 19) && j != 0 && j != 19)
				plate[i][j] = 100;
			else
				plate[i][j] = 0;
		}
	}
}
void print(double plate[20][20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
			cout << fixed << setprecision(1) << setw(6) << plate[i][j];
		cout << endl;
	}
}
double average(double plate[20][20], double newPlate[20][20]) {
	double change = 0;
	for (int i = 1; i < 19; i++) {
		for (int j = 1; j < 19; j++) {
			newPlate[i][j] = (plate[i - 1][j] + plate[i][j - 1]
					+ plate[i + 1][j] + plate[i][j + 1]) / 4;
			if (abs(newPlate[i][j] - plate[i][j]) > change)
				change = abs(newPlate[i][j] - plate[i][j]);
		}
	}
	return change;

}
void swap(double plate[20][20], double newPlate[20][20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			double temp = plate[i][j];
			plate[i][j] = newPlate[i][j];
			newPlate[i][j] = temp;
		}
	}
}
void toFile(double plate[20][20], string fileName) {
	ofstream file(fileName.c_str());
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
			file << fixed << setprecision(1) << setw(6) << plate[i][j] << ',';
		if (i < 19)
			file << endl;
	}
}

int main() {
	double plate[20][20];
	initialize(plate);
	print(plate);
	double newPlate[20][20];
	initialize(newPlate);
	double change = average(plate, newPlate);
	print(newPlate);
	swap(plate, newPlate);
	while (change > 0.1) {
		change = average(plate, newPlate);
		if (change > 0.1)
			swap(plate, newPlate);
	}
	toFile(newPlate, "lab6output.csv");
	return 0;
}

