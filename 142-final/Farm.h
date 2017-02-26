/*
 * Farm.h
 *
 *  Created on: Apr 9, 2015
 *      Author: jacobmb
 */

#ifndef FARM_H_
#define FARM_H_

#include <iostream>
#include <string>

#include "Commercial.h"

using namespace std;
//Extends the commercial class because it needs commercial specific abilities
class Farm: public Commercial {
private:
	static constexpr int FARMTAXPERIOD = 100;
public:

	Farm(const string& address = "", const double& value = 0,
			const bool& rented = 0, const int& id = -1, const int& lastPayed = 0);
	~Farm() {
	}
	;
	const int getTaxDeadline();
	const string toString();
	const double getTaxes();
};

#endif /* FARM_H_ */
