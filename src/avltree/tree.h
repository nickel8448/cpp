/**
 * tree.h
 * Purpose: Header file for AVLTree
 *  
 * @author Rahul W
 * @version 0.1 01/28/20
 */
#ifndef AVLTREE
#define AVLTREE

#include <utility>

struct Node {
  int data;
  Node *left;
  Node *right;
};


class AVLTree {

  public:
    // Constructor
    AVLTree();

    // Function to insert data into the tree
    void Insert(int data);

    // Prints the tree in in-order traversal
    void PrintTree();

    // Function to get the tree size
    int GetTreeSize();

    // Searches for a specific key in the tree. If key is found it returns
    // the <key, true>, if key is not found it returns <key, false>
    std::pair<int, bool> SearchKey(int key);

  private:
    // Node variable
    Node *root;

    //  Helper function to insert node into the tree
    Node* InsertHelper(Node *root, int data);

    // Helper function to print the tree
    void PrintTree(Node *root);

    bool IsBalanced(Node *root);

    // Function to get the size of the tree/subtree
    int GetTreeSize(Node *root);

    // Helper function to search for a specific key in the tree
    std::pair<int, bool> SearchKey(Node *root, int key);
};


#endif
