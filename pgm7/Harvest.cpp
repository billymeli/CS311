// File Name: Harvest.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 7

#include "Array.h"
#include "Output.hpp"
#include "Input.hpp"

using namespace std;
using namespace ContainerTemplate;

int main(void)
{
  //Declaring a array of type Ticket to hold the tickets generated
  Array<Ticket> tickets;

  Input::inputTickets(tickets);
  sort(tickets.begin(), tickets.end(), Ticket::compareTickets);
  Output::outputTickets(tickets);
  Output::outputSummary(tickets);

  return 0;
}
