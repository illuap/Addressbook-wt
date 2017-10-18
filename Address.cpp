/*
*   File:   Address.cpp
*   Author: Paul Li
*   Date:   Oct. 4th 2017
*   Desc:   a class that is used to represent an address of a person
*/

#include "Address.h"

using namespace std;

//constructor
Address::Address(string aStreet, string aCity, string aProvince, string aCountry){
    street = aStreet;
    city = aCity;
    province = aProvince;
    country = aCountry;

};
//deconstructor
Address::~Address(){
};

// getters
string Address::getStreet(){
    return street;
}
string Address::getCity(){
    return city;
}
string Address::getProvince(){
    return province;
}
string Address::getCountry(){
    return country;
}


// setters
void Address::setStreet(string newStreet){
    street = newStreet;
}
void Address::setCity(string newCity){
    city = newCity;
}
void Address::setProvince(string newProvince){
    province = newProvince;
}
void Address::setCountry(string newCountry){
    country = newCountry;
}


// parsing the data into a json string format.
string Address::getJson(){
    string jsonStr = "";
    jsonStr = jsonStr +
        "\"address\": {\n" + 
            "\t\"street\": \""+ street + "\"\n" +
            "\t\"city\": \""+ city + "\"\n" +
            "\t\"province\": \""+ province + "\"\n" +
            "\t\"country\": \""+ country + "\"\n" + 
        "}\n";
    return jsonStr;
}
string Address::getJsonStreet(){
    return "\"street\": \""+ street + "\"";
}
string Address::getJsonCity(){
    return "\"city\": \""+ city + "\"";
}
string Address::getJsonProvince(){
    return "\"province\": \""+ province + "\"";
}
string Address::getJsonCountry(){
    return "\"country\": \""+ country + "\"";
}
