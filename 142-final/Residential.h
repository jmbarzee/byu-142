/*
 * Residential.h
 *
 *  Created on: Apr 1, 2015
 *      Author: jacobmb
 */

#ifndef RESIDENTIAL_H_
#define RESIDENTIAL_H_

#include "Property.h"

using namespace std;

class Residential: public Property {
private:
	bool occupied;
	static constexpr double RESIDENTIALOCCUPIED = 0.006;
	static constexpr double RESIDENTIALNONOCCUPIED = 0.009;
public:
	Residential(const string& address = "", const double& value = 0,
			const bool& rented = 0, const int& id = -1,
			const bool& occupied = 0, const int& lastPayed = 0);
	~Residential() {
	}
	;
	const string toString();
	const double getTaxes();
};

#endif /* RESIDENTIAL_H_ */
