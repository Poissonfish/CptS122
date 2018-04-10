#ifndef PA8_DATAANALYSIS_H
#define PA8_DATAANALYSIS_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "BST.h"

using std::ifstream;
using std::stringstream;
using std::getline;
using std::stoi;

class DataAnalysis {
public:
    DataAnalysis();
    ~DataAnalysis();
    // load the file and print out the summary
    void runAnalysis();

private:
    BST mTreeSold;
    BST mTreePurchased;
    ifstream mCsvStream;

    // function
    // open filestream
    void openFile(string filename);
    // close filestream
    void closeFile();
    // split line by ',' and store them into each input arguments
    void splitLine(string line, int &units, string &type, string &transaction);
    // load file and print out the tree
    void loadFile();
    // insert tree by units
    void insertTree(int units, string type, string transaction);
    // show summary statistics (max and min value) of trees
    void showTrend();
};

#endif //PA8_DATAANALYSIS_H
