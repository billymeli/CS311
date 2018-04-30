// File Name: Ticket.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include "Ticket.hpp"

using namespace std;


// Default Constructor (initializes all numerical values to zero)
  Ticket::Ticket()
    : ticketNumber(""), grossWeight(0), tareWeight(0), grainPtr(nullptr), timestamp(0)
  {

  }

// Custom Constructor (sets values for each member variable to value entered by the user)
  Ticket::Ticket(const string number, const double grossWeight, const double tareWeight, const Grain* newGrainPtr, time_t timeStamp)
    : ticketNumber(number), grossWeight(grossWeight), tareWeight(tareWeight), timestamp(timeStamp)
  {
    if (newGrainPtr != nullptr) {
      grainPtr = newGrainPtr->clone();
    }
  }

  // Copy Constructor (creates a deep copy of the object argument)
  Ticket::Ticket(const Ticket& ticket)
  {
    ticketNumber = ticket.ticketNumber;
    grossWeight = ticket.grossWeight;
    tareWeight = ticket.tareWeight;
    timestamp = ticket.timestamp;

    if (ticket.grainPtr != nullptr) {
      grainPtr = ticket.grainPtr->clone();
    }
  }

  // Destructor
  Ticket::~Ticket()
  {
    if (grainPtr != nullptr) {
      delete this->grainPtr;
    }
  }

  // Overloaded assignment operator = (copies the object argument into the calling object)
  const Ticket& Ticket::operator =(const Ticket& ticket)
  {
    if (this != &ticket) {
      if (grainPtr != nullptr)
        delete grainPtr;
      if (ticket.grainPtr != nullptr) {
        this->grainPtr = ticket.grainPtr->clone();
      }
      this->ticketNumber = ticket.getTicketNumber();
      this->grossWeight = ticket.getGrossWeight();
      this->tareWeight = ticket.getTareWeight();
      this->timestamp = ticket.getTimestamp();

      return *this;
    }
    return *this;
  }

// Equality operator overloading function (checks if two tickets have the same ticket number and returns a bool)
bool Ticket::operator ==(const Ticket &T) const
{
  return (this->ticketNumber == T.getTicketNumber());
}

// Less than operator overloading function (returns true if ticket1 has a lower net bushels, otherwise returns false)
bool Ticket::compareTickets(const Ticket &T1, const Ticket &T2)
{
  return (T1.calcNetBushels() < T2.calcNetBushels());
}

// Insertion operator overloading function (overloads the insertion operator to output a ticket receipt)
ostream& operator<< (ostream &out, const Ticket &ticket)
{
  out << ticket.toString();
  return out;
}

// Static member function returning a string representing the header row
string Ticket::getHeader()
{
  string header =  "Type|Date|Time|Number|GrossWeight|TareWeight|NetWeight|GrossBushels|MoistureLevel|MoistureLevelDockage|ForeignMaterial|ForeignMaterialDockage|NetBushels";

  return header;
}

// Returns the ticket number
string Ticket::getTicketNumber() const
{
  return ticketNumber;
}

// Returns the gross weight
double Ticket::getGrossWeight() const
{
  return grossWeight;
}

// Returns the tare weight
double Ticket::getTareWeight() const
{
  return tareWeight;
}

// Returns the timestamp
time_t Ticket::getTimestamp() const
{
  return timestamp;
}

// Returns the moisture level from the grain sample
double Ticket::getMoistureLevel() const
{
  return grainPtr->getMoistureLevel();
}

// Returns the foreign material from the grain sample
double Ticket::getForeignMaterial() const
{
  return grainPtr->getForeignMaterial();
}

// Returns a pointer to the grain sample
Grain* Ticket::getSample() const
{
    return grainPtr;
}

// Calculates the net weight
double Ticket::calcNetWeight() const
{
  return (grossWeight - tareWeight);
}

// Calculates the gross Weight
double Ticket::calcGrossBushels() const
{
  return (this->calcNetWeight() / grainPtr->getAverageTestWeight());
}

// Calculates the moisture dockage
double Ticket::calcMoistureDockage() const
{
  if(grainPtr->getMoistureLevel() < grainPtr->getIdealMoistureLevel()) {
    return 0;
  }
    return (this->calcGrossBushels() * ((grainPtr->getMoistureLevel()/100) - (grainPtr->getIdealMoistureLevel()/100)));
}

// Calculates the net bushels
double Ticket::calcNetBushels() const
{
  return (this->calcGrossBushels() - this->calcMoistureDockage() - this->calcForeignMaterialDockage());
}

// Calculates the foreign material dockage
double Ticket::calcForeignMaterialDockage() const
{
  return (this->calcGrossBushels() * (grainPtr->getForeignMaterial() / 100));
}

// Returns the tickets receipt as a single string
string Ticket::toString() const
{
  char outTime[20];
  strftime(outTime, sizeof(outTime), "%D %T", localtime(&timestamp));

  stringstream ss;
  ss.precision(2);

    ss << fixed;
    ss <<  "\n" << grainPtr->toString() << " Ticket " << ticketNumber << " - " << outTime << ":\n";
    ss <<  "\t" << grossWeight << " Gross Weight\n";
    ss <<  "\t" << tareWeight << " Tare Weight\n";
    ss <<  "\t" << this->calcNetWeight() << " Net Weight\n\n";
    ss <<  "\t" << this->calcGrossBushels() << " Gross Bushels\n";
    ss <<  "\t" << this->calcMoistureDockage() << " Moisture Level" << "(" << grainPtr->getMoistureLevel() << "%)\n";
    ss <<  "\t" << this->calcForeignMaterialDockage() << " Foreign Material" << "(" << grainPtr->getForeignMaterial() << "%)\n";
    ss <<  "\t" << this->calcNetBushels() << " Net Bushels\n";

  return ss.str();
}

// Returns a string representing the ticket's receipt record
string Ticket::receipt() const
{
  // C String to hold the date
  char outDate[20];
  strftime(outDate, sizeof(outDate), "%Y%m%d", localtime(&timestamp));

  // C String to hold the time
  char outTime[20];
  strftime(outTime, sizeof(outTime), "%H%M%S", localtime(&timestamp));

  stringstream ss;

  ss << fixed;
  ss.precision(0);
  ss << "\n" << grainPtr->toString() << "|" << outDate << "|" << outTime << "|";
  ss << ticketNumber << "|" << grossWeight << "|" << tareWeight << "|";
  ss.precision(2);
  ss << this->calcNetWeight() << "|" << this->calcGrossBushels() << "|" << grainPtr->getMoistureLevel() << "|";
  ss << this->calcMoistureDockage() << "|" << grainPtr->getForeignMaterial() << "|" << this->calcForeignMaterialDockage() << "|";
  ss << this->calcNetBushels();

  return ss.str();
}
