/*
*	File: 	MyResource.h
*	Author: Paul Li
*	Date: 	Oct. 4th 2017
*	Desc:	Used to setup and handle requests made by the client
*			to allow them to access the rest api of my server.
*			It will allow users to view all the people through 
*			/people and see more detail if a specific id was passed
*			in through the path (aka url) /people/1
*/

#ifndef MYRESOURCE_H_
#define MYRESOURCE_H_

#include <iostream>

#include <Wt/Http/Response>
#include <Wt/WResource>

#include <boost/thread.hpp>
#include <boost/chrono.hpp>

#include "Person.h"

class MyResource: public Wt::WResource {
 public:
  MyResource();
  virtual ~MyResource();
 protected:
  virtual void handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response);
};
 
#endif /* MYPRESOURCE_H_ */
