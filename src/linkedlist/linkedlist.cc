#include <cstdlib>
#include <iostream>

#include "linkedlist.h"

LinkedList::LinkedList() {
  head = nullptr;
}


LinkedList::LinkedList(std::initializer_list<int> init_list) {
  for (auto itr = init_list.begin(); itr != init_list.end(); ++itr) {
    this->AddNode(*itr);
  }
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
  ListNode *curr = head;
  while (curr != nullptr) {
    std::cout << curr->data << ", ";
    curr = curr->next;
  }
  std::cout << std::endl;
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
  return ReverseLinkedListHelper(head, nullptr);
}

ListNode* LinkedList::ReverseLinkedListHelper(ListNode *head, ListNode *prev) {
  if (head == nullptr) return prev;
  ListNode *next = head->next;
  head->next = prev;
  return ReverseLinkedListHelper(next, head);
}

// 1. If head is not null, return prev
// 2.

/* ListNode* LinkedList::ReverseLinkedList(ListNode *head) { */
/*   ListNode *current = head; */
/*   ListNode *prev = nullptr, *next = nullptr; */
/*   while (current != nullptr) { */
/*     // Store next */
/*     next = current->next; */
/*     // Reverse current node's pointer */
/*     current->next = prev; */

/*     // Move pointer one position */
/*     prev = current; */
/*     current = next; */
/*   } */
/*   head = prev; */
/*   return head; */
/* } */


bool LinkedList::CompareLinkedLists(const LinkedList *l1,
    const LinkedList *l2) {
  return CompareLinkedLists(l1->head, l2->head);
}


bool LinkedList::CompareLinkedLists(ListNode *head1, ListNode *head2) {
  ListNode *anchorNode = new ListNode;
  ListNode *bridge = anchorNode;
  while(head1 && head2) {
    if (head1->data < head2->data) {
      bridge->next = head1;
      head1 = head1->next;
    } else {
      bridge->next = head2;
      head2 = head2->next;
    }
    bridge = bridge->next;
  }
  bridge->next = head1 ? head1 : head2;
  return anchorNode->next;
}


void LinkedList::RemoveDuplicates(LinkedList *l1) {
  l1->head = RemoveDuplicates(l1->head);
}


ListNode* LinkedList::RemoveDuplicates(ListNode *head) {
  ListNode *current = head; // might not need this
  ListNode *traversal = new ListNode;
  while (current != nullptr && current->next != nullptr) {
    if(current->data == current->next->data) {
      traversal = current->next->next;
      if (traversal == nullptr) {
        current->next = nullptr;
        break;
      }
      current->next = traversal;
    }
    if(current->data != current->next->data) current = current->next;
  }
  return head;
}


int LinkedList::GetNodeFromTail(const LinkedList *l1, int position) {
  return GetNodeFromTail(l1->head, position);
}

int LinkedList::GetNodeFromTail(ListNode *head, int position) {
  ListNode *refNode = head;
  for(int i = 0; i <= position; ++i) {
    refNode = refNode->next;
  }
  while (refNode != nullptr) {
    head = head->next;
    refNode = refNode->next;
  }
  return head->data;
}


void LinkedList::RemoveDuplicatesLC() {
  this->head = RemoveDuplicatesLC(head);
}


ListNode* LinkedList::RemoveDuplicatesLC(ListNode* head) {
  if (head == nullptr) return head;
  ListNode *curr = head;
  ListNode *trav = curr->next;
  while(trav != nullptr) {
    while(trav->data == curr->data) {
      trav = trav->next;
      if (trav == nullptr) break;
    }
    curr->next = trav;
    if (trav != nullptr)
      curr = curr->next;
  }
  return head;
}


int main() {
  std::cout << "L1: " << std::endl;
  LinkedList l1;
  l1.AddNode(3);
  l1.AddNode(3);
  l1.AddNode(2);
  l1.AddNode(1);
  l1.PrintList();
  l1.RemoveDuplicatesLC();
  l1.PrintList();
  std::cout << "L1 ends " << std::endl;

  std::cout << "L2: " << std::endl;
  LinkedList l2;
  l2.AddNode(1);
  l2.PrintList();
  l2.RemoveDuplicatesLC();
  l2.PrintList();

  std::cout << "L2 ends " << std::endl;
  std::cout << "L3: " << std::endl;
  LinkedList l3;
  l3.AddNode(2);
  l3.AddNode(1);
  l3.AddNode(1);
  l3.PrintList();
  l3.RemoveDuplicatesLC();
  l3.PrintList();

  std::cout << "L3 ends " << std::endl;

  std::cout << "L4: " << std::endl;
  LinkedList l4;
  l4.AddNode(1);
  l4.AddNode(1);
  l4.PrintList();
  l4.RemoveDuplicatesLC();
  l4.PrintList();

  // l2.RemoveDuplicatesLC();
  // l2.PrintList();
  // l3.PrintList();
  // l3.RemoveDuplicatesLC();
  // l3.PrintList();
}
