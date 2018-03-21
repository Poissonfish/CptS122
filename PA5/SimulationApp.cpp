#include "SimulationApp.h"

SimulationApp::SimulationApp() {
  this->normalLane = new Queue(false);
  this->expressLane = new Queue(true);
  this->elapsed = 0;
  this->customNumberNormal = 1;
  this->customNumberExpress = 1;
}

int SimulationApp::getTime() const {
  return this->elapsed;
}

int SimulationApp::getNormalNumber() const {
  return this->customNumberNormal;
}

int SimulationApp::getExpressNumber() const {
  return this->customNumberExpress;
}

void SimulationApp::setTime(int elapsed) {
  this->elapsed = elapsed;
}

void SimulationApp::setNormalNumber(int number) {
  this->customNumberNormal = number;
}

void SimulationApp::setExpressNumber(int number) {
  this->customNumberExpress = number;
}

void SimulationApp::pauseOneSec() {
  usleep(1000000); // Mac
  // Sleep(1000);
}

void SimulationApp::clean() const {
   // system("cls"); // Windows
  system("clear"); // Mac
}

void SimulationApp::reset() {
  this->setTime(0);
  this->setExpressNumber(1);
  this->setNormalNumber(1);
}

int SimulationApp::promptMsg() {
  cout << "Welcome to the simulator!" << endl;
  cout << "How long is the simulate? (mins) : ";
  int simTime = 0;
  cin >> simTime;
  return simTime;
  this->clean();
}

void SimulationApp::initialize() {
  normalLane->iniCustomer();
  expressLane->iniCustomer();
}

void SimulationApp::printStatus() {
  cout << endl << "\t\t\tStatus of lanes"<< endl;
  cout << "Normal lane : " << endl;
  normalLane->printQueue();
  cout << "Express lane : " << endl;
  expressLane->printQueue();
  cout << endl;
}

void SimulationApp::checkEachCounter() {
  normalLane->checkArrival(customNumberNormal, getTime());
  expressLane->checkArrival(customNumberExpress, getTime());
  normalLane->checkOut();
  expressLane->checkOut();
}

void SimulationApp::updateElapsed() {
  normalLane->updateElapsed();
  expressLane->updateElapsed();
  this->elapsed += 1;
}

void SimulationApp::runApp(void) {
  srand(time(NULL));
  normalLane->
  int simTime = this->promptMsg();
  cout << "Simulation Starts!" << endl;
  this->initialize();
  while (this->getTime() < simTime) {
    pauseOneSec();
    cout << "Time : " << this->getTime() << endl;
    if (this->getTime() % 10 == 0 && this->getTime() != 0)
      this->printStatus();
	  else if (this->getTime() == 1440)
      this->reset();
    this->checkEachCounter();
    this->updateElapsed();
  }
  cout << "Simulation Done!" << endl;
}
