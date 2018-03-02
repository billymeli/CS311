// File Name: Ticket.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include "Ticket.hpp"
#include "Grain.hpp"

using namespace std;


// Default Constructor (initializes all numerical values to zero)
  Ticket::Ticket()
    : ticketNumber(""), grossWeight(0), tareWeight(0), timestamp(0)
  {}

// Custom Constructor (sets values for each member variable to value entered by the user)
  Ticket::Ticket(const string number, const float grossWeight, const float tareWeight, const Grain& newGrain)
    : ticketNumber(number), grossWeight(grossWeight), tareWeight(tareWeight), grain(newGrain), timestamp(time(nullptr))
  {}

// Equality operator overloading function (checks if two tickets have the same ticket number and returns a bool)
bool Ticket::operator ==(const Ticket &T) const
{
  return (this->ticketNumber == T.getTicketNumber());
}

// Insertion operator overloading function (overloads the insertion operator to output a ticket receipt)
ostream& operator<< (ostream &out, const Ticket &ticket)
{
  out << ticket.toString();
  return out;
}

// Returns the ticket number
string Ticket::getTicketNumber() const
{
  return ticketNumber;
}

// Returns the gross weight
float Ticket::getGrossWeight() const
{
  return grossWeight;
}

// Returns the tare weight
float Ticket::getTareWeight() const
{
  return tareWeight;
}

// Returns the timestamp
time_t Ticket::getTimestamp() const
{
  return timestamp;
}

// Returns the moisture level from the grain sample
float Ticket::getMoistureLevel() const
{
  return grain.getMoistureLevel();
}

// Returns the foreign material from the grain sample
float Ticket::getForeignMaterial() const
{
  return grain.getForeignMaterial();
}

// Calculates the net weight
float Ticket::calcNetWeight() const
{
  return (grossWeight - tareWeight);
}

// Calculates the gross Weight
float Ticket::calcGrossBushels() const
{
  return (this->calcNetWeight() / grain.getAverageTestWeight());
}

// Calculates the moisture dockage
float Ticket::calcMoistureDockage() const
{
  if(grain.getMoistureLevel() < grain.getIdealMoistureLevel()) {
    return 0;
  }
    return (this->calcGrossBushels() * ((grain.getMoistureLevel()/100) - (grain.getIdealMoistureLevel()/100)));
}

// Calculates the net bushels
float Ticket::calcNetBushels() const
{
  return (this->calcGrossBushels() - this->calcMoistureDockage() - this->calcForeignMaterialDockage());
}

// Calculates the foreign material dockage
float Ticket::calcForeignMaterialDockage() const
{
  return (this->calcGrossBushels() * (grain.getForeignMaterial() / 100));
}

// Returns the tickets receipt as a single string
string Ticket::toString() const
{
  char outTime[20];
  strftime(outTime, sizeof(outTime), "%D %T", localtime(&timestamp));

  stringstream ss;
  ss.precision(2);

    ss << fixed;
    ss <<  "\nTicket " << ticketNumber << " - " << outTime << ":\n";
    ss <<  "\t" << grossWeight << " Gross Weight\n";
    ss <<  "\t" << tareWeight << " Tare Weight\n";
    ss <<  "\t" << this->calcNetWeight() << " Net Weight\n\n";
    ss <<  "\t" << this->calcGrossBushels() << " Gross Bushels\n";
    ss <<  "\t" << this->calcMoistureDockage() << " Moisture Level" << "(" << grain.getMoistureLevel() << "%)\n";
    ss <<  "\t" << this->calcForeignMaterialDockage() << " Foreign Material" << "(" << grain.getForeignMaterial() << "%)\n";
    ss <<  "\t" << this->calcNetBushels() << " Net Bushels\n";

  return ss.str();
}
