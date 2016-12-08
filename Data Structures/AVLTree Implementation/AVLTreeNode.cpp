//
// Created by My Pc on 10/23/2016.
//
#ifndef CMSC341_PROJECT3_AVLTREENODE_CPP
#define CMSC341_PROJECT3_AVLTREENODE_CPP


#include <algorithm>
#include "AVLTreeNode.h"
#include<iostream>

template<typename K, typename V>
AVLTreeNode<K, V>::~AVLTreeNode()
{
    delete left;
    delete right;
};

template<typename K, typename V>
AVLTreeNode<K, V>::AVLTreeNode(K key, V value)
{
    this->key = key;
    this->value = value;
    balanceFactor = 0;
    height = 0;
    left = NULL;
    right = NULL;
    parent = NULL;

}

template<typename K, typename V>
int AVLTreeNode<K, V>::compareTo(AVLTreeNode<K, V> *node)
{
    if ( this->value < node->value) { return SMALLER; }
    if ( this->value > node->value ) { return BIGGER;  }
    else { return EQUAL; }
}

template<typename K, typename V>
void AVLTreeNode<K, V>::updateBalance()
{

    if (right != NULL && left != NULL)
    {
        balanceFactor = (right->height - left->height);
    } else if (right != NULL)
    {
        right->updateBalance();
        balanceFactor = right->getBalance() + 1;
    } else if(left != NULL)
    {
        left->updateBalance();
        balanceFactor = left->getBalance() - 1;
    } else { balanceFactor = 0; }
};

template<typename K, typename V>
void AVLTreeNode<K, V>::updateHeight()
{

    if( left != NULL && right != NULL)
    {
        left->updateHeight();
        right->updateHeight();
        height = std::max(left->height, right->height) + 1;
    } else if ( left != NULL )
    {
        left->updateHeight();
        height = left->height + 1;
    } else if ( right != NULL )
    {
        right->updateHeight();
        height = right->height + 1;
    } else { height = 0; }
};

template<typename K, typename V>
int AVLTreeNode<K, V>::getBalance()
{
    return balanceFactor;
}

template<typename K, typename V>
K& AVLTreeNode<K, V>::getKey() { return *key; }


#endif