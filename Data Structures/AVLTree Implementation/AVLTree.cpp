//
// Created by My Pc on 10/23/2016.
//

#ifndef CMSC341_PROJECT3_AVLTREE_CPP
#define CMSC341_PROJECT3_AVLTREE_CPP

#define LEFT_HEAVY -1
#define RIGHT_HEAVY 1

#include"AVLTree.h"
#include<queue>

template<typename K, typename V>
AVLTree<K, V>::AVLTree() { root = NULL; }

template<typename K, typename V>
AVLTree<K, V>::AVLTree(std::string id, int order, int dType, int nType)
{
    root = NULL;
    size = 0;
    idType = (AVLTreeBase::DataType)dType;
    numType = (AVLTreeBase::NumberType)nType;
    this->id = id;
    this->order = (AVLTreeBase::PrintOrder)order;
}

template<typename K, typename V>
void AVLTree<K, V>::insert(K key, V value)
{
    size++;
    insert(new AVLTreeNode<K, V>(key, value), root);
};

template<typename K, typename V>
bool AVLTree<K, V>::insert( AVLTreeNode<K, V> *insNode, AVLTreeNode<K, V> *parent)
{

    if (root == NULL) {
        root = insNode;
        return true;
    }
    else if ( parent != NULL )
    {

        int comparison = insNode->compareTo(parent);
        bool newBranch = false;

        // if the insNode parent does not have any children, then there will be a new level on this that subtree
        if ( parent->left == NULL && parent->right == NULL) { newBranch = true; }

        // Insert left
        if (comparison == -1)
        {
            if ( parent->left == NULL ) {
                if ( parent == root ) { insNode->parent = root; } else { insNode->parent = parent; }
                parent->left = insNode;
            }
            else { newBranch = insert(insNode, parent->left); }
        } // Insert right
        else if ( comparison == 1 ) {
            if (parent->right == NULL)
            {
                if ( parent == root ) { insNode->parent = root; } else { insNode->parent = parent; }
                parent->right = insNode;
            }
            else { newBranch = insert(insNode, parent->right); }
        }

        parent->updateBalance();
        checkBalance(parent);
        if (newBranch) {
            parent->updateHeight();

        }
        return newBranch;
    }

    return false;
}

template<typename K, typename V>
void AVLTree<K, V>::updateBalance(AVLTreeNode<K, V> *node)
{
    if ( node->right != NULL && node->left != NULL)
    {
        node->balanceFactor = node->left->height + node->right->height;
    } else if ( node->right != NULL ) { node->balanceFactor = node->right->balanceFactor + 1; }\
    else if ( node->left != NULL ) { node->balanceFactor = node->left->balanceFactor - 1; }
}
template<typename K, typename V>
void AVLTree<K, V>::checkBalance(AVLTreeNode<K, V> *node)
{
    node->updateBalance();
    int balance = node->getBalance();
    int height = node->height;

    if ( node->balanceFactor)
   if ( node->balanceFactor > RIGHT_HEAVY ) {

       Lrotation(node);
   }
    else
   {
       if (node->balanceFactor < LEFT_HEAVY )
       {
           Rrotation(node);
       }
       else
       {
           if ( node->balanceFactor == 1)
           {
               if(node->right->balanceFactor == -1)
               {
                   Rrotation(node->right);
                   Lrotation(node);
               }
           }
           else
           {
               if (node->balanceFactor == -1)
               {
                   if ( node->left->balanceFactor == 1)
                   {
                       Lrotation(node->left);
                       Rrotation(node);
                   }
               }
           }
       }
   }


}

template<typename K, typename V>
bool AVLTree<K, V>::Lrotation(AVLTreeNode<K, V> *parent)
{
    if ( parent->right == NULL) { return false; }

    // find out if if parent is a left or right child
    int child = 0;
    if ( parent != root ) {
        if (parent->parent->left == parent) { child--; }
        else { child++; }
    }


    AVLTreeNode<K, V> *newRoot = parent->right;
    parent->right = newRoot->left;
    newRoot->left = parent;

    if(parent == root) { root = newRoot; }
    if ( child == 1) { parent->parent->right = newRoot;} else if ( child == -1) { parent->parent->left = newRoot; }
    newRoot->parent = parent->parent;
    newRoot->left->parent = newRoot;
    parent = newRoot;
    if (child != 0) {
        newRoot->updateHeight();
        newRoot->left->updateHeight();
    }

    newRoot->updateBalance();
    newRoot->left->updateBalance();

    newRoot = NULL;
    delete newRoot;

    return true;
}

