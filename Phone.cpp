/*
*   File:   Phone.cpp
*   Author: Paul Li
*   Date:   Oct. 4th 2017
*   Desc:   a class that is used to represent a phone number of a person
*/

#include "Phone.h"

using namespace std;

//constructor
Phone::Phone(string number){
    phoneNumber = number;
};
Phone::~Phone(){
};

//getters
string Phone::getPhoneNumber(){
    return phoneNumber;
}

// setters
void Phone::setPhoneNumber(string newPhone){
    phoneNumber = newPhone;
}

// parsing the data into a json string format.
string Phone::getJson(){
    string jsonStr = "";
    jsonStr = jsonStr +
        "\"phone\": {\n" +
            "\t\"phoneNumber\": \"" +phoneNumber + "\"\n" +
        "}\n";
    return jsonStr;
}
string Phone::getJsonPhone(){
    return "\"phoneNumber\": \"" + phoneNumber + "\"";
}
