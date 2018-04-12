// File Name: Output.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Output.hpp"
#include "Tickets.hpp"

using namespace std;

void Output::outputTickets(const Tickets& tickets)
{
  ofstream write_file;
  // opening file to store the list of ticket receipts
  write_file.open("HarvestTicketReceipts.txt");

  if (write_file.is_open()) {
    // write the header row to the file
    write_file << Ticket::getHeader() << endl;
    
    for (int i = 0; i < tickets.size(); i++) {
      write_file << tickets[i].receipt() << endl;
    }
  }
  write_file.close();
}

void Output::outputSummary(const Tickets& tickets)
{
  //Declaring variables to hold values for total gross bushels and net bushels
  double totalGrossBushels = 0;
  double totalNetBushels = 0;

  // Calculating the total gross bushels and net bushels for the whole tickets list
  for (int i = 0; i < tickets.size(); i++) {
    totalNetBushels += tickets[i].calcNetBushels();
    totalGrossBushels += tickets[i].calcGrossBushels();
  }

  //Printing the harvest summary
  cout << "\nHarvest Summary Totals" << endl;
  cout << "\t" << totalGrossBushels << " Gross bushels" << endl;
  cout << "\t" << totalNetBushels << " Net bushels" << endl;
}
