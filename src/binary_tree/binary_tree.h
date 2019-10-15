/**
 * binary_tree.h
 * Purpose: Header file for binary tree configuration
 *  
 * @author Rahul W
 * @version 0.1 10/15/19
 */

// struct for node. Node in the binary tree
struct node {
    int value;
    node *left;
    node *right;
};

// Class for binary tree
class binarytree {

public:

    // default constructors
    binarytree();

    // default destructor
    ~binarytree();

    // Inserts a node in the binary tree
    void insertNode(int key);

    // searches for a specific key in the binarytree
    node* search(int key);

    // Destroy the tree
    void destroy_tree();

private:

    // Helper function to add nodes to the tree
    void insert(int key, node* leaf);

    // Helper function for searching a key in the tree
    node* search(int key, node* leaf);

    // Destroy tree 
    void destroy_tree(node* leaf);

    node* root;
};