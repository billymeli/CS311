// File Name: Grain.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 7

#include <iostream>
#include <string>
#include "Grain.hpp"

using namespace std;

// Default constructor (initializes all member variables to 0)
Grain::Grain()
{
  moistureLevel = 0;
  foreignMaterial = 0;
}

// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
Grain::Grain(double moistureLevel, double foreignMaterial)
  : moistureLevel(moistureLevel), foreignMaterial(foreignMaterial)
{}

// Member function toString() that returns a string representing grain type
string Grain::toString() const
{
  return this->getType();
}

// Accessor to return sample's moisture level (percent)
double Grain::getMoistureLevel() const
{
  return moistureLevel;
}

// Accessor to return sample's foreign material (percent)
double Grain::getForeignMaterial() const
{
  return foreignMaterial;
}

//Destructor (doesn't do anything specific)
Grain::~Grain()
{}
