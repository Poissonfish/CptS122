#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h> // Mac

#include "Queue.h"
#include "QueueNode.h"
#include "Data.h"
#include "Queue.cpp"
#include "QueueNode.cpp"
#include "Data.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class SimulationApp {
public:
  SimulationApp();

  int getTime() const;
  int getNormalNumber() const;
  int getExpressNumber() const;

  void setTime(int elapsed);
  void setNormalNumber(int number);
  void setExpressNumber(int number);

  void pauseOneSec();
  // Clean the screen
  void clean () const;
  void reset();
  int promptMsg();
  void initialize();
  void printStatus();
  void checkEachCounter();
  void updateElapsed();
  void runApp(void);

private:
  Queue *normalLane;
  Queue *expressLane;
  int elapsed;
  int customNumberNormal;
  int customNumberExpress;
};
