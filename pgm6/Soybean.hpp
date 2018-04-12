
// File Name: Soybean.hpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 5

#include "Grain.hpp"
#include <string>

#ifndef SOYBEAN_H_
#define SOYBEAN_H_

class Soybean : public Grain
{
public:
  //default constructor
  Soybean();

  // custom Constructor
  Soybean(double moistureLevel, double foreignMaterial);

  // returns a pointer pointing to a copy of the grain sample
  Soybean* clone() const;

  // returns string representing the grain type
  std::string getType() const;

  // Accessor to return grain's average test weight (lbs/bushel)
  const double getAverageTestWeight() const;

  // Accessor to return grain's ideal moisture level (percent)
  const double getIdealMoistureLevel() const;
};

#endif /* SOYBEAN_H_ */
