
// File Name: Milo.hpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 6

#include "Grain.hpp"
#include <string>

#ifndef MILO_H_
#define MILO_H_

class Milo : public Grain
{
public:
  //default constructor
  Milo();

  // custom Constructor
  Milo(double moistureLevel, double foreignMaterial);

  // returns a pointer pointing to a copy of the grain sample
  Milo* clone() const;

  // returns string representing the grain type
  std::string getType() const;

  // Accessor to return grain's average test weight (lbs/bushel)
  const double getAverageTestWeight() const;

  // Accessor to return grain's ideal moisture level (percent)
  const double getIdealMoistureLevel() const;
};

#endif /* MILO_H_ */
