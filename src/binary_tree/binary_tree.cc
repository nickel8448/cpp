/**
 * game.cc
 * Purpose: Build a simple snake game
 *  
 * @author Rahul W
 * @version 0.1 10/13/19
 */

#include <iostream>

#include "binary_tree.h"

// Binary tree constructor
binarytree::binarytree() {
    root = NULL;
}

// Binary tree destructor
binarytree::~binarytree() {
    binarytree::destroy_tree();
}

// Destroy tree helper function
binarytree::destroy_tree(node* leaf) {
    if (leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

