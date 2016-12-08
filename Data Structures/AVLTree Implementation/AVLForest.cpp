#include "AVLForest.h"


AVLForest::AVLForest()
{

}

AVLForest::~AVLForest()
{
    for ( int i = 0; i < forest.size(); i++)
    {
        delete forest.erase(forest.begin());
    }
}



int AVLForest::contains(std::string line) {

    std::istringstream ist(line);
    std::string lineId;
    Pairs pair;

    std::getline(ist, lineId, ',');

    for (size_t i = 0; i < forest.size(); i++) {
        pair = treePairs[i];
        if ( pair == CHAR_FLOAT) { if (static_cast<AVLTree<char, float>*>(forest[i])->getId() == lineId) { return i; } }
        if ( pair == CHAR_INT  ) { if (static_cast<AVLTree<char, int>*>(forest[i])->getId() == lineId ) { return i; } }
        if ( pair == STR_FLOAT ) { if (static_cast<AVLTree<std::string, float>*>(forest[i])->getId() == lineId ) { return i; } }
        if ( pair == STR_INT )   { if ( static_cast<AVLTree<std::string, int>*>(forest[i])->getId() == lineId) { return i; } }
    }



    return -1;
}

void AVLForest::getInsertData(std::string line)
{
    std::istringstream ist(line);
    std::string id;

    std::getline(ist, id, ',');

    std::getline(ist, key, ',');

    std::getline(ist, value, ',');


}


void AVLForest::getData(std::string line)
{
    std::istringstream ist(line);

    std::string data;
    std::string number;
    std::string print;

    //getting the id
    std::getline(ist, id, ',');

    //getting the data type
    std::getline(ist, print, ',');

    //getting the number type
    std::getline(ist, data, ',');

    //getting the print order
    std::getline(ist, number, ',');

    dType = ((AVLTreeBase::DataType)atoi(data.c_str()));

    nType = ((AVLTreeBase::NumberType)atoi(number.c_str()));

    pOrder = ((AVLTreeBase::PrintOrder)atoi(print.c_str()));




}

void AVLForest::insert(std::string line)
{
    int index = contains(line);
    AVLTreeBase *newTree;

    if (index == -1) {
        // create a new tree and add it to the vector
        getData(line);


        if (dType == AVLTreeBase::CHARACTER && nType == AVLTreeBase::INTEGER) {
            newTree = new AVLTree<char, int>(id, pOrder, dType, nType );
            treePairs.push_back(CHAR_INT);
            forest.push_back(static_cast<AVLTree<char, int>*>(newTree));
        } else if (dType == AVLTreeBase::CHARACTER && nType == AVLTreeBase::FLOAT) {
            newTree = new AVLTree<char, float>(id, pOrder, dType, nType );
            treePairs.push_back(CHAR_FLOAT);
            forest.push_back(static_cast<AVLTree<char, float>*>(newTree));
        } else if (dType == AVLTreeBase::STRING && nType == AVLTreeBase::INTEGER) {
            newTree = new AVLTree<std::string, int>(id, pOrder, dType, nType );
            treePairs.push_back(STR_INT);
            forest.push_back(static_cast<AVLTree<std::string, int>*>(newTree));
        } else if (dType == AVLTreeBase::STRING && nType == AVLTreeBase::FLOAT) {
            newTree = new AVLTree<std::string, float>(id, pOrder, dType, nType );
            treePairs.push_back(STR_FLOAT);
            forest.push_back(static_cast<AVLTree<std::string, float>*>(newTree));
        } else {
            // invalid case
        }


        newTree = NULL;

    } else {


        getInsertData(line);
        if (treePairs[index] == CHAR_INT) {
            static_cast<AVLTree<char, int>*>(forest[index])->insert(key.c_str()[0], (int)atoi(value.c_str()));
        } else if (treePairs[index] == CHAR_FLOAT) {
            static_cast<AVLTree<char, float>*>(forest[index])->insert(key.c_str()[0], (float)atof(value.c_str()));
        } else if (treePairs[index] == STR_INT) {
            static_cast<AVLTree<std::string, int>*>(forest[index])->insert(key, (int)atoi(value.c_str()));
        } else if (treePairs[index] == STR_FLOAT) {
            static_cast<AVLTree<std::string, float>*>(forest[index])->insert(key, (float)atof(value.c_str()));
        } else {
            // invalid case
        }
    }

}

void AVLForest::print_range(std::ostream &stream, std::string range)
{
    std::istringstream ist(range);
    std::string id;
    std::string min;
    std::string max;

    std::getline(ist, id, ',');
    std::getline(ist, min, ',');
    std::getline(ist, max, ',');

    int i = contains(range);
    AVLTreeBase *curTree = forest[i];

    if (treePairs[i] == AVLForest::CHAR_INT) {
        static_cast<AVLTree<char, int> *>(curTree)->print_range(stream, (int)std::atoi(min.c_str()), (int)std::atoi(max.c_str()));
    } else if (treePairs[i] == AVLForest::CHAR_FLOAT) {
        static_cast<AVLTree<char, float> *>(curTree)->print_range(stream, (int)std::atoi(min.c_str()), (int)std::atoi(max.c_str()));
    } else if (treePairs[i] == AVLForest::STR_INT) {
        static_cast<AVLTree<std::string, int> *>(curTree)->print_range(stream, (int)std::atoi(min.c_str()), (int)std::atoi(max.c_str()));
    } else if (treePairs[i] == AVLForest::STR_FLOAT) {
        static_cast<AVLTree<std::string, float> *>(curTree)->print_range(stream, (int)std::atoi(min.c_str()), (int)std::atoi(max.c_str()));
    } else {
        stream << "Unable to print";
    }

}

std::ostream &operator<<(std::ostream &out, AVLForest &avlForest) {
    // print all trees
    for (int i = 0; i < avlForest.forest.size(); i++) {
        AVLTreeBase *curTree = avlForest.forest[i];

        if (avlForest.treePairs[i] == AVLForest::CHAR_INT) {
            static_cast<AVLTree<char, int> *>(curTree)->printTree(out);
        } else if (avlForest.treePairs[i] == AVLForest::CHAR_FLOAT) {
            static_cast<AVLTree<char, float> *>(curTree)->printTree(out);
        } else if (avlForest.treePairs[i] == AVLForest::STR_INT) {
            static_cast<AVLTree<std::string, int> *>(curTree)->printTree(out);
        } else if (avlForest.treePairs[i] == AVLForest::STR_FLOAT) {
            static_cast<AVLTree<std::string, float> *>(curTree)->printTree(out);
        } else {
            out << "Unable to print";
        }
        std::cout << "\n";
    }
    return out;
}
