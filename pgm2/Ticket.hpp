
// File Name: Ticket.hpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 2

#include <string>
#ifndef ticket_hpp
#define ticket_hpp
using namespace std;

class Ticket {
private:
  //declaring member variables for the class
  string ticketNumber;
  float grossWeight, tareWeight, netWeight, grossBushels, moistureDockage;
  float foreignMaterialDockage, netBushels, moistureLevel, foreignMaterial;

 public:
  //Default Constructor
  Ticket();

  //Custom Constructor
  Ticket(string number, float grossWeight, float tareWeight, float moistureLevel, float foreignMaterial);

  friend bool operator== (Ticket &T1, Ticket &T2);

  friend ostream& operator<< (ostream &out, Ticket &ticket);

  //Accessor Functions
  string getTicketNumber();
  float getGrossWeight();
  float getTareWeight();
  float getMoistureLevel();
  float getForeignMaterial();

  //Member Functions
  float calcNetWeight();
  float calcGrossBushels();
  float calcMoistureDockage();
  float calcNetBushels();
  float calcForeignMaterialDockage();
  string toString();

};
#endif
