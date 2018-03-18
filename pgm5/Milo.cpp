// File Name: Milo.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 5

#include <iostream>
#include <string>
#include "Milo.hpp"

using namespace std;

namespace {
  const double AVG_WEIGHT_PER_BUSHEL = 56.0;
  const double IDEAL_MOISTURE_LEVEL = 13.0;
}

// Default constructor (initializes all member variables to 0)
Milo::Milo() : Grain()
{}

// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
Milo::Milo(double moistureLevel, double foreignMaterial)
  : Grain(moistureLevel, foreignMaterial)
{}

// returns a pointer pointing to a copy of the grain sample
Milo* Milo::clone() const
{
  Milo* clonePtr = new Milo(this->moistureLevel, this->foreignMaterial);
  return clonePtr;
}

// returns string representing the grain type
string Milo::getType() const
{
  string grainType = "Grain Sorghum";
  return grainType;
}

// Accessor to return grain's average test weight (lbs/bushel)
const double Milo::getAverageTestWeight() const
{
  return AVG_WEIGHT_PER_BUSHEL;
}

// Accessor to return grain's ideal moisture level (percent)
const double Milo::getIdealMoistureLevel() const
{
  return IDEAL_MOISTURE_LEVEL;
}
