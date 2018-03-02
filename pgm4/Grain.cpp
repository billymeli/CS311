// File Name: Grain.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include <iostream>
#include <string>
#include "Grain.hpp"

using namespace std;

namespace {
  const float AVG_WEIGHT_PER_BUSHEL = 60.0;
  const float IDEAL_MOISTURE_LEVEL = 12.0;
}

// Default constructor (initializes all member variables to 0)
Grain::Grain()
{
  moistureLevel = 0;
  foreignMaterial = 0;
}

// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
Grain::Grain(double moistureLevel, double foreignMaterial)
  : moistureLevel(moistureLevel), foreignMaterial(foreignMaterial)
{ }

// Accessor to return grain's average test weight (lbs/bushel)
const double Grain::getAverageTestWeight() const
{
  return AVG_WEIGHT_PER_BUSHEL;
}

// Accessor to return grain's ideal moisture level (percent)
const double Grain::getIdealMoistureLevel() const
{
  return IDEAL_MOISTURE_LEVEL;
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
