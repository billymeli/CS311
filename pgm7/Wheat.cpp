// File Name: Wheat.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 7
#include <iostream>
#include <string>
#include "Wheat.hpp"

using namespace std;

namespace {
  const double AVG_WEIGHT_PER_BUSHEL = 60.0;
  const double IDEAL_MOISTURE_LEVEL = 13.5;
}

// Default constructor (initializes all member variables to 0)
Wheat::Wheat() : Grain()
{}

// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
Wheat::Wheat(double moistureLevel, double foreignMaterial)
  : Grain(moistureLevel, foreignMaterial)
{}

// returns a pointer pointing to a copy of the grain sample
Wheat* Wheat::clone() const
{
  Wheat* clonePtr = new Wheat(this->moistureLevel, this->foreignMaterial);
  return clonePtr;
}

// returns an integer representing the grain type
int Wheat::getTypeVal() const
{
  int grainTypeVal = 1;
  return grainTypeVal;
}

// returns string representing the grain type
string Wheat::getType() const
{
  string grainType = "Wheat";
  return grainType;
}

// Accessor to return grain's average test weight (lbs/bushel)
const double Wheat::getAverageTestWeight() const
{
  return AVG_WEIGHT_PER_BUSHEL;
}

// Accessor to return grain's ideal moisture level (percent)
const double Wheat::getIdealMoistureLevel() const
{
  return IDEAL_MOISTURE_LEVEL;
}
