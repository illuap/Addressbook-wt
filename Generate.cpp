/*
*	File: 	Generate.cpp
*	Author: Paul Li
*	Date: 	Oct. 4th 2017
*	Desc:	A class with a bunch of static methods for generating
*			objects of addresses,names,phone numbers and people.
*			Mainly used to populate the data structure when called
*			upon for generating N amount of people.
*/

#include "Generate.h"

using namespace std;

// generate an address object
Address *Generate::generateAddress(){
    //random 10 street names, cities, provinces.
    string streetNames[] = {
        "Bloor Street",
        "Eglinton Ave",
        "Sherwoodmills Blvd",
        "Falling Brook Dr",
        "Western Rd",
        "Yonge St",
        "Hurontario st",
        "Main St",
        "Sarnia Rd",
        "Wonderland Rd"
    };
    string cityNames[] = {
        "Mississauga",
        "Toronto",
        "London",
        "Waterloo",
        "North York",
        "Winnipeg",
        "Vancouver",
        "Montreal",
        "Calgary",
        "Yellow Knife"
    };
    string provinceNames[] = {
        "Ontario",
        "Alberta",
        "Quebec",
        "Nova Scotia",
        "British Columbia",
        "Manitoba",
        "Saskatchewan",
        "Newfoundland & Labrador",
        "Prince Edward Island",
        "New Brunswick"
    };
    //default country
    string country = "Canada";

    /*
	*	appends a random number under 1000 to a random street name of the 10 premade
	*	city name is choosen randomly out of the 10 that are premade
	* 	province name is choosen randomly out of the 10 that are premade
	* 	country is defaulted to Canada
    */
    return new Address(""+ std::to_string(rand()%1000)+ " " + streetNames[rand()%10],
                                        cityNames[rand()%10],
                                        provinceNames[rand()%10],
                                        country);
}

// generate a phone number object in proper format xxx-xxx-xxxx
Phone *Generate::generatePhone(){
    
    string phoneString = "";
    //gernerates random number in xxx-xxx-xxxx format.
    phoneString = phoneString + std::to_string(rand()%900 + 100) +"-"; // give it a number between 0-899 
    phoneString = phoneString + std::to_string(rand()%900 + 100) +"-"; // then + 100 to be 100-999    
    phoneString = phoneString + std::to_string(rand()%10000);          // random number 0-9999
    return new Phone(phoneString);										// return the combined string
}

// generates a name object from a list of 10 random names and 10 random last names
Name *Generate::generateName(){
    //10 random first names to be choosen
    string firstNames[] = {
        "John",
        "Bob",
        "Kevin",
        "Thomas",
        "Nathan",
        "Amanda",
        "Jenny",
        "Kelly",
        "Ashley",
        "Victora"
    };
    //10 random last names to be choosen
    string lastNames[] = {
        "Smith",
        "Li",
        "Wong",
        "Jones",
        "Brown",
        "Johnson",
        "Taylor",
        "Wilson",
        "Wood",
        "Hall"
    };

    // a combination of randomly choosen first name and last name from the 10 premade
    return new Name(firstNames[rand()%10],lastNames[rand()%10]);
}

// generates a new person using the other generator functions above
Person *Generate::generatePerson(){
    return new Person(*Generate::generateName(), *Generate::generatePhone(),*Generate::generateAddress());
}
