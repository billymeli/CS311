// File Name: Tickets.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include "Tickets.hpp"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor (initializes all numerical values to zero)
template<class T>
Array<T>::Array()
  : arrayCapacity(0), arraySize(0)
{
  array = new T[arrayCapacity];
}

// Copy Constructor (copies a tickets object to another tickets object)
template<class T>
Tickets::Tickets(const Array<T>& arrayObj)
  : arrayCapacity(arrayObj.arrayCapacity), arraySize(arrayObj.arraySize)
{
  array = new T[arrayCapacity];
}

// Destructor
template<class T>
Array<T>::~Array() {
  delete[] array;
}

// Adds a ticket to the array of Tickets
template<class T>
void Array<T>::add(const T& element)
{
  // increment the size of the ticket array
  arraySize++;

  if (arraySize > arrayCapacity) {
    arrayCapacity = arraySize + 3;
    T *newArray = new T[arrayCapacity];

    for (unsigned int i = 0; i < arraySize - 1; i++){
      newArray[i] = array[i];
    }

    newArray[arraySize - 1] = element;

    delete[] array;
    array = newArray;

    return;
  }
  array[arraySize - 1] = element;
}

// Return size of array of tickets (number of tickets in array)
template<class T>
int Array<T>::size() const
{
  return arraySize;
}

// Overloaded assignment operator =
template<class T>
const Array<T>& Array::operator =(const Array<T>& arrayObj)
{
  if (arrayCapacity != arrayObj.arrayCapacity) {
    delete[] array;
    array = new T[arrayObj.arrayCapacity];
  }
  arrayCapacity = arrayObj.arrayCapacity;
  arraySize = arrayObj.arraySize;
  for(int i = 0; i < arraySize; i++) {
    array[i] = arrayObj.array[i];
  }

  return *this;
}

// Overloaded array operator [] (returns an anonymous ticket object if the index argument is greater the the ticket array size)
template<class T>
T Array<T>::operator [](unsigned int index) const
{
  if (index >= arraySize) {
    cout << "This index doesn't exist in the tickets list \n";
    return T();
  }
  return array[index];
}
