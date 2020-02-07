/**
 * tree.c
 * Purpose: Implementing AVLTree from scratch
 *  
 * @author Rahul W
 * @version 0.1 01/28/20
 */


/**
 * Pending implementations:
 * 1. Check if the tree is balanced - done
 * 2. Do rotations when a node is inserted
 * 3. Create delete
 * 4. Min
 * 5. Max
 * 6. Successor
 * 7. Predecessor
 */

#include <iostream>
#include <algorithm>
#include <iomanip>

#include "tree.h"


AVLTree::AVLTree() {
  this->root = nullptr;
}


Node* AVLTree::RebalanceTree(Node *root) {
  // If the balance factor > 1 at the root that means there is some rebalancing
  // required
  int balancefactor = BalanceFactor(root);
  if(balancefactor > 1) {
    if(root->left != nullptr && BalanceFactor(root->left) > 0) {
      // TODO: Pending implementation
      root = LeftRotate(root);
    }
    root = RightRotate(root);
  } else if (balancefactor < -1) {
    if(root->right != nullptr && BalanceFactor(root->right) < -1) {
      // TODO: Pending implementation
      root = RightRotate(root);
    }
    root = LeftRotate(root);
  }
  return root;
}

/*
 *      y                               x
 *     / \     Right Rotation          /  \
 *    x   T3   - - - - - - - >        T1   y 
 *   / \       < - - - - - - -            / \
 *  T1  T2     Left Rotation            T2  T3
 */


Node* AVLTree::LeftRotate(Node *root) {
  Node *tempRoot = root;
  if (root->right != nullptr) {
    if (root->right->left != nullptr) {
      tempRoot->right = root->right->left;
    }
    root = root->right;
    root->left = tempRoot;
  }
  return root;
}


Node* AVLTree::RightRotate(Node *root) {
  Node *tempRoot = root;
  if(root->left != nullptr) {
    if(root->left->right != nullptr) {
      tempRoot->left = root->left->right;
    }
    root = root->left;
    root->left = tempRoot;
  }
  return root;
}


void AVLTree::Insert(int data) {
  root = InsertHelper(root, data);
}


Node* AVLTree::InsertHelper(Node *root, int data) {
  if (root == nullptr) {
    Node *toInsert = new Node;
    toInsert->data = data;
    toInsert->left = nullptr;
    toInsert->right = nullptr;
    return toInsert;
  }
  if (data < root->data) {
    root->left = InsertHelper(root->left, data);
    root = RebalanceTree(root);
  } else {
    root->right = InsertHelper(root->right, data); 
    root = RebalanceTree(root);
  }
  return root;
}


void AVLTree::PrintTree() {
  PrintTree(root);
}


void AVLTree::PrintTree(Node *root) {
  if (root == nullptr) return;
  PrintTree(root->left);
  std::cout << root->data << std::endl;
  PrintTree(root->right);
}


int AVLTree::GetTreeSize() {
  return GetTreeSize(this->root);
}


int AVLTree::GetTreeSize(Node *root) {
  // 1. Nullptrs are marked as -1
  // 2. Bottom most level is size 0
  // 2.1 Have to take the max or both the subtrees
  if(root == nullptr) {
    return -1;
  }
  int leftTreeSize = GetTreeSize(root->left) + 1;
  int rightTreeSize = GetTreeSize(root->right) + 1;
  return std::max(leftTreeSize, rightTreeSize);
}


std::pair<int, bool> AVLTree::SearchKey(int key) {
  return SearchKey(root, key);
}


std::pair<int, bool> AVLTree::SearchKey(Node *root, int key) {
  if(root == nullptr) {
    return std::make_pair(key, false);
  } else if (key == root->data) {
    return std::make_pair(root->data, true);
  }
  if(key < root->data) {
    return SearchKey(root->left, key);
  } else {
    return SearchKey(root->right, key);
  }
}


bool AVLTree::IsBalanced() {
  return IsBalanced(root);
}


bool AVLTree::IsBalanced(Node *root) {
  if (root == nullptr) return true;
  int leftSubTreeSize = GetTreeSize(root->left);
  int rightSubTreeSize = GetTreeSize(root->right);
  int difference = GetAbsoluteInteger(leftSubTreeSize) -
    GetAbsoluteInteger(rightSubTreeSize);
  if (difference <= 1) return true;
  else return false;
}


inline int AVLTree::GetAbsoluteInteger(int num) {
  if (num >= 0) return num;
  else return -num;
}


inline int AVLTree::BalanceFactor(Node *root) {
  return GetTreeSize(root->left) - GetTreeSize(root->right);
}


int main() {
  AVLTree t;
  t.Insert(30);
  t.Insert(20);
  t.Insert(10);
  t.Insert(40);
  t.Insert(25);
  t.Insert(27);
  t.PrintTree();
  std::cout << std::boolalpha;
  std::cout << "Balanced tree: " << t.IsBalanced() << std::endl;
}