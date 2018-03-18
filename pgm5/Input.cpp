// File Name: Input.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include <iostream>
#include <ctime>
#include <string>
#include "Input.hpp"
#include "Ticket.hpp"

using namespace std;

enum Type {WHEAT, SOYBEAN, MILO};

void Input::inputTickets(Tickets& tickets)
{
  cout << "Enter the tickets details" << endl;

  // declaring a variable to hold the user's choice after each loop
  char Endloop;

  // the user is propmted for a ticket's data until 'n' is entered at the end of a loop
  do {
    //declaring varaibles to hold the ticket's data
    string ticketNumber;
    double grossWeight = 0, tareWeight = 0, moistureLevel = 0, foreignMaterial = 0;
    int NumOfDuplicates = 0;

    // variable that holds the grain type (char entered by the user)
    char typeLetter;

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
    cout << "Grain type (w)heat, (s)oybean, (g)rain sorghum: ";
    cin >> typeLetter;

    // declaring an enum to hold the grain type
    Type grainType;

    if (typeLetter == 'w') {
      grainType = WHEAT;
    } else if (typeLetter == 's') {
      grainType = SOYBEAN;
    } else {
      grainType = MILO;
    }

    // Declaring a ticket
    Ticket ticket;

    // Initializing the ticket based on the grain type
    switch(grainType) {
      case WHEAT: {
        cout << "case is wheat" << endl;
        Wheat* wheatPtr = new Wheat(moistureLevel, foreignMaterial);
        ticket = Ticket(ticketNumber, grossWeight, tareWeight, wheatPtr);
        break;
      }

      case SOYBEAN: {
        cout << "case is soybean" << endl;
        Soybean* soybeanPtr = new Soybean(moistureLevel, foreignMaterial);
        ticket = Ticket(ticketNumber, grossWeight, tareWeight, soybeanPtr);
        break;
      }

      case MILO: {
        cout << "case is grain soghurm" << endl;
        Milo* miloPtr = new Milo(moistureLevel, foreignMaterial);
        ticket = Ticket(ticketNumber, grossWeight, tareWeight, miloPtr);
        break;
      }
      default: {
        cout << "case is default" << endl;
        ticket = Ticket();
      }
    }

    // Determines the number of tickets similar to the current ticket
    for (int i = 0; i < tickets.size(); i++) {
      if (ticket == tickets[i]){
        NumOfDuplicates += 1;
      }
    }

    // Add the current ticket to the list based on the number of duplicates found
    if (NumOfDuplicates == 0) {
      cout << "number of dups is 0" << endl;
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
