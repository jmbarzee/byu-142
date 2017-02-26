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

class Commercial : public Property {
private:
	double discount;
public:
	Commercial(const string& address = "", const double& value = 0, const bool& rented = 0, const int& id = -1, const double& discount = 0);
	~Commercial(){};
	const string toString();
	const double getTaxes();
};


#endif /* COMMERCIAL_H_ */
