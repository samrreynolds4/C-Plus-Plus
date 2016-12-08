#ifndef _AVLFOREST_H_
#define _AVLFOREST_H_

/* include your tree implementation  */
#include <vector>
#include <string>
#include<iostream>
#include <sstream>
#include "AVLTree.h"

class AVLForest
{
    enum Pairs { CHAR_INT, CHAR_FLOAT, STR_INT, STR_FLOAT };
  // vector of trees
  // we use a non-templated base class so we can hold all template instantiations
  std::vector<AVLTreeBase*> forest;

    // vector to hold the datatype and numbertype pairs
    std::vector<Pairs> treePairs;

    // ---- Information to hold for new trees and info from strings ----
    AVLTreeBase::DataType   dType;
    AVLTreeBase::NumberType nType;
    AVLTreeBase::PrintOrder pOrder;
    std::string id;

    // --- Insert data ---
    std::string key;
    std::string value;

  // other data memebers
  
public:
    AVLForest();
    ~AVLForest();

    // Name: contains(std::string line)
    // Pre-conditions: a valid string
    // post-conditions: returns true if there exists a tree with the line
    int contains(std::string line);

    // Name: getData(std::string, id, printOrder, DataType, NumberType)
    // Pre-conditions: valid parameters
    // Post-conditions: gets the data from the string and puts them in the correct variables
    void getData(std::string line);

    // Name: getInsertData(std::string line)
    // Pre-conditions: a valid string
    // Post-conditions: gets the indertdata from string and stored them in the lcass variable
    void getInsertData(std::string line);

    void insert(std::string);
    void print_range(std::ostream&, std::string);
    friend std::ostream& operator << (std::ostream&, AVLForest&);

  // other member functions

};

#endif /* _AVLFOREST_H_ */
