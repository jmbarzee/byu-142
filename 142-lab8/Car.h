//WARNING: It is expressly forbidden to modify any part of this document, including its name
#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Car
{
	private:
		string name;
		string color;
		double price;

	public:
		//---------------------------------------------------------------------------------------
		/* 
		 * Constructor/Destructor
		 * 
		 * Handles creation and deletion of Car objects.
		 * 
		 * Parameter: name_in
		 *		The name of a new car
		 * Parameter: color_in
		 *		The color of a new car
		 * Parameter: price_in
		 *		The price of a new car
		 */
		Car(string name_in, string color_in, double price_in);
		virtual ~Car();
		//---------------------------------------------------------------------------------------
		/* 
		 * getName
		 * 
		 * Returns the name of the car.
		 * 
		 * Return:
		 *		The name of the car
		 */
		string getName();
		/* 
		 * getColor
		 * 
		 * Returns the color of the car.
		 * 
		 * Return:
		 *		The color of the car
		 */
		string getColor();
		/* 
		 * getPrice
		 * 
		 * Returns the price of the car.
		 * 
		 * Return:
		 *		The price of the car
		 */
		double getPrice();
		//---------------------------------------------------------------------------------------
		/* 
		 * paint
		 * 
		 * Paints the car a new color and increases the price by $1,000.
		 * 
		 * Parameter: new_color
		 *		The color of paint to be used on the car
		 */
		void paint(string new_color);
		//---------------------------------------------------------------------------------------
		/* 
		 * toString
		 * 
		 * Returns a single string containing useful information about the car.
		 * 
		 * Return:
		 *		A data string about this car
		 */
		string toString();
		//---------------------------------------------------------------------------------------
};