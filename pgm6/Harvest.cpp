// File Name: Harvest.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include "Tickets.hpp"
#include "Output.hpp"
#include "Input.hpp"


int main(void)
{
  //Declaring a variable of type Tickets to hold the tickets generated
  Tickets tickets;

  Input::inputTickets(tickets);
  Output::outputTickets(tickets);
  Output::outputSummary(tickets);

  return 0;
}
