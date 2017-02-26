/*
 * Commercial.h
 *
 *  Created on: Apr 1, 2015
 *      Author: jacobmb
 */

#ifndef COMMERCIAL_H_
#define COMMERCIAL_H_

#include <iostream>
#include <string>

#include "Property.h"

using namespace std;

class Commercial: public Property {
public:
	double discount;
	static constexpr double COMMERCIALRENTED = 0.012;
	static constexpr double COMMERCIALNONRENTED = 0.01;
public:
	Commercial(const string& address = "", const double& value = 0,
			const bool& rented = 0, const int& id = -1, const double& discount =
					0, const int& lastPayed = 0);
	~Commercial() {};
	virtual const int getTaxDeadline();
	virtual const string toString();
	virtual const double getTaxes();
};

#endif /* COMMERCIAL_H_ */
