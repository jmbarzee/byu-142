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
/*
 * constructor
 * can take anywhere from all to no parameters
 */
Commercial::Commercial(const string& address, const double& value,
		const bool& rented, const int& id, const double& discount, const int& lastPayed) :
		Property(address, value, rented, id, lastPayed) {
	this->discount = discount;
}
/*
 * returns tax specific deadline
 */
const int Commercial::getTaxDeadline() {
	return Property::getTaxDeadline();
}
/*
 * appends commercial relevent data after it has been appened to the property to string data
 */
const string Commercial::toString() {
	stringstream ss;
	ss << Property::toString();
	if(discount == 0) {
		ss << " NOT discounted";
	} else {
		ss << " Discounted Discount: " << discount;
	}
	return ss.str();
}
/*
 * returns commercial specific taxes
 */
const double Commercial::getTaxes() {
	double tax = 0;
	if (rented)
		tax = COMMERCIALRENTED * value;
	else
		tax = COMMERCIALNONRENTED * value;
	return tax - tax * discount;
}
