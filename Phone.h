/*
*   File:   Phone.h
*   Author: Paul Li
*   Date:   Oct. 4th 2017
*   Desc:   a class that is used to represent an phone number of a person
*/

#ifndef PHONE_H
#define PHONE_H
#include <string>

class Phone{
    public:
        Phone(std::string number);
        ~Phone();
        // getters
        std::string getPhoneNumber();
        // setters
        void setPhoneNumber(std::string newPhone);
        // getting the data in a json string format
        std::string getJson();
        std::string getJsonPhone();
    private:
        std::string phoneNumber;
};

#endif
