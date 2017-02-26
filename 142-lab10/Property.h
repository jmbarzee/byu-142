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
public:
	Property(const string address = "", const double value = 0, const bool rented = 0, const int id = -1);
	~Property(){};
	const string getAddress();
	const int getId();
	const double getValue();
	virtual const string toString();
	virtual double const getTaxes() = 0;
};

#endif /* PROPERTY_H_ */
