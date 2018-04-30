/*
 * Tickets.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Joe
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Ticket.hpp"

/**
 * The Tickets class identifies properties of a list (array) of tickets
 **/
template<class T>
class Array {
public:
	// Constructor default
	Array();

	// Copy constructor
	Array(const Array<T>& arrayObj);

	// Destructor
	~Array();

	// Add an element to the array of tickets
	void add(const T& element);

	// Return size of array (number of elements in array)
	int size() const;

	// Overloaded assignment operator =
	const Array<T>& operator =(const Array<T>& arrayObj);

	// Overloaded array operator []
	T operator [](unsigned int index) const;

private:
	// Member variables
	T *array;				// Pointer to array of T
	unsigned int arrayCapacity;	// Number of elements the array currently has space for
	unsigned int arraySize;		// Number of elements added to the array
};

#endif /* ARRAY_H_ */
