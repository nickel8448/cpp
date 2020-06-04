/**
 * @file copy_list_random_pointer.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/copy-list-with-random-pointer/
 * @version 0.1
 * @date 2020-05-25
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <set>
#include <unordered_map>

using std::set;
using std::unordered_map;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

Node *copyRandomListHelper(Node *head,
                           unordered_map<Node *, Node *> &node_map) {

  if (head == nullptr) {
    return nullptr;
  }
  // if we have already processed the current node, then we simply return the
  // cloned version of it
  if (node_map.find(head) != node_map.end()) {
    return node_map.at(head);
  }

  // Create a new node with the same value as the head
  Node *new_node = new Node(head->val);

  // Saving the value in the map
  node_map.insert(std::make_pair(head, new_node));

  // recursively copy the remaining linked list starting once from the next
  // pointer and then from the random pointer
  new_node->next = copyRandomListHelper(head->next, node_map);
  new_node->random = copyRandomListHelper(head->random, node_map);

  return new_node;
}

Node *copyRandomListLC(Node *head) {
  // Map will hold old nodes as keys and new nodes as its values
  unordered_map<Node *, Node *> node_map;

  if (head == nullptr) {
    return nullptr;
  }

  Node *new_head = copyRandomListHelper(head, node_map);
  return new_head;
}

Node *copyRandomList(Node *head) {
  // current_node -> new_node map
  unordered_map<Node *, Node *> node_map;
  if (head == nullptr)
    return nullptr;
  Node *new_head = new Node(head->val);
  Node *new_head_copy = new_head;
  if (head->next == nullptr && head->random == nullptr) {
    return new_head;
  }
  Node *current_head = head->next;
  node_map.insert(std::make_pair(head, new_head));
  while (current_head != nullptr) {
    // Creating a new node
    Node *new_node = new Node(current_head->val);
    new_head_copy->next = new_node;

    // adding the current node to the map
    node_map.insert(std::make_pair(current_head, new_node));

    // Traversing it further
    new_head_copy = new_head_copy->next;
    current_head = current_head->next;
  }

  // restarting the traversal
  new_head_copy = new_head;
  current_head = head;
  while (current_head != nullptr) {
    // Mapping block
    Node *mapped_new_node = node_map.at(current_head);
    Node *random_pointer_current_node = current_head->random;
    if (random_pointer_current_node == nullptr) {
      new_head_copy->random = nullptr;
    } else {
      Node *mapped_random_pointer = node_map.at(random_pointer_current_node);
      new_head_copy->random = mapped_random_pointer;
    }

    // Traversing it further
    new_head_copy = new_head_copy->next;
    current_head = current_head->next;
  }

  return new_head;
}

int main() {
  Node *head = new Node(7);
  Node *sec = new Node(13);
  Node *third = new Node(11);
  Node *fourth = new Node(10);
  Node *fifth = new Node(1);

  head->next = sec;
  sec->next = third;
  third->next = fourth;
  fourth->next = fifth;

  head->random = nullptr;
  sec->random = head;
  third->random = fifth;
  fourth->random = third;
  fifth->random = head;

  Node *new_head = copyRandomList(head);
  std::cout << new_head->next->next->val << std::endl;
}
