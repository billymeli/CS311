// File Name: Output.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include <iostream>
#include <ctime>
#include <string>
#include "Output.hpp"
#include "Tickets.hpp"

using namespace std;

void Output::outputTickets(const Tickets& tickets)
{
  //Processing each ticket and printing the receipt (using an overloaded insertion operator)
  for (int i = 0; i < tickets.size(); i++) {
    cout << tickets[i];
  }
}

void Output::outputSummary(const Tickets& tickets)
{
  //Declaring variables to hold values for total gross bushels and net bushels
  float totalGrossBushels = 0;
  float totalNetBushels = 0;

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
