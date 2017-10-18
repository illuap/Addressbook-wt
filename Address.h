/*
*	File: 	Address.h
*	Author: Paul Li
*	Date: 	Oct. 4th 2017
*	Desc:	a class that is used to represent an address of a person
*/

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address{
	public:
		Address(std::string aStreet, std::string aCity, std::string aProvince, std::string aCountry);
		~Address();
		// getters
		std::string getStreet();
		std::string getCity();
		std::string getProvince();
		std::string getCountry();
		//setters
		void setStreet(std::string newStreet);
		void setCity(std::string newCity);
		void setProvince(std::string newProvince);
		void setCountry(std::string newCountry);
		// getting the data in a json string format
		std::string getJson();
		std::string getJsonStreet();
		std::string getJsonCity();
		std::string getJsonProvince();
		std::string getJsonCountry();
	private:
		std::string street, city, province, country;

};

#endif
