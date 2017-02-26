/*
 * Property.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: jacobmb
 */
#include <string>
#include <sstream>

#include "Property.h"

using namespace std;

Property::Property(const string address, const double value, const bool rented,
		const int id) {
	this->address = address;
	this->value = value;
	this->rented = rented;
	this->id = id;
}
const string Property::getAddress() {
	return address;
}
const int Property::getId() {
	return id;
}
const double Property::getValue() {
	return value;
}
const string Property::toString() {
	stringstream ss;
	ss << "Property Id: " << id << " Address: " << address;
	if (rented)
		ss << " Rental ";
	else
		ss << " NOT Rental ";
	ss << " Value: " << value;
	return ss.str();
}
