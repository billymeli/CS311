// File Name: Soybean.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include <iostream>
#include <string>
#include "Soybean.hpp"

using namespace std;

namespace {
  const double AVG_WEIGHT_PER_BUSHEL = 60.0;
  const double IDEAL_MOISTURE_LEVEL = 13.0;
}

// Default constructor (initializes all member variables to 0)
Soybean::Soybean() : Grain()
{}

// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
Soybean::Soybean(double moistureLevel, double foreignMaterial)
  : Grain(moistureLevel, foreignMaterial)
{}

// returns a pointer pointing to a copy of the grain sample
Soybean* Soybean::clone() const
{
  Soybean* clonePtr = new Soybean(this->moistureLevel, this->foreignMaterial);
  return clonePtr;
}

// returns string representing the grain type
string Soybean::getType() const
{
  string grainType = "Soybean";
  return grainType;
}

// Accessor to return grain's average test weight (lbs/bushel)
const double Soybean::getAverageTestWeight() const
{
  return AVG_WEIGHT_PER_BUSHEL;
}

// Accessor to return grain's ideal moisture level (percent)
const double Soybean::getIdealMoistureLevel() const
{
  return IDEAL_MOISTURE_LEVEL;
}
