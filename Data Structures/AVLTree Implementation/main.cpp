// Name: Sam Reynolds
// Date: 11/1/2016
// Project 3
// Note: The AVL Tree stores all the elements correctly, but printing them does not seem to work very well.


#include <iostream>
#include<fstream>
#include"AVLTree.h"
#include"AVLForest.h"

int main(int argc, char**argv)
{
    std::string inputFile = "input1.txt";
    std::string rangeFile = "range1.txt";
    AVLForest forest;

    std::ifstream inputStream(argv[0]);
    std::ifstream rangeStream(argv[1]);

    AVLTree<std::string, int> tree;

    std::cout << "============== \n";
    std::cout << "PRINTING TREES \n";
    std::cout << "============== \n";
    while (!inputStream.eof())
    {
        std::string line;
        std::getline(inputStream, line);
        forest.insert(line);
    }

    std::cout << forest;
    std::cout << "\n";

    std::cout << "============== \n";
    std::cout << "PRINTING RANGES \n";
    std::cout << "============== \n";
    while(!rangeStream.eof())
    {
        std::string range;
        std::getline(rangeStream, range);
        forest.print_range(std::cout, range);
        std::cout << "\n";
    }


}