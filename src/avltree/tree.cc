/**
 * tree.c
 * Purpose: Implementing AVLTree from scratch
 *  
 * @author Rahul W
 * @version 0.1 01/28/20
 */


#include <iostream>
#include <algorithm>
#include <iomanip>

#include "tree.h"

AVLTree::AVLTree() {
  this->root = nullptr;
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
  } else {
    root->right = InsertHelper(root->right, data); 
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

int main() {
  AVLTree t;
  t.Insert(30);
  t.Insert(20);
  t.Insert(10);
  t.Insert(40);
  t.Insert(25);
  t.Insert(27);
  t.PrintTree();
  std::cout << t.GetTreeSize() << std::endl;
  std::pair<int, bool> findKey = t.SearchKey(20);
  std::pair<int, bool> findKey2 = t.SearchKey(90);
  std::cout << std::boolalpha;
  std::cout << "Key: " << findKey.first << " found: " << findKey.second <<
    std::endl;
  std::cout << "Key: " << findKey2.first << " found: " << findKey2.second <<
    std::endl;
}

