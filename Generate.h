/*
*	File: 	Generate.h
*	Author: Paul Li
*	Date: 	Oct. 4th 2017
*	Desc:	A class with a bunch of static methods for generating
*			objects of addresses,names,phone numbers and people.
*			Mainly used to populate the data structure when called
*			upon for generating N amount of people.
*/

#ifndef GENERATE_H
#define GENERATE_H
#include "Address.h"
#include "Name.h"
#include "Phone.h"
#include "Person.h"

//generates a random person, name, address, and phone number object
class Generate{
public:
	static Address *generateAddress();
	static Name *generateName();
	static Phone *generatePhone();
	static Person *generatePerson();
private:
	Generate();
};

#endif
