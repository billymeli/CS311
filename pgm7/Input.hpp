/*
 * Input.hpp
 *
 *  Created on: Feb 11, 2018
 *      Author: Joe
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "Array.h"
#include "Wheat.hpp"
#include "Soybean.hpp"
#include "Milo.hpp"
#include "Ticket.hpp"

using namespace ContainerTemplate;

/**
 * The Input class allows input of various values from the console
 */
class Input {
public:
	// Return list of tickets (prompt user for tickets, adding each to list of tickets)
	static void inputTickets(Array<Ticket>& tickets);

private:
	// Default constructor (use private to prevent creation)
	Input();
};

#endif /* INPUT_H_ */
