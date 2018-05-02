// File Name: Input.cpp
// Author: Billy Meli
// Student ID: w882x457
// Assignment Number: 7

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string>
#include "Input.hpp"

using namespace std;
using namespace ContainerTemplate;

enum Type {WHEAT, SOYBEAN, MILO};

void Input::inputTickets(Array<Ticket>& tickets)
{
  ifstream read_file("HarvestTickets.txt");

  if (read_file.is_open()) {
      while(!read_file.eof()) {
        // line is a string representing a line imported from the file
        // record is a string representing a line after white space characters have been trimed
        string line, record;
        getline(read_file, line);

        // Triming leading/trailing white spaces from the line
        const size_t strBegin = line.find_first_not_of(" ");
        if (strBegin == string::npos) {
          record = "";
        } else {
          const size_t strEnd = line.find_last_not_of(" ");
          const size_t strRange = strEnd - strBegin + 1;
          record = line.substr(strBegin, strRange);
        }

        // exclude any line that begins with a pound or is an
        if (record[0] != '#' && record != "\t" && record != "\r" && record != "\n" ) {
          try {
            int fieldNumber = 0;
            bool strLimitExceeded = false;
            string type, date, time_string, ticketNumber, gross_weight, tare_weight, moisture_level, foreign_material;

            for(int i = 0; i < record.length(); i++) {
              // get a new field when the delimiter '|' is encountered
              if (record[i] == '|') {
                fieldNumber += 1;
              }

              // append various portions of the record string to the appropriate variable
              // excluding '|' and ' ' characters
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
            // Throwing an exception if a record doesn't have the appropriate number of fields
            if (fieldNumber != 7) {
              throw fieldNumber;
            }
            try {
              time_t t;
              string time_stamp = date + " " + time_string;
              double grossWeight = 0, tareWeight = 0, moistureLevel = 0, foreignMaterial = 0;

              // t is a variable of type time_t holding information about the date and time
              const char *timestamp = time_stamp.c_str();
              struct tm tm;
              strptime(timestamp, "%Y-%m-%d %H:%M:%S", &tm);
              t = mktime(&tm);

              // converting each string to the appropriate type (interger, double)
              grossWeight = stoi(gross_weight);
              tareWeight = stoi(tare_weight);
              moistureLevel = stod(moisture_level);
              foreignMaterial = stod(foreign_material);

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
              } else {
                cout << "\nError: Duplicate ticket encountered, ticket ignored!";
              }
            }
            catch(const exception& e) {
              // handling exceptions for invalid type convertions
              cout << "\nInvalid input: " << e.what();
            }
          }
          catch(int e) {
            // handling exception for insufficient number of fields in a record
            cout << "\nError! This record only has " << e << " number of fields";
          }
        }
      }
    // closing file
    read_file.close();
  } else {
    cout << "\n Error! Input file could not be opened" << endl;
    exit(0);
  }
}
