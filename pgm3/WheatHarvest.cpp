// File Name: WheatHarvest.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 2


#include<iostream>
#include<vector>
#include <string>
#include "Ticket.hpp"


using namespace std;

int main(void) {
  //Declaring a list of tickets
  vector<Ticket> tickets;

  cout << "Enter the tickets details" << endl;

  //Declaring a variable to hold the number of tickets
  int ticketCount = 1;

  // declaring a variable to hold the user's choice after each loop
  char Endloop;

  // the user is propmted for a ticket's data until 'n' is entered at the end of a loop
  do {
    //declaring varaibles to hold the ticket's data
    string ticketNumber;
    float grossWeight = 0, tareWeight = 0, moistureLevel = 0, foreignMaterial = 0;
    int NumOfDuplicates = 0;

    //Prompting the user to enter the ticket's data
    cout << "\nTicket number " << ticketCount << " (alphanumeric): ";
    cin >> ticketNumber;
    cout << "Gross Weight(lbs): ";
    cin >> grossWeight;
    cout<< "Tare Weight(lbs): ";
    cin >> tareWeight;
    cout << "Moisture Level(%): ";
    cin >> moistureLevel;
    cout << "Foreign Material(%): ";
    cin >> foreignMaterial;

    //Declaring a ticket and initilaizing it
    Ticket ticket(ticketNumber, grossWeight, tareWeight, moistureLevel, foreignMaterial);

    for (int i = 0; i < tickets.size(); i++) {
      if (ticket == tickets[i]){
        NumOfDuplicates += 1;
      }
    }
    if (NumOfDuplicates == 0) {
      //Adding the ticket to the list of tickets
      tickets.push_back(ticket);

      //Increment the number of tickets
      ticketCount += 1;
    } else {
      cout << "Error: Duplicate ticket encountered, ticket ignored!" << endl;
    }
    NumOfDuplicates = 0;
    //Prompt the user for a character in order to continue the loop
    cout << "Do you wish to continue? (Enter 'y' for yes, 'n' for no): ";
    cin >> Endloop;
  } while(Endloop == 'y');

  //Declaring variables to hold values for total gross bushels and net bushels
  float totalGrossBushels = 0;
  float totalNetBushels = 0;

  //Processing each ticket and printing the results
  for (int i = 0; i < tickets.size(); i++) {
    cout << tickets[i];
    totalNetBushels += tickets[i].calcNetBushels();
    totalGrossBushels += tickets[i].calcGrossBushels();
  }

  //Printing the harvest summary
  cout << "\nWheat harvest summary" << endl;
  cout << "\t" << totalGrossBushels << " Gross bushels" << endl;
  cout << "\t" << totalNetBushels << " Net bushels" << endl;

  return 0;
}
