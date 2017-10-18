/*
*   File:   Person.cpp
*   Author: Paul Li
*   Date:   Oct. 4th 2017
*   Desc:   a class that is used to represent a person that
*           has a Name, Phone and Address object to store
*           the data of itself. 
*/

#include "Person.h"

using namespace std;


//constructor
Person::Person(Name &aName, Phone &aPhone, Address &aAddress){
    name = &aName;
    phoneNumber= &aPhone;
    address = &aAddress;
};
//deconstructor
Person::~Person(){
    delete name;
    delete phoneNumber;
    delete address;
};

// getter methods
Name *Person::getName(){
    return name;
}
Phone *Person::getPhone(){
    return phoneNumber;
}
Address *Person::getAddress(){
    return address;
}

// setter methods
void Person::setName(Name &newName){
    name = &newName;
}
void Person::setPhone(Phone &newPhone){
    phoneNumber = &newPhone;
}
void Person::setAddress(Address &aAddress){
    address = &aAddress;
}

// parse the data into a json formated string
string Person::getJson(){
    string jsonStr ="";

    jsonStr = jsonStr +
        "\"Person\" : {\n"+
            name->getJson() +
            phoneNumber->getJson() +
            address->getJson()+
        "}\n";

    return jsonStr;
}

// global variable as the data structure.
vector<Person*> addressBook;