// File Name: Input.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include <iostream>
#include <ctime>
#include <string>
#include "Input.hpp"
#include "Ticket.hpp"
#include "Tickets.hpp"

using namespace std;

void Input::inputTickets(Tickets& tickets)
{
  cout << "Enter the tickets details" << endl;

  // declaring a variable to hold the user's choice after each loop
  char Endloop;

  // the user is propmted for a ticket's data until 'n' is entered at the end of a loop
  do {
    //declaring varaibles to hold the ticket's data
    string ticketNumber;
    float grossWeight = 0, tareWeight = 0, moistureLevel = 0, foreignMaterial = 0;
    int NumOfDuplicates = 0;

    //Prompting the user to enter the ticket's data
    cout << "\nTicket number " << tickets.size() + 1 << " (alphanumeric): ";
    cin >> ticketNumber;
    cout << "Gross Weight(lbs): ";
    cin >> grossWeight;
    cout<< "Tare Weight(lbs): ";
    cin >> tareWeight;
    cout << "Moisture Level(%): ";
    cin >> moistureLevel;
    cout << "Foreign Material(%): ";
    cin >> foreignMaterial;

    //Declaring a ticket and initilaizing it (using anonymous object for Grain sample)
    Ticket ticket(ticketNumber, grossWeight, tareWeight, Grain(moistureLevel, foreignMaterial));

    // Determines the number of tickets similar to the current ticket
    for (int i = 0; i < tickets.size(); i++) {
      if (ticket == tickets[i]){
        NumOfDuplicates += 1;
      }
    }

    // Add the current ticket to the list based on the number of duplicates found
    if (NumOfDuplicates == 0) {
      //Adding the ticket to the list of tickets
      tickets.add(ticket);
    } else {
      cout << "Error: Duplicate ticket encountered, ticket ignored!" << endl;
    }
    
    //Prompt the user for a character in order to continue the loop
    cout << "Do you wish to continue? (Enter 'y' for yes, 'n' for no): ";
    cin >> Endloop;
  } while(Endloop == 'y');
}
