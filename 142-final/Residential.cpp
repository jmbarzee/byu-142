/*
 * Residential.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: jacobmb
 */

#include <string>
#include <sstream>

#include "Residential.h"

using namespace std;
/*
 * constructor
 * can take anywhere from all to no parameters
 */
Residential::Residential(const string& address, const double& value,
		const bool& rented, const int& id, const bool& occupied,
		const int& lastPayed) :
		Property(address, value, rented, id, lastPayed) {
	this->occupied = occupied;
}
/*
 * to string
 * add residential specific output
 */
const string Residential::toString() {
	stringstream ss;
	ss << Property::toString();
	if (this->occupied)
		ss << " Occupied ";
	else
		ss << " Vacant ";
	return ss.str();
}
/*
 * get taxes
 * returns residential specific taxes
 */
const double Residential::getTaxes() {
	if (occupied)
		return RESIDENTIALOCCUPIED * value;
	else
		return RESIDENTIALNONOCCUPIED * value;
}

