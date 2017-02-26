/*
 * Property.h
 *
 *  Created on: Apr 1, 2015
 *      Author: jacobmb
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include <iostream>
#include <string>

using namespace std;

class Property {
protected:
	string address;
	double value;
	bool rented;
	int id;
	int lastPayed;
	static constexpr int TAXBRACKETCUTOFF = 1000000;
	static constexpr int SHORTTAXPERIOD = 60;
	static constexpr int LONDTAXPERIOD = 90;
public:
	Property(const string address = "", const double value = 0, const bool rented = 0, const int id = -1, const int& lastPayed = 0);
	virtual ~Property(){};
	const int getLastPayed();
	const string getAddress();
	const int getId();
	const double getValue();
	virtual const int getTaxDeadline();
	virtual const string toString();
	virtual double const getTaxes() = 0;
};

#endif /* PROPERTY_H_ */
