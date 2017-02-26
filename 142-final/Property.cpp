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
/*
 * constructor
 * can take anywhere from all to no parameters
 */
Property::Property(const string address, const double value, const bool rented,
		const int id, const int& lastPayed) {
	// Initializes all members
	this->address = address;
	this->value = value;
	this->rented = rented;
	this->id = id;
	this->lastPayed = lastPayed;
}
/*
 * returns how many days it has been since the taxes were paid
 */
const int Property::getLastPayed() {
	return this->lastPayed;
}
/*
 * Returns address of the property
 */
const string Property::getAddress() {
	return address;
}
/*
 * returns property ID
 */
const int Property::getId() {
	return id;
}
/*
 * returns the value of the property
 */
const double Property::getValue() {
	return value;
}
/*
 * returns when the taxes are next due
 */
const int Property::getTaxDeadline() {
	// checks if properties are valuable enough to have taxes due earlier
	if (getTaxes() > TAXBRACKETCUTOFF)
		return SHORTTAXPERIOD;
	return LONDTAXPERIOD;
}
/*
 * to string
 * spits out all basic information about the property object
 * often called by children and the appended to by the child to string
 */
const string Property::toString() {
	stringstream ss;
	ss << "Property Id: " << id << " Address:" << address;
	//checks rented to determine outpot of toString()
	if (rented)
		ss << " Rental";
	else
		ss << " NOT Rental";
	ss << " Value: " << value;
	ss << " last payment: " << lastPayed << " days ago";
	return ss.str();
}
