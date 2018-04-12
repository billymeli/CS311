// File Name: Input.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 4

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string>
#include "Input.hpp"
#include "Ticket.hpp"

using namespace std;

enum Type {WHEAT, SOYBEAN, MILO};

void Input::inputTickets(Tickets& tickets)
{
  ifstream read_file("HarvestTickets.txt");

  if (read_file.is_open()) {
      while(!read_file.eof()) {
        // record is a string representing a ticket record imported from the file
        string record;
        getline(read_file, record);

        // exclude any line that begins with a pound or is a new line character
        if (record[0] != '#' && record.length() > 1) {
          try {
            int fieldNumber = 0;
            bool strLimitExceeded = false;
            // variable that holds the grain type (char entered by the user)
            string type, date, time_string, ticketNumber, gross_weight, tare_weight, moisture_level, foreign_material;
            for(int i = 0; i < record.length(); i++) {
              if (record[i] == '|') {
                fieldNumber += 1;
              }
              switch(fieldNumber) {
                case 0: {
                  if (record[i] != '|' && record[i] != ' ') {
                    type += record[i];
                  }
                  break;
                }
                case 1: {
                  if (record[i] != '|' && record[i] != ' ') {
                    date += record[i];
                  }
                  break;
                }
                case 2: {
                  if (record[i] != '|' && record[i] != ' ') {
                    time_string += record[i];
                  }
                  break;
                }
                case 3: {
                  if (record[i] != '|' && record[i] != ' ') {
                    ticketNumber += record[i];
                  }
                  break;
                }
                case 4: {
                  if (record[i] != '|' && record[i] != ' ') {
                    gross_weight += record[i];
                  }
                  break;
                }
                case 5: {
                  if (record[i] != '|' && record[i] != ' ') {
                    tare_weight += record[i];
                  }
                  break;
                }
                case 6: {
                  if (record[i] != '|' && record[i] != ' ') {
                    moisture_level += record[i];
                  }
                  break;
                }
                case 7: {
                  if (record[i] != '|' && record[i] != ' ') {
                    foreign_material += record[i];
                  }
                  break;
                }
                default: {
                  strLimitExceeded = true;
                }
              }
            }
            if (fieldNumber != 7) {
              throw fieldNumber;
            }
            try {
              time_t t;
              string time_stamp = date + " " + time_string;
              double grossWeight = 0, tareWeight = 0, moistureLevel = 0, foreignMaterial = 0;

              const char *timestamp = time_stamp.c_str();
              struct tm tm;
              strptime(timestamp, "%Y-%m-%d %H:%M:%S", &tm);
              t = mktime(&tm);

              grossWeight = stoi(gross_weight);
              tareWeight = stoi(tare_weight);
              moistureLevel = stod(moisture_level);
              foreignMaterial = stod(foreign_material);
              cout << "\n" << type << " " << date << " " << time_string<<" "<<ticketNumber<<" "<<grossWeight<<" "<<tareWeight<<" "<<moistureLevel<<" "<<foreignMaterial;
              // declaring an enum to hold the grain type
              Type grainType;

              if (type == "Wheat") {
                grainType = WHEAT;
              } else if (type == "Soybean") {
                grainType = SOYBEAN;
              } else {
                grainType = MILO;
              }

              // Declaring a ticket
              Ticket ticket;

              // Initializing the ticket based on the grain type
              switch(grainType) {
                case WHEAT: {
                  Wheat* wheatPtr = new Wheat(moistureLevel, foreignMaterial);
                  ticket = Ticket(ticketNumber, grossWeight, tareWeight, wheatPtr, t);
                  break;
                }

                case SOYBEAN: {
                  Soybean* soybeanPtr = new Soybean(moistureLevel, foreignMaterial);
                  ticket = Ticket(ticketNumber, grossWeight, tareWeight, soybeanPtr, t);
                  break;
                }

                case MILO: {
                  Milo* miloPtr = new Milo(moistureLevel, foreignMaterial);
                  ticket = Ticket(ticketNumber, grossWeight, tareWeight, miloPtr, t);
                  break;
                }
                default: {
                  ticket = Ticket();
                }
              }

              int NumOfDuplicates = 0;

              // Determines the number of tickets similar to the current ticket
              for (int i = 0; i < tickets.size(); i++) {
                if (ticket == tickets[i]){
                  NumOfDuplicates += 1;
                }
              }

              // Add the current ticket to the list based on the number of duplicates found
              if (NumOfDuplicates == 0) {
                //Adding the ticket to the list of tickets
                tickets.add(ticket);
                cout << "\nTicket added " << ticket.getTicketNumber();
              } else {
                cout << "\nError: Duplicate ticket encountered, ticket ignored!";
              }
            }
            catch(const exception& e) {
              cout << "\nInvalid input: " << e.what();
            }
          }
          catch(int e) {
            cout << "\nError! This record only has " << e << " number of fields";
          }
        }
      }
    read_file.close();
  }
}
