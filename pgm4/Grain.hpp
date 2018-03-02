/*
 * Grain.h
 *
 *  Created on: Feb 9, 2018
 *      Author: Joe
 */

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
	~Grain();

	// Accessor to return grain's average test weight (lbs/bushel)
	const double getAverageTestWeight() const;

	// Accessor to return grain's ideal moisture level (percent)
	const double getIdealMoistureLevel() const;

	// Accessor to return sample's moisture level (percent)
	double getMoistureLevel() const;

	// Accessor to return sample's foreign material (percent)
	double getForeignMaterial() const;

private:
	// Member variables
	double moistureLevel;
	double foreignMaterial;
};

#endif /* GRAIN_H_ */
