
// File Name: Wheat.hpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include "Grain.hpp"

#ifndef WHEAT_H_
#define WHEAT_H_

class Wheat : public Grain
{
public:
  //default constructor
  Wheat();

  // custom Constructor
  Wheat(double moistureLevel, double foreignMaterial);

  // returns a pointer pointing to a copy of the grain sample
  Wheat* clone() const;

  // returns string representing the grain type
  std::string getType() const;

  // Accessor to return grain's average test weight (lbs/bushel)
  const double getAverageTestWeight() const;

  // Accessor to return grain's ideal moisture level (percent)
  const double getIdealMoistureLevel() const;
};

#endif /* WHEAT_H_ */
