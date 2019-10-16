#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/binary_tree/binary_tree.h"

// TEST(BinaryTree, SmallTiltTree) {
//     binarytree bt;
//     bt.insertNode(10);
//     bt.insertNode(8);
//     bt.insertNode(12);
//     ASSERT_EQ(4, bt.tiltTree());
// }

// TEST(BinaryTree, OneBranchTreeTilt) {
//     binarytree leftBranchBt;
//     leftBranchBt.insertNode(10);
//     leftBranchBt.insertNode(8);

//     binarytree rightBranchBt;
//     rightBranchBt.insertNode(10);
//     rightBranchBt.insertNode(12);

//     ASSERT_EQ(8, leftBranchBt.tiltTree());
//     ASSERT_EQ(12, rightBranchBt.tiltTree());
// }

// TEST(BinaryTree, MediumTiltTree) {
//     binarytree bt;
//     bt.insertNode(50);
//     bt.insertNode(30);
//     bt.insertNode(70);
//     bt.insertNode(10);
//     bt.insertNode(20);
//     bt.insertNode(60);
//     bt.insertNode(90);
//     ASSERT_EQ(160, bt.tiltTree());
// }


TEST(Binarytree, UnivalTree) {
  int allTen[] = {10, 10, 10};
  int mixed[] = {10, 20, 30};
  int bigTree[] = {1, 1, 1, 1, 1, 1, 1};
  int bigMixedTree[] = {1, 1, 1, 1, 1, 5};
  binarytree btAllTen(allTen, 3);
  binarytree btMixed(mixed, 3);
  binarytree btBigTree(bigTree, 7);
  binarytree btBigMixedTree(bigMixedTree, 7);

  ASSERT_EQ(true, btAllTen.isUnivalTree());
  ASSERT_EQ(false, btMixed.isUnivalTree());
  ASSERT_EQ(true, btBigTree.isUnivalTree());
  ASSERT_EQ(false, btBigMixedTree.isUnivalTree());
}

TEST(BinaryTree, InvertTree) {
  int elements[] = {4, 2, 7, 1, 3, 6, 9};
  binarytree bt(elements, 7);
  std::cout << "Before inversion: " << std::endl;
  bt.printInOrder();
  bt.invertBinaryTree();
  std::cout << "After inversion: " << std::endl;
  bt.printInOrder();
}