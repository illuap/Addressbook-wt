/*
*   File:   Person.h
*   Author: Paul Li
*   Date:   Oct. 4th 2017
*   Desc:   a class that is used to represent a person that
*           has a Name, Phone and Address object to store
*           the data of itself. 
*/

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

#include "Name.h"
#include "Phone.h"
#include "Address.h"

class Person{
    public:
        Person(Name&aName, Phone&aPhone, Address&aAddress);
        ~Person();
        // getters
        Name *getName();
        Phone *getPhone();
        Address *getAddress();
        //setters
        void setName(Name &newName);
        void setPhone(Phone &newPhone);
        void setAddress(Address&aAddress);
        // getting the data in a json string format
        std::string getJson();
    private:
        Name * name;
        Phone *phoneNumber;
        Address * address;
};

#endif
