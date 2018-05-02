
// File Name: Ticket.hpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 7

#include "Grain.hpp"
#include <ctime>
#include <string>
#ifndef ticket_hpp
#define ticket_hpp

class Ticket {
private:
  //declaring member variables for the class
  std::string ticketNumber;
  double grossWeight, tareWeight;
  Grain* grainPtr;
  std::time_t timestamp;

 public:
  //Default Constructor
  Ticket();

  //Custom Constructor
  Ticket(const std::string number, const double grossWeight, const double tareWeight, const Grain* newGrainPtr, const time_t timeStamp);

  // Copy Constructor (creates a deep copy of the object argument)
  Ticket(const Ticket& ticket);

  //Destructor
  ~Ticket();

  // Overloaded equality operator
  bool operator ==(const Ticket &T) const;

  // static member function to compare two tickets based on their netbushels and grain type
  static bool compareTickets(const Ticket &T1, const Ticket &T2);

  // Overloaded assignment operator = (copies the object argument into the calling object)
  const Ticket& operator =(const Ticket& ticket);

  // Overloaded insertion operator
  friend std::ostream& operator<< (std::ostream &out, const Ticket &ticket);

  //Accessor Functions
  std::string getTicketNumber() const;
  double getGrossWeight() const;
  double getTareWeight() const;
  std::time_t getTimestamp() const;
  double getMoistureLevel() const;
  double getForeignMaterial() const;
  Grain* getSample() const;

  //Member Functions
  double calcNetWeight() const;
  double calcGrossBushels() const;
  double calcMoistureDockage() const;
  double calcNetBushels() const;
  double calcForeignMaterialDockage() const;
  std::string toString() const;
  std::string receipt() const;

  static std::string getHeader();

};
#endif /* ticket_hpp_ */
