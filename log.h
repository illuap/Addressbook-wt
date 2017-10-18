/*
*	File:	log.h
*	Author: Eduardo Lago Aguilar
*	src:	http://eduardo-lago.blogspot.ca/2013/05/creating-rest-web-service-using.html?m=1
*	Desc:	Containing a few functions mainly for debugging purposes
*			that is used to log errors that occur in the program.
*	Note: 	This code is from the tutorial given to us in the assignment
*			the original author and link to the tutorial are above.
*/

#ifndef LOG_H_
#define LOG_H_
 
#include <Wt/WLogger>
 
using namespace std;
using namespace Wt;
 
void info(WLogger& logger, const string& message);
void fatal(WLogger& logger, const string& message, const char* what);
void fatal(WLogger& logger, const string& message);
void configLogger(WLogger& logger);
 
#endif /* LOG_H_ */