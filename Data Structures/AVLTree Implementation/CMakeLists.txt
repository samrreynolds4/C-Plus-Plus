cmake_minimum_required(VERSION 3.6)
project(CMSC341_Project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES main.cpp AVLTree.h treeNode.h AVLTree.cpp AVLTreeNode.h AVLTreeNode.cpp AVLForest.h AVLForest.cpp )
add_executable(CMSC341_Project3 ${SOURCE_FILES})