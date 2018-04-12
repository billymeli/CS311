/*
 * Grain.h
 *
 *  Created on: Feb 9, 2018
 *      Author: Joe
 */

#include <string>
#ifndef GRAIN_H_
#define GRAIN_H_

/**
 * The Grain class identifies properties of a sample of grain
 */
class Grain {
public:
	// Constructor default
	Grain();

	// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
	Grain(double moistureLevel, double foreignMaterial);

	// Destructor
	virtual ~Grain();

	// pure virtual functions
	virtual Grain* clone() const = 0;

	virtual std::string getType() const = 0;

	virtual const double getAverageTestWeight() const = 0;

	virtual const double getIdealMoistureLevel() const = 0;

	// returns a string that represents the grain type
	std::string toString() const;

	// Accessor to return sample's moisture level (percent)
	double getMoistureLevel() const;

	// Accessor to return sample's foreign material (percent)
	double getForeignMaterial() const;

protected:
	// Member variables
	double moistureLevel;
	double foreignMaterial;
};

#endif /* GRAIN_H_ */
