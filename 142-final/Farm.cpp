/*
 * Farm.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jacobmb
 */

#include <string>
#include <sstream>

#include "Farm.h"
#include "Commercial.h"

using namespace std;

const double FARMDISCOUNT = 0.4;
/*
 * constructor
 * can take anywhere from all to no parameters
 */
Farm::Farm(const string& address, const double& value, const bool& rented, const int& id, const int& lastPayed) : Commercial(address, value, rented, id, FARMDISCOUNT) {
}
/*
 * returns the farm specific deadline for taxs
 */
const int Farm::getTaxDeadline() {
	return FARMTAXPERIOD;
}
/*
 * calls the property to string function and appends all farm relevant data
 */
const string Farm::toString() {
	stringstream ss;
	ss << Commercial::toString();
	//uses already implemented toString() of commercial and appends the note
	ss << " NOTE: Farm property";
	return ss.str();
}
/*
 *  get taxes gives commercial specific taxes
 * uses the commercial getTaxes (inheritance error without this function)
 */
const double Farm::getTaxes() {
	return Commercial::getTaxes();
}
