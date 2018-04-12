// File Name: Ticket.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 1


#include "Ticket.hpp"
#include <string>

using namespace std;

void Ticket::setTicketNumber(string ticketNum){

  ticketNumber = ticketNum;
}
void Ticket::setGrossWeight(float weight){

  grossWeight = weight;
}
void Ticket::setTareWeight(float weight){

  tareWeight = weight;
}
void Ticket::setMoistureLevel(float moistrLevel){

  moistureLevel = moistrLevel;
}
void Ticket::setForeignMaterial(float material){

  foreignMaterial = material;
}


string Ticket::getTicketNumber(){

  return ticketNumber;
}
float Ticket::getGrossWeight(){

  return grossWeight;
}
float Ticket::getTareWeight(){

  return tareWeight;
}
float Ticket::getNetWeight(){

  return netWeight;
}
float Ticket::getGrossBushels(){

  return grossBushels;
}
float Ticket::getMoistureDockage(){

  return moistureDockage;
}
float Ticket::getForeignMaterialDockage(){

  return foreignMaterialDockage;
}
float Ticket::getNetBushels(){
  return netBushels;
}
float Ticket::getMoistureLevel(){

  return moistureLevel;
}
float Ticket::getForeignMaterial(){

  return foreignMaterial;
}


void Ticket::calcNetWeight(){

  netWeight = grossWeight - tareWeight;
}
void Ticket::calcGrossBushels(){

  grossBushels = netWeight / AVG_WEIGHT_PER_BUSHEL;
}
void Ticket::calcMoistureDockage() {

  moistureDockage = grossBushels * ((moistureLevel/100) - IDEAL_MOISTURE_LEVEL);
}
void Ticket::calcNetBushels(){

  netBushels = grossBushels - moistureDockage - foreignMaterialDockage;
}
void Ticket::calcForeignMaterialDockage() {

  foreignMaterialDockage = grossBushels * (foreignMaterial / 100);
}
