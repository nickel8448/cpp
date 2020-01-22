#include <iostream>

#include "linkedlist.h"

LinkedList::LinkedList() {
  head = nullptr;
}
 

void LinkedList::AddNode(int data) {
  // TODO: why does this have to be a pointer?
  ListNode *temp = new ListNode();
  temp->data = data;
  if(head == nullptr) {
    head = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}


void LinkedList::PrintList() {
  PrintList(head); 
}


void LinkedList::ReverseLinkedList() {
  head = ReverseLinkedList(head);
}


void LinkedList::InsertNodeAtTail(int data) {
  head = InsertNodeAtTail(head, data);
}


void LinkedList::PrintList(ListNode *head) {
  while (head != nullptr) {
    std::cout << head->data << std::endl;
    head = head->next;
  }
}


ListNode* LinkedList::InsertNodeAtTail(ListNode *head, int data) {
  ListNode *temp = head;
  ListNode *nodeToAdd = new ListNode();
  nodeToAdd->data = data;
  nodeToAdd->next = nullptr;
  if (head == nullptr) {
    head = nodeToAdd;
  } else {
    while(temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = nodeToAdd;
  }
  return head;
}

ListNode* LinkedList::ReverseLinkedList(ListNode *head) {
  ListNode *current = head;
  ListNode *prev = nullptr, *next = nullptr;
  while (current != nullptr) {
    // Store next
    next = current->next;
    
    // Reverse current node's pointer
    current->next = prev;

    // Move pointer one position
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}


bool LinkedList::CompareLinkedLists(LinkedList *l1, LinkedList *l2) {
  return CompareLinkedLists(l1->head, l2->head);
}


bool LinkedList::CompareLinkedLists(ListNode *head1, ListNode *head2) {
  while (head1 != nullptr && head2 != nullptr) {
    if (head1->data != head2->data) return false;
    head1 = head1->next;
    head2 = head2->next;
  }
  return (head1 == nullptr && head2 == nullptr);
}


int main() {
  LinkedList l1, l2, l3;
  l1.AddNode(1);
  l1.AddNode(2);
  l2.AddNode(1);
  l2.AddNode(2);
  std::cout << "Comparing l1 and l2: " << std::boolalpha
            << l1.CompareLinkedLists(&l1, &l2) << std::endl;
}
