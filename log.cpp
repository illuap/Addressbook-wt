/*
*	File:	log.cpp
*	Author: Eduardo Lago Aguilar
*	src:	http://eduardo-lago.blogspot.ca/2013/05/creating-rest-web-service-using.html?m=1
*	Desc:	Containing a few functions mainly for debugging purposes
*			that is used to log errors that occur in the program.
*	Note: 	This code is from the tutorial given to us in the assignment
*			the original author and link to the tutorial are above.
*/

#include "log.h"
#include <iostream>
 
//prints out fatal errors in my program and the
// date and time of these errors
void info(WLogger& logger, const string& message) {
	WLogEntry entry = logger.entry("info");
	entry << WLogger::timestamp << WLogger::sep << WLogger::sep << '[' << "info"
	  << ']' << WLogger::sep << message;
}
void fatal(WLogger& logger, const string& message, const char* what) {
	WLogEntry entry = logger.entry("fatal");
	entry << WLogger::timestamp << WLogger::sep << WLogger::sep << '['
	 << "fatal" << ']' << WLogger::sep << message << what;
}
 
void fatal(WLogger& logger, const string& message) {
	fatal(logger, message, "");
}
 
void configLogger(WLogger& logger) {
	logger.addField("datetime", false);
	logger.addField("type", false);
	logger.addField("message", true);
	logger.setFile("/var/log/resource.log");
}
