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

    // Checks if the tree is balanced or not
    bool IsBalanced();

    // Draws the tree on the console
    void DrawTree();

    // Returns the min element in the tree
    int GetMinElement();

    // Returns the max element in the tree
    int GetMaxElement();

  private:
    // Node variable
    Node *root;

    //  Helper function to insert node into the tree
    Node* InsertHelper(Node *root, int data);

    // Helper function to print the tree
    void PrintTree(Node *root);

    // Function to get the size of the tree/subtree
    int GetTreeSize(Node *root);

    // Helper function to search for a specific key in the tree
    std::pair<int, bool> SearchKey(Node *root, int key);

    // Function checks if the tree is balanced or not
    bool IsBalanced(Node *root);

    // Returns an abosolute integer
    inline int GetAbsoluteInteger(int num);

    // Calculates the balace factor for the node
    inline int BalanceFactor(Node *root);

    // Rebalances the tree at the root node
    Node* RebalanceTree(Node *root);

    // Left rotate the tree at the node supplied
    Node* LeftRotate(Node *root);

    // Right rotate the tree at the node supplied
    Node* RightRotate(Node *root);

    // Helper function to draw the tree
    void DrawTree(Node *current, int indent);

    // Helper function to return the min element
    int GetMinElement(Node *root);

    // Helper function to return the max element
    int GetMaxElement(Node *root);
};

#endif
