//
// Created by My Pc on 10/23/2016.
//

#ifndef CMSC341_PROJECT3_AVLTREENODE_H
#define CMSC341_PROJECT3_AVLTREENODE_H

#include <cstddef>

#define BIGGER 1
#define SMALLER -1
#define EQUAL 0


template<typename K, typename V>
class AVLTree;

// K is the "key" in which the node will display, V is the data the tree will compare
template<typename K, typename V>
class AVLTreeNode
{

    friend class AVLTree<K, V>;

public:

    ~AVLTreeNode();

    // Name: AVLTreeNode(key, value)
    // Pre-conditions: valid key and value parameters
    // Post-conditions: creates an AVLTreeNode
    AVLTreeNode(K key, V value );

    // Name: operator<(AVLTreeNode lhs, AVLTreeNode rhs)
    // Pre-conditions: valid lhs and rhs pointers
    // Post-conditions: returns true if lhs is less than rhs by comparing the value of nodes
    int compareTo(AVLTreeNode<K, V> *node);

    // Name: getKey()
    // Pre-conditions: A valid key pointer
    // Post-conditions: returns a reference of the variable key
    K& getKey();

    // Name: getBalance()
    // Pre-conditions: a valid node object
    // Post-conditions: returns the balance factor of the node
    int getBalance();

    // Name: updateBalance
    // Pre-conditions: a valid tree node
    // Post-conditions: updates the balance factor of this node
    void updateBalance();

    // Name: updateHeight()
    // Pre-conditions: updates the height of this node
    // Post-conditions: updates the height of a node
    void updateHeight();

private:
    // The key to display
    K key;

    // The value to compare
    V value;

    // Height of the node
    int height;

    // Balance Factor of the node
    int balanceFactor;

    // Right child
    AVLTreeNode<K, V> *right;

    // Left Child
    AVLTreeNode<K, V> *left;

    // Parent of this node;
    AVLTreeNode<K, V> *parent;


};

#include"AVLTreeNode.cpp"

#endif //CMSC341_PROJECT3_AVLTREENODE_H
