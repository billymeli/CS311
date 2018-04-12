// File Name: WheatHarvest.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 1


#include<iostream>
#include "Ticket.cpp"
#include <string>

using namespace std;

// this function propmpts the user for ticket information
Ticket promptInputData(string ticketNum, float grossWeight, float tareWeight, float moistureLevel, float foreignMaterial);


int main(void) {

  string ticketNumber;
  float grossWeight = 0, tareWeight = 0, moistureLevel = 0, foreignMaterial = 0;

  Ticket ticket = promptInputData(ticketNumber, grossWeight, tareWeight, moistureLevel, foreignMaterial);

  // calculate the values for net weight, gross bushels, moisture dockage...
  ticket.calcNetWeight();
  ticket.calcGrossBushels();
  ticket.calcMoistureDockage();
  ticket.calcForeignMaterialDockage();
  ticket.calcNetBushels();

  // output the results
  cout<<"\nTicket "<<ticket.getTicketNumber()<<":"<<endl;
  cout<<"\t"<<ticket.getGrossWeight()<<" Gross Weight"<<endl;
  cout<<"\t"<<ticket.getTareWeight()<<" Tare Weight"<<endl;
  cout<<"\t"<<ticket.getNetWeight()<<" Net Weight\n"<<endl;
  cout<<"\t"<<ticket.getGrossBushels()<<" Gross Bushels"<<endl;
  cout<<"\t"<<ticket.getMoistureDockage()<<" Moisture Level"<<"("<<ticket.getMoistureLevel()<<"%)"<<endl;
  cout<<"\t"<<ticket.getForeignMaterialDockage()<<" Foreign Material"<<"("<<ticket.getForeignMaterial()<<"%)"<<endl;
  cout<<"\t"<<ticket.getNetBushels()<<" Net Bushels"<<endl;

  return 0;
}

Ticket promptInputData(string ticketNum, float grossWeight, float tareWeight, float moistureLevel, float foreignMaterial) {

  Ticket ticket;

  cout<<"Ticket number: ";
  cin >> ticketNum;
  ticket.setTicketNumber(ticketNum);
  cout<<"Gross Weight(lbs): ";
  cin >> grossWeight;
  ticket.setGrossWeight(grossWeight);
  cout<<"Tare Weight(lbs): ";
  cin >> tareWeight;
  ticket.setTareWeight(tareWeight);
  cout<<"Moisture Level(%): ";
  cin >> moistureLevel;
  ticket.setMoistureLevel(moistureLevel);
  cout<<"Foreign Material(%): ";
  cin >> foreignMaterial;
  ticket.setForeignMaterial(foreignMaterial);

  return ticket;

}
