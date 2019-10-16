#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/binary_tree/binary_tree.h"

TEST(BinaryTree, SmallTiltTree) {
    binarytree bt;
    bt.insertNode(10);
    bt.insertNode(8);
    bt.insertNode(12);
    ASSERT_EQ(4, bt.tiltTree());
}

TEST(BinaryTree, OneBranchTreeTilt) {
    binarytree leftBranchBt;
    leftBranchBt.insertNode(10);
    leftBranchBt.insertNode(8);

    binarytree rightBranchBt;
    rightBranchBt.insertNode(10);
    rightBranchBt.insertNode(12);

    ASSERT_EQ(8, leftBranchBt.tiltTree());
    ASSERT_EQ(12, rightBranchBt.tiltTree());
}

TEST(BinaryTree, MediumTiltTree) {
    binarytree bt;
    bt.insertNode(50);
    bt.insertNode(30);
    bt.insertNode(70);
    bt.insertNode(10);
    bt.insertNode(20);
    bt.insertNode(60);
    bt.insertNode(90);
    ASSERT_EQ(160, bt.tiltTree());
}