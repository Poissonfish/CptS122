#include "Data.h"

Data::Data(int customerNumber, int serviceTime, int totalTime) {
  this->customerNumber = customerNumber;
  this->serviceTime = serviceTime;
  this->totalTime = totalTime;
}

Data::Data(Data &copy) {
  this->customerNumber = copy.getNumber();
  this->serviceTime = copy.getServiceTime();
  this->totalTime = copy.getTotalTime();
}

Data::~Data() {
  delete &this->customerNumber;
  delete &this->serviceTime;
  delete &this->totalTime;
}

int Data::getNumber() {
  return this->customerNumber;
}

int Data::getServiceTime() {
  return this->serviceTime;
}

int Data::getTotalTime() {
  return this->totalTime;
}

void Data::setNumber(int number) {
  this->customerNumber = number;
}

void Data::setServiceTime(int servicetime) {
  this->serviceTime = servicetime;
}

void Data::setTotalTime(int totaltime) {
  this->totalTime = totaltime;
}
