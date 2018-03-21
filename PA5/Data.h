#pragma once

#include <iostream>

class Data {

public:
  Data(int customerNumber, int serviceTime, int totalTime);
  Data(Data &copy);
  ~Data();

  int getNumber();
  int getServiceTime();
  int getTotalTime();

  void setNumber(int number);
  void setServiceTime(int time);
  void setTotalTime(int time);

private:
  // Unique identifier; starts at 1; after 24 hours should be reset to 1
  int customerNumber;
  // Random time; varies between express and normal lanes; units in minutes
  int serviceTime;
  // totalTime = serviceTime + sum of service Times of customers in line
  // before this customer; units in minutes
  int totalTime;
};
