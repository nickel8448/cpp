/**
 * binary_tree.cc
 * Purpose: Implenting a binary tree
 *  
 * @author Rahul W
 * @version 0.1 10/15/19
 */

#include <iostream>
#include <cmath>

#include "binary_tree.h"


/**
 * @brief  Binary tree constructor
 * @retval None
 */
binarytree::binarytree() {
    root = NULL;
}


binarytree::binarytree(const int elements[], const int size) : root(NULL) {
    for (int i = 0; i < size; i++) {
        this->insertNode(elements[i]);
    }
}


/**
 * @brief  Destructor for Binary Tree
 * @retval None
 */
binarytree::~binarytree() {
    binarytree::destroy_tree();
}


void binarytree::destroy_tree() {
    binarytree::destroy_tree(root);
}


void binarytree::destroy_tree(node *leaf) {
    if (leaf != NULL) {
        // the way this is implemented it is like a post-order traversal
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}


node *binarytree::search(int key) {
    return binarytree::search(key, root);
}


node *binarytree::search(int key, node *leaf) {
    if (leaf == NULL) return NULL;
    if (key == leaf->value) return leaf;
    if (key < leaf->value) {
        return search(key, leaf->left);
    } else {
        return search(key, leaf->right);
    }
}


void binarytree::insertNode(int key) {
    binarytree::insertNode(key, root);
}

/**
 * @brief  Helper function for inserting a node in the binary tree
 * @note  The leaf is being passed as an address to the pointer because the
 * root node is a pointer and it points to a node
 * @param  key: key to be inserted
 * @param  *&leaf: pointer to the leaf node
 * @retval None
 */
void binarytree::insertNode(int key, node *&leaf) {
    if (leaf == NULL) {
        leaf = new node;
        leaf->value = key;
        leaf->right = leaf->left = NULL;
        treeSize++;
        return;
    }
    //if (key == leaf->value) return;
    if (key <= leaf->value) {
        insertNode(key, leaf->left);
    } else {
        insertNode(key, leaf->right);
    }
}


void binarytree::printInOrder() {
    binarytree::printInOrder(root);
}


void binarytree::printInOrder(node *leaf) {
    if (leaf == NULL) return;
    printInOrder(leaf->left);
    std::cout << leaf->value << "\n";
    printInOrder(leaf->right);
}


int binarytree::size() {
    return treeSize;
}


int binarytree::tiltTree() {
    int total = 0;
    binarytree::tiltTree(root, &total);
    return total;
}


int binarytree::tiltTree(node *leaf, int *total) {
    if (!leaf) return 0;
    int leftSubTreeNode = tiltTree(leaf->left, total);
    int rightSubTreeNode = tiltTree(leaf->right, total);
    total = total + std::abs(leftSubTreeNode - rightSubTreeNode);
    return leftSubTreeNode + rightSubTreeNode + leaf->value;
}