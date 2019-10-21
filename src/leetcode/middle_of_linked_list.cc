/**
 * middle_of_linked_list.cc
 * Purpose: Given a non-empty, singly linked list with head node head, return a
 * middle node of linked list.
 * 
 * If there are two middle nodes, return the second middle node.
 * 
 * https://leetcode.com/problems/middle-of-the-linked-list/
 * 
 * @author Rahul W
 * @version 0.1 10/20/19
 */

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode *middleNode(ListNode *head) {
  ListNode *slow_ptr = head;
  ListNode *fast_ptr = head;
  if (head != nullptr) {
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
    }
  }
  return slow_ptr;
}


void addNode(ListNode **head_ref, int new_data) {
  ListNode *newNode = new ListNode(new_data);
  newNode->next = (*head_ref);
  (*head_ref) = newNode;
}


void printList(ListNode *root) {
  while (root != NULL) {
    printf("%d->", (root)->val);
    root = (root)->next;
  }
  printf("NULL\n");
}


int main() {
  ListNode *root = NULL;
  for (int i = 0; i < 6; i++) {
    addNode(&root, i);
  }
  printList(root);
  printList(middleNode(root));
}