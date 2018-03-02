
// File Name: Ticket.hpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include "Grain.hpp"
#include <ctime>
#include <string>
#ifndef ticket_hpp
#define ticket_hpp

class Ticket {
private:
  //declaring member variables for the class
  std::string ticketNumber;
  float grossWeight, tareWeight;
  Grain grain;
  std::time_t timestamp;

 public:
  //Default Constructor
  Ticket();

  //Custom Constructor
  Ticket(const std::string number, const float grossWeight, const float tareWeight, const Grain& newGrain);

  bool operator ==(const Ticket &T) const;

  friend std::ostream& operator<< (std::ostream &out, const Ticket &ticket);

  //Accessor Functions
  std::string getTicketNumber() const;
  float getGrossWeight() const;
  float getTareWeight() const;
  std::time_t getTimestamp() const;
  float getMoistureLevel() const;
  float getForeignMaterial() const;

  //Member Functions
  float calcNetWeight() const;
  float calcGrossBushels() const;
  float calcMoistureDockage() const;
  float calcNetBushels() const;
  float calcForeignMaterialDockage() const;
  std::string toString() const;

};
#endif
