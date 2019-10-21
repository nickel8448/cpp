/**
 * maxdepth.cc
 * Purpose: Given a n-ary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the root
 * node down to the farthest leaf node.
 * 
 * For example, given a 3-ary tree:
 * 
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 *   
 * @author Rahul W
 * @version 0.1 10/20/19
 */

#include <iostream>
#include <vector>

struct Node {
  int key;
  std::vector<Node*> child;
};


Node *newNode(int key) {
  Node *temp = new Node;
  temp->key = key;
  return temp;
}


int maxDepthOfTree(Node* root) {
  if (root == nullptr) return 0;

  int maxDepth = 0;
  for (auto itr = root->child.begin(); itr != root->child.end(); itr++) {
    maxDepth = std::max(maxDepth, maxDepthOfTree(*itr));
  }
  return maxDepth + 1;
}


int main() {
  Node *root = newNode(10);
  (root->child).push_back(newNode(20));
  (root->child).push_back(newNode(30));
  (root->child).push_back(newNode(40));
  (root->child).push_back(newNode(50));
  (root->child[0]->child).push_back(newNode(60));
  (root->child[0]->child).push_back(newNode(70));
  (root->child[0]->child).push_back(newNode(80));
  (root->child[0]->child).push_back(newNode(90));
  std::cout << maxDepthOfTree(root) << std::endl;
}