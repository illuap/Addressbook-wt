/*
*   File:   Name.h
*   Author: Paul Li
*   Date:   Oct. 4th 2017
*   Desc:   a class that is used to represent an name of a person
*/

#ifndef NAME_H
#define NAME_H

#include <string>

class Name{
    public:
        Name(std::string fName, std::string lName);
        ~Name();
        // getters
        std::string getFirstName();
        std::string getLastName();
        // setters
        void setFirstName(std::string newName);
        void setLastName(std::string newName);
        // getting the data in a json string format
        std::string getJson();
        std::string getJsonFirstName();
        std::string getJsonLastName();
    private:
        std::string firstName, lastName;
};

#endif
