/*
 * Commercial.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: jacobmb
 */

#include <string>
#include <sstream>

#include "Commercial.h"

using namespace std;

Commercial::Commercial(const string& address, const double& value,
		const bool& rented, const int& id, const double& discount) :
		Property(address, value, rented, id) {
	this->discount = discount;
}

const string Commercial::toString() {
	stringstream ss;
	ss << Property::toString();
	if(discount == 0) {
		ss << " NOT discounted";
	} else {
		ss << "Discounted Discount: " << discount;
	}
	return ss.str();
}
const double Commercial::getTaxes() {
	double tax = 0;
	if (rented)
		tax = 0.012 * value;
	else
		tax = 0.01 * value;
	return tax - tax * discount;
}
