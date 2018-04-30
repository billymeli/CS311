// File Name: Harvest.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include "Array.h"
#include "Output.hpp"
#include "Input.hpp"
#include "Ticket.hpp"

using namespace std;
using namespace ContainerTemplate;

int main(void)
{
  //Declaring a variable of type Tickets to hold the tickets generated
  Array<Ticket> tickets;

  Input::inputTickets(tickets);
  sort(tickets.begin(), tickets.end(), Ticket::compareTickets);
  Output::outputTickets(tickets);
  Output::outputSummary(tickets);

  return 0;
}
