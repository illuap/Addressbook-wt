/*
* File:   Generate.cpp
* Author: Paul Li
* Date:   Oct. 4th 2017
* Desc:   A web application that generates random people in an 
*         address book with a given input using a vector. It also
*         incorperates the use of restAPI to view the people in the
*         address book. It also incorporates a mechanicism to prevent
*         thread locking be locking the thread and preventing any other
*         thread from starting.
*/


#include <string>
#include <vector>
#include <iostream>

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WServer>
#include <Wt/WTable>
#include <Wt/WTableCell>

#include <boost/thread.hpp>

// used for sleeping threads to test out threadlocking.
// #include <thread>         
// #include <chrono>         

#include "Name.h"
#include "Phone.h"
#include "Address.h"
#include "Person.h"
#include "Generate.h"
#include "MyResource.h"
#include "log.h"

using namespace Wt;
using namespace std;
  
extern boost::mutex mutex;                // in the MyResource.cpp 
                                          // used preventing thread locking

extern std::vector<Person*> addressBook;  // Global Variable for the datastructure in Person Class
/*
 * A web application that generates an address book using a vector
 * that incorperates the use of restAPI to view the people in the 
 * address book.
 */
class AddressBookApplication : public WApplication
{
public:
  AddressBookApplication(const WEnvironment& env);
private:
  WLineEdit *genNum_;
  WText *errormsg_;
  WTable *table_;
  void generatePeople();
};

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
AddressBookApplication::AddressBookApplication(const WEnvironment& env)
  : WApplication(env)
{
  setTitle("Hello world");                               // application title
  root()->addWidget(new WText("How many entities do you want generated?"));  // show some text
  genNum_ = new WLineEdit(root());                     // allow text input
  genNum_->setFocus();                                 // give focus

  WPushButton *button
    = new WPushButton("Generate!", root());              // create a button
  button->setMargin(5, Left);                            // add 5 pixels margin

  root()->addWidget(new WBreak());                       // insert a line break


  errormsg_ = new WText(root());                         // used for displaying invalid input
  root()->addWidget(new WBreak());                       // insert a line break

  table_ = new WTable(root());                           // displaying the data for the people

  //writing the headers of the table
  table_->setWidth("100%");                               // table styling
  table_->setHeaderCount(1, Orientation::Horizontal);

  // generate + display the data
  button->clicked().connect(this, &AddressBookApplication::generatePeople);
    genNum_->enterPressed().connect
    (boost::bind(&AddressBookApplication::generatePeople, this));

}


// takes in a number of people to generate and add it to the vector data structure
void AddressBookApplication::generatePeople()
{

  // Update the text, using text input into the genNum_ field.

  
  string x = genNum_->text().toUTF8();        //convert to c++ string
  bool isWholeNum = x.find_first_not_of("0123456789") == std::string::npos;  //check if the input is a whole number

  //if valid input
  if(isWholeNum){       
    int num = std::stoi(genNum_->text());     // convert to int
    Person *temp;                             // for adding and deleting people


    errormsg_->setText("");                   // clear error msg
   
    //clear the table of previous data
    table_->clear();
    //create the header of the table
    table_->elementAt(0, 0)->addWidget(new Wt::WText("ID"));
    table_->elementAt(0, 1)->addWidget(new Wt::WText("Last Name"));
    table_->elementAt(0, 2)->addWidget(new Wt::WText("First Name"));
    table_->elementAt(0, 3)->addWidget(new Wt::WText("Phone Number"));
    table_->elementAt(0, 4)->addWidget(new Wt::WText("Street"));
    table_->elementAt(0, 5)->addWidget(new Wt::WText("City"));
    table_->elementAt(0, 6)->addWidget(new Wt::WText("Province"));
    table_->elementAt(0, 7)->addWidget(new Wt::WText("Country"));

    // prevents any other threads from starting
    // to prevent other threads from accessing the global vector
    mutex.lock();

    //empty/free up memory in the vector.
    while(!addressBook.empty()){
      temp = addressBook.back();
      delete temp;
      addressBook.pop_back();
    }


    // For the sake of testing threadlocking
    // std::this_thread::sleep_for (std::chrono::seconds(10));

    //add rows of each person in the data structure
    for(int i = 0; i < num; i++){
      temp = Generate::generatePerson();
      addressBook.push_back(temp);      //add the person data structure
      table_->elementAt(i+1, 0)->addWidget(new Wt::WText(to_string(i)));
      table_->elementAt(i+1, 1)->addWidget(new Wt::WText(temp->getName()->getLastName()));
      table_->elementAt(i+1, 2)->addWidget(new Wt::WText(temp->getName()->getFirstName()));
      table_->elementAt(i+1, 3)->addWidget(new Wt::WText(temp->getPhone()->getPhoneNumber()));
      table_->elementAt(i+1, 4)->addWidget(new Wt::WText(temp->getAddress()->getStreet()));
      table_->elementAt(i+1, 5)->addWidget(new Wt::WText(temp->getAddress()->getCity()));
      table_->elementAt(i+1, 6)->addWidget(new Wt::WText(temp->getAddress()->getProvince()));
      table_->elementAt(i+1, 7)->addWidget(new Wt::WText(temp->getAddress()->getCountry()));
    }

    // allows other threads to execute now
    mutex.unlock();

  }else{
    //display if the text was invalid 
    //and to avoid touching the data.
    errormsg_->setText("Invalid input");
  }

}
/*
void wait(int seconds)
{
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}
*/

// creates an instance of the application.
WApplication *createApplication(const WEnvironment& env)
{
  /*
   * You could read information from the environment to decide whether
   * the user has permission to start a new application
   */
  return new AddressBookApplication(env);
}


int main(int argc, char **argv)
{
  /*
   * Your main method may set up some shared resources, but should then
   * start the server application (FastCGI or httpd) that starts listening
   * for requests, and handles all of the application life cycles.
   *
   * The last argument to WRun specifies the function that will instantiate
   * new application objects. That function is executed when a new user surfs
   * to the Wt application, and after the library has negotiated browser
   * support. The function should return a newly instantiated application
   * object.
   */

  WLogger logger;                                             // log information on the server
  configLogger(logger);                                       // used for debugging purposes
  try {
    WServer server(argv[0]);
    try {
      server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);

      MyResource dr;
      server.addResource(&dr, "/people");                    //for the restapi
      info(logger, "Starting resource server."); 

      server.addEntryPoint(Application, createApplication);  //load the web app
      info(logger, "Starting application.");

      if (server.start()) {
        WServer::waitForShutdown();
        server.stop();
      } else {           //error messages if server stops suddenly.
        fatal(logger, "Fatal error starting resource server.");
        return 1;
      }
      return 0;
    } catch (std::exception& e) {
      fatal(logger, "Fatal error starting resource server.", e.what());
      return 1;
    }
  } catch (WServer::Exception& e) {
    fatal(logger, "Fatal error creating WServer.", e.what());
    return 1;
  } catch (exception& e) {
    fatal(logger, "Fatal error occurred.", e.what());
    return 1;
  }

  return WRun(argc, argv, &createApplication); 
}
