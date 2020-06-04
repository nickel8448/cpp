/**
 * @file invert_tree.cpp
 * @author Rahul Wadhwani
 * @brief
 * https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3347/
 * @version 0.1
 * @date 2020-06-01
 *
 * @copyright Copyright (c) 2020
 *
 * Approach: DFS and swap
 */

#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* invertTreeHelper(TreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  } else if (root->left == nullptr && root->right == nullptr) {
    return root;
  } else {
    root->left = invertTreeHelper(root->left);
    root->right = invertTreeHelper(root->right);
    std::swap(root->left, root->right);
    return root;
  }
}

TreeNode* invertTree(TreeNode* root) {
  root = invertTreeHelper(root);
  return root;
}
