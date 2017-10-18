/*
*	File: 	MyResource.cpp
*	Author: Paul Li
*	Date: 	Oct. 4th 2017
*	Desc:	Used to setup and handle requests made by the client
*			to allow them to access the rest api of my server.
*			It will allow users to view all the people through 
*			/people and see more detail if a specific id was passed
*			in through the path (aka url) /people/1
*/

#include "MyResource.h"

 
using namespace std;
using namespace Wt::Http;

extern std::vector<Person*> addressBook; 

//global mutex for preventing thread locking.
boost::mutex mutex;

MyResource::MyResource() {
}	
 
MyResource::~MyResource() {
}

void MyResource::handleRequest(const Request& request, Response& response) {
	string method = request.method();			//the http request method
	string contentType = request.contentType();	//type of content in the body.
	int contentLength = request.contentLength();//get the length of the conent
	char* buffer = new char[contentLength + 1]; //gets the data in the response
	request.in().read(buffer, contentLength);	
	buffer[contentLength] = 0;					
	ostream& out = response.out();				//http response body.
	string pathInfo = request.pathInfo();		//get the url path

	
	if(pathInfo.size() > 1){					//if there is a specific person id entered (/person/1)
		
		pathInfo.erase(0,1);					// remove the last '/' in /people/1

		// check if its a whole number was entered
		if(pathInfo.find_first_not_of("0123456789") == std::string::npos){
			int id = std::stoi(pathInfo);		//convert path to int


			if(id >= addressBook.size()){		//checks for a number smaller then the data structure size	
				response.setStatus(400);		// when the wrong data was entered in the path
				out << "400 Bad Request" << endl;	//output the proper http response to user
			}else{

				// prevent any other threads from running to prevent 
				// access collisions to the global data structure addressBook 
				mutex.lock();

				Person *temp = addressBook.at(id);	//get data on the specific person

				// finished with accessing the global data structure
				// now other threads can access it now.
				mutex.unlock();

				//print out data on person in json format
				out << "{" <<endl;
				out << "\t \"id\": \"" << id << "\"," << endl;
				out << "\t" << temp->getName()->getJsonLastName() << "," << endl;
				out << "\t" << temp->getName()->getJsonFirstName() << "," << endl;
				out << "\t" << temp->getAddress()->getJsonStreet() << "," << endl;
				out << "\t" << temp->getAddress()->getJsonCity() << "," << endl;
				out << "\t" << temp->getAddress()->getJsonProvince() << "," << endl;
				out << "\t" << temp->getAddress()->getJsonCity() << "," << endl;
				out << "\t" << temp->getPhone()->getJsonPhone() << endl;
				out << "}" <<endl;
			}
		}else{
			response.setStatus(400);			// when the wrong data was entered in the path
			out << "400 Bad Request" << endl;
		}
	}else{
		//prints out each person in the addressbook. (id, firstname, lastname)
		out << "{" <<endl;
		out << "\t\"people\": [" <<endl;
		
		mutex.lock();
		for(int i = 0; i < addressBook.size();i++){		//generate list of people
		 	out << "\t\t{ \"id\": \"" << i << "\", ";
		 	out << addressBook.at(i)->getName()->getJsonLastName() << ", ";
		 	out << addressBook.at(i)->getName()->getJsonFirstName() << "}";

		 	if(i < (addressBook.size()-1) ){	//avoids adding a comma on the last entity
		 		out << ",\n";
		 	}else{
		 		out << "\n";
		 	}
		}
		mutex.unlock();

		out << "\t]\n" <<endl;
		out << "}" <<endl;
		//end of people output.
	}

	delete[] buffer;
}
