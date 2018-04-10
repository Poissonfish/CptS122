#include "DataAnalysis.h"

DataAnalysis::DataAnalysis() {

}

DataAnalysis::~DataAnalysis() {

}

void DataAnalysis::runAnalysis() {
    openFile("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA8/data.csv");
    loadFile();
    showTrend();
    closeFile();
}

void DataAnalysis::openFile(string filename) {
    this->mCsvStream.open(filename);
    if (!this->mCsvStream)
        cout << "Unable to open file";
}

void DataAnalysis::closeFile() {
    this->mCsvStream.close();
}

void DataAnalysis::splitLine(string line, int &units, string &type, string &transaction) {
    stringstream stream(line);
    string strTemp;
    getline(stream, strTemp, ',');
    units = stoi(strTemp);
    getline(stream, type, ',');
    getline(stream, transaction);
}

void DataAnalysis::loadFile() {
    string strTemp;
    int units;
    string type;
    string transaction;
    // skip the header
    getline(this->mCsvStream, strTemp);
    while (getline(this->mCsvStream, strTemp)) {
        this->splitLine(strTemp, units, type, transaction);
        this->insertTree(units, type, transaction);
    }
    // print trees
    cout << "Purchased Tree  : " << endl << "   ";
    this->mTreePurchased.inOrderTraversal();
    cout << endl << "Sold Tree  : " << endl << "   ";
    this->mTreeSold.inOrderTraversal();
}

void DataAnalysis::insertTree(int units, string type, string transaction) {
    if (transaction.find("Purchased") != string::npos)
        this->mTreePurchased.insert(type, units);
    else
        this->mTreeSold.insert(type, units);
}

void DataAnalysis::showTrend() {
    cout << endl << "Summary : ";
    cout << endl << "   " << "Item purchased the most over past 48 hours : ";
    this->mTreePurchased.findLargest().printData();
    cout << endl << "   " << "Item purchased the least over past 48 hours : ";
    this->mTreePurchased.findSmallest().printData();
    cout << endl << "   " << "Item sold the most over past 48 hours : ";
    this->mTreeSold.findLargest().printData();
    cout << endl << "   " << "Item sold the least over past 48 hours : ";
    this->mTreeSold.findSmallest().printData();
    cout << endl;
}
