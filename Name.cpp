/*
*   File:   Name.cpp
*   Author: Paul Li
*   Date:   Oct. 4th 2017
*   Desc:   a class that is used to represent a name of a person
*/

#include "Name.h"

using namespace std;

// constructor
Name::Name(string fName, string lName){
    firstName = fName;
    lastName = lName;
};
Name::~Name(){

}
// getters
string Name::getFirstName(){
    return firstName;
}
string Name::getLastName(){
    return lastName;
}

// setters
void Name::setFirstName(string newName){
    firstName = newName;
}
void Name::setLastName(string newName){
    lastName = newName;
}

// parse the data into a json formated string
string Name::getJson(){
    string jsonStr = "";
    jsonStr = jsonStr +
        "\"name\": {\n" +
            "\t\"first-name\": \""+ firstName + "\"\n" +
            "\t\"last-name\": \""+ lastName + "\"\n" +
        "}\n";
    return jsonStr;
}
string Name::getJsonFirstName(){
    return "\"firstName\": \""+ firstName + "\"";
}
string Name::getJsonLastName(){
    return "\"lastName\": \""+ lastName + "\"";
}
