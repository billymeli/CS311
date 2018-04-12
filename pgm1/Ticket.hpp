
// File Name: Ticket.hpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 1

#include <string>
#ifndef ticket_hpp
#define ticket_hpp
using namespace std;
class Ticket {

private:
   string ticketNumber;
   float grossWeight, tareWeight, netWeight, grossBushels, moistureDockage;
   float foreignMaterialDockage, netBushels, moistureLevel, foreignMaterial;
   const float AVG_WEIGHT_PER_BUSHEL = 60;
   const float IDEAL_MOISTURE_LEVEL = 0.12;

 public:
   //Mutator Functions
   void setTicketNumber(string ticketNum);
   void setGrossWeight(float weight);
   void setTareWeight(float weight);
   void setMoistureLevel(float moistrLevel);
   void setForeignMaterial(float material);

   //Accessor Functions
   string getTicketNumber();
   float getGrossWeight();
   float getTareWeight();
   float getNetWeight();
   float getGrossBushels();
   float getMoistureDockage();
   float getForeignMaterialDockage();
   float getNetBushels();
   float getMoistureLevel();
   float getForeignMaterial();

   //Member Functions
   void calcNetWeight();
   void calcGrossBushels();
   void calcMoistureDockage();
   void calcNetBushels();
   void calcForeignMaterialDockage();

};
#endif
