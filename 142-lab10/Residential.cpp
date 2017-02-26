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

Residential::Residential(const string& address, const double& value, const bool& rented, const int& id, const bool& occupied) :Property(address, value, rented, id) {
	this->occupied = occupied;
}

const string Residential::toString() {
	stringstream ss;
	ss << Property::toString();
	if(this->occupied)
		ss << " Occupied ";
	else
		ss << " Vacant ";
	return ss.str();
}

const double Residential::getTaxes() {
	if(occupied)
		return 0.006 * value;
	else
		return 0.009 * value;
}

