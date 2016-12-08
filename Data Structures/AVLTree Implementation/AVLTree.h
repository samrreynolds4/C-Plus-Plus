//
// Created by My Pc on 10/20/2016.
//

#ifndef CMSC341_PROJECT3_AVLTREE_H
#define CMSC341_PROJECT3_AVLTREE_H



#include"AVLTreeBase.h"
#include"AVLTreeNode.h"

#include<iostream>
#include<string>

template<typename K,  typename V>
class AVLTree : public AVLTreeBase
{
public:

    enum TREETYPE { CHAR_INT, STR_INT, CHAR_FLOAT, STR_FLOAT };

    ~AVLTree() { delete root; }

    AVLTree();


    AVLTree(std::string id, int order, int dType, int nType);

    // Name: checkBalance()
    // Pre-conditions: A valid AVL Tree
    // Post-conditions: balances the AVL tree
    void checkBalance(AVLTreeNode<K, V> *node);

    // Name: updateBalance(AVLTreeNode)
    // Pre-conditions: a valid AVLTreeNode
    // Post-conditions: Updates the balance for the node
    void updateBalance(AVLTreeNode<K, V> *node);

    // Name: Insert(K)
    // Pre-conditions: a valid K value
    // Post-conditions: inserts a K value into the tree
    void insert(K key, V value);

    // Name: insert(treeNode<E>, treeNode<E>)
    // Pre-conditions: valid tree nodes
    // Post-conditions: inserts the new element in a BST
    bool insert(AVLTreeNode<K, V> *insNode, AVLTreeNode<K, V> *parent);

    // Name balanceTree()
    // Pre-conditions: a valid AVLTree object
    // Post-conditions: Balances the tree using left and right rotations
    void balanceTree();

    // Name LRotation(treeNode<W, E>)
    // Pre-conditions a treeNode<W, E> that contains children
    // Post-conditions: rotates the treeNode to the left
    bool Lrotation(AVLTreeNode<K, V> *parent);

    // Name: Rrotation(treeNode<W, E>)
    // Pre-conditions: a valid treeNode that contains children
    // Post-conditions: rotates the treeNode to the right
    bool Rrotation(AVLTreeNode<K, V> *parent);

    // Name: getId()
    // Pre-conditions: a valid AVLTree Object
    // Post-conditions: returns the id associated with this tree
    std::string getId() { return id; }

    // Name: getKeyType()
    // Pre-conditions: a valid AVLTree Object
    // Post-conditions: returns the Keytype associated with this tree
    int getKeyType() { return idType; }

    // Name: getValueType()
    // Pre-conditions: a valid AVLTree Object
    // Post-conditions: returns the valueType associated with this tree
    int getValueType() { return numType; }

    // Name: printTree(std::ostream)
    // Pre-conditions: a valid stream
    // Post-conditions: prints the tree in the specified print order
    void printTree(std::ostream &stream);

    // Name: printInorder()
    // Pre-conditons: a valid tree
    // Post-conditions: prints the tree inorder
    void printInOrder(std::ostream &stream, AVLTreeNode<K, V> *node);
    void printInOrder(std::ostream &stream);

    // Name: printPostOrder()
    // Pre-conditons: a valid tree
    // Post-conditions: prints the tree Postorder
    void printPostOrder(std::ostream &stream, AVLTreeNode<K, V> *node);
    void printPostOrder(std::ostream &stream);

    // Name: printPreOrder()
    // Pre-conditons: a valid tree
    // Post-conditions: prints the tree PreOrder
    void printPreOrder(std::ostream &stream, AVLTreeNode<K, V> *node);
    void printPreOrder(std::ostream &stream);


    // Name: printRange(ostream, int, int, AVLTreeNode)
    // Pre-conditions: a valid stream
    // Post-conditions: recursively prints the nodes between the range
    void print_range(std::ostream&, int min, int max);

    // Name: printRange(ostream, int, int, AVLTreeNode)
    // Pre-conditions: a valid stream
    // Post-conditions: recursively prints the nodes between the range
    void print_range(std::ostream&, int min, int max, AVLTreeNode<K, V> *iter);

    // Name: printLevelOrder()
    // Pre-conditions: a valid tree
    // Post-conditions: pritns the tree in level order
    void printLevelOrder(std::ostream &stream);

    // Name: printLevel()
    // Pre-conditions: a valid tree
    // Post-conditions: prints the tree at a certain level
    void printLevel(std::ostream &stream, int level, AVLTreeNode<K, V> *node);


private:
    // The root of the tree
    AVLTreeNode<K, V> *root;

    // Number of nodes in the tree
    int size;

    // Data type;
    DataType idType;

    //Numer type float or int
    NumberType numType;

    // id of the tree
    std::string id;

    // printOrder of the tree
    PrintOrder order;

};

#include"AVLTree.cpp"

#endif //CMSC341_PROJECT3_AVLTREE_H
