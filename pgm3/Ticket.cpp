// File Name: Ticket.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 2


#include "Ticket.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace {
  const float AVG_WEIGHT_PER_BUSHEL = 60;
  const float IDEAL_MOISTURE_LEVEL = 12;
}

//Default Constructor (initializes all numerical values to zero)
  Ticket::Ticket() {
    ticketNumber = "";
    grossWeight = 0;
    tareWeight = 0;
    moistureLevel = 0;
    foreignMaterial = 0;
  }

//Custom Constructor
  Ticket::Ticket(string number, float grossWeight, float tareWeight, float moistureLevel, float foreignMaterial)
    : ticketNumber(number), grossWeight(grossWeight), tareWeight(tareWeight), moistureLevel(moistureLevel),
      foreignMaterial(foreignMaterial) {}

bool operator== (Ticket &T1, Ticket &T2)
{
  return (T1.getTicketNumber() == T2.getTicketNumber());
}

ostream& operator<< (ostream &out, Ticket &ticket) {
  out << ticket.toString();
  return out;
}

//Returns the ticket number
string Ticket::getTicketNumber(){
  return ticketNumber;
}
//Returns the gross weight
float Ticket::getGrossWeight(){
  return grossWeight;
}
//Returns the tare weight
float Ticket::getTareWeight(){
  return tareWeight;
}
//Returns the moisture level
float Ticket::getMoistureLevel(){
  return moistureLevel;
}
//Returns the foreign material
float Ticket::getForeignMaterial(){
  return foreignMaterial;
}

//Calculates the net weight
float Ticket::calcNetWeight(){
  netWeight = grossWeight - tareWeight;
  return netWeight;
}
//Calculates the gross Weight
float Ticket::calcGrossBushels(){
  grossBushels = netWeight / AVG_WEIGHT_PER_BUSHEL;
  return grossBushels;
}
//Calculates the moisture dockage
float Ticket::calcMoistureDockage() {
  if(moistureLevel < 12)
    return 0;
  else
    moistureDockage = grossBushels * ((moistureLevel/100) - (IDEAL_MOISTURE_LEVEL/100));
  return moistureDockage;
}
//Calculates the net bushels
float Ticket::calcNetBushels(){
  netBushels = grossBushels - moistureDockage - foreignMaterialDockage;
  return netBushels;
}
//Calculates the foreign material dockage
float Ticket::calcForeignMaterialDockage() {
  foreignMaterialDockage = grossBushels * (foreignMaterial / 100);
  return foreignMaterialDockage;
}
string Ticket::toString() {
  return (
    "\nTicket " + ticketNumber + ":\n" +
    "\t" + to_string(grossWeight) + " Gross Weight\n" +
    "\t" + to_string(tareWeight) + " Tare Weight\n" +
    "\t" + to_string(this->calcNetWeight()) + " Net Weight\n\n" +
    "\t" + to_string(this->calcGrossBushels()) + " Gross Bushels\n" +
    "\t" + to_string(this->calcMoistureDockage()) + " Moisture Level" + "(" + to_string(moistureLevel) + "%)\n" +
    "\t" + to_string(this->calcForeignMaterialDockage()) + " Foreign Material" + "(" + to_string(foreignMaterial) + "%)\n" +
    "\t" + to_string(this->calcNetBushels()) + " Net Bushels\n"
  );
}
