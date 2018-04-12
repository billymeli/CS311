// File Name: Tickets.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include "Tickets.hpp"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor (initializes all numerical values to zero)
Tickets::Tickets()
  : ticketArrayCapacity(0), ticketArraySize(0)
{
  ticketArray = new Ticket[ticketArrayCapacity];
}

// Copy Constructor (copies a tickets object to another tickets object)
Tickets::Tickets(const Tickets& tickets)
  : ticketArrayCapacity(tickets.ticketArrayCapacity), ticketArraySize(tickets.ticketArraySize)
{
  ticketArray = new Ticket[ticketArrayCapacity];
}

// Destructor
Tickets::~Tickets() {
  delete[] ticketArray;
}

// Adds a ticket to the array of Tickets
void Tickets::add(const Ticket& ticket)
{
  // increment the size of the ticket array
  ticketArraySize++;

  if (ticketArraySize > ticketArrayCapacity) {
    ticketArrayCapacity = ticketArraySize + 3;
    Ticket *newArray = new Ticket[ticketArrayCapacity];

    for (unsigned int i = 0; i < ticketArraySize - 1; i++){
      newArray[i] = ticketArray[i];
    }

    newArray[ticketArraySize - 1] = ticket;

    delete[] ticketArray;
    ticketArray = newArray;

    return;
  }
  ticketArray[ticketArraySize - 1] = ticket;
}

// Return size of array of tickets (number of tickets in array)
int Tickets::size() const
{
  return ticketArraySize;
}

// Overloaded assignment operator =
const Tickets& Tickets::operator =(const Tickets& tickets)
{
  if (ticketArrayCapacity != tickets.ticketArrayCapacity) {
    delete[] ticketArray;
    ticketArray = new Ticket[tickets.ticketArrayCapacity];
  }
  ticketArrayCapacity = tickets.ticketArrayCapacity;
  ticketArraySize = tickets.ticketArraySize;
  for(int i = 0; i < ticketArraySize; i++) {
    ticketArray[i] = tickets.ticketArray[i];
  }

  return *this;
}

// Overloaded array operator [] (returns an anonymous ticket object if the index argument is greater the the ticket array size)
Ticket Tickets::operator [](unsigned int index) const
{
  if (index >= ticketArraySize) {
    cout << "This index doesn't exist in the tickets list \n";
    return Ticket();
  }
  return ticketArray[index];
}