template<typename K, typename V>
bool AVLTree<K, V>::Rrotation(AVLTreeNode<K, V> *parent)
{
    if ( parent->left == NULL) { return false; }

    AVLTreeNode<K, V> *newRoot = parent->left;
    int child = 0;

    // find out if if parent is a left or right child
    if ( parent != root) {

        if (parent->parent->left == parent) { child--; }
        else { child++; }
    }
    parent->left = newRoot->right;
    newRoot->right = parent;

    if(parent == root) {root = newRoot;}
    if ( child == 1) { parent->parent->right = newRoot;} else if ( child == -1){ parent->parent->left = newRoot; }

    newRoot->parent = parent->parent;
    newRoot->right->parent = newRoot;
    parent = newRoot;

    if (child != 0) {
        newRoot->updateHeight();
        newRoot->right->updateHeight();
    }
    newRoot->updateBalance();
    newRoot->right->updateBalance();

    newRoot = NULL;
    delete newRoot;

    return true;
}

template<typename K, typename V>
void AVLTree<K, V>::printPreOrder(std::ostream &stream)
{
    printPreOrder(stream, root);
}

template<typename K, typename V>
void AVLTree<K, V>::printPreOrder(std::ostream &stream, AVLTreeNode<K, V> *node)
{
    if(node!= NULL)
    {
        stream <<  " " << node->key;
        if (node->left != NULL) {printPreOrder(stream, node->left);}
        if (node->right != NULL) { printPreOrder(stream, node->right); }
    }
}

template<typename K, typename V>
void AVLTree<K, V>::printPostOrder(std::ostream &stream)
{
    printPostOrder(stream, root);
};

template<typename K, typename V>
void AVLTree<K, V>::printPostOrder(std::ostream &stream, AVLTreeNode<K, V> *node) {
    if (node != NULL) {
        if (node->left != NULL) { printPostOrder(stream, node->left); }
        if (node->right != NULL) { printPostOrder(stream, node->right); }
        stream << " " << node->key;
    }
};

template<typename K, typename V>
void AVLTree<K, V>::printInOrder(std::ostream &stream)
{
    printInOrder(stream, root);
};

template<typename K, typename V>
void AVLTree<K, V>::printInOrder(std::ostream &stream, AVLTreeNode<K, V> *node)
{
    if ( node != NULL ) {
        if (node->left != NULL) { printInOrder(stream, node->left); }
        stream << " " << node->key;
        if (node->right != NULL) { printInOrder(stream, node->right); }
    }
};

template<typename K, typename V>
void AVLTree<K, V>::printLevelOrder(std::ostream &stream) {
    if (root == NULL ) { return; }

    std::queue<AVLTreeNode<K, V>*> levels;
    levels.push(root);
    while( levels.empty() == false)
    {
        AVLTreeNode<K, V> *iter = levels.front();
        std::cout << iter->key << " ";
        levels.pop();
        if ( iter->left != NULL)
        {
            levels.push(iter->left);
        }

        if ( iter->right != NULL)
        {
            levels.push(iter->right);
        }
    }

}

template<typename K, typename V>
void AVLTree<K, V>::printTree(std::ostream &stream)
{
    if (order == AVLTreeBase::IN)
    {
        printInOrder(stream, root);
    }
    else if ( order == AVLTreeBase::PRE)
    {
        printPreOrder(stream, root);
    }
    else if ( order == AVLTreeBase::POST)
    {
        printPostOrder(stream, root);
    } else if ( order == AVLTreeBase::LEVEL)
    {
        printLevelOrder(stream);
    }
}

template<typename K, typename V>
void AVLTree<K, V>::print_range(std::ostream &stream, int min, int max)
{
    print_range(stream, min, max, root);
}

template<typename K, typename V>
void AVLTree<K, V>::print_range(std::ostream& stream, int min, int max, AVLTreeNode<K, V>* iter)
{

    if (iter != NULL) {
        if (min < iter->value) { print_range(stream, min, max, iter->left); }

        if (min <= iter->value && max >= iter->value) { stream << " " << iter->key; }

        if (max > iter->value) { print_range(stream, min, max, iter->right); }
    } else return;

};

#endif