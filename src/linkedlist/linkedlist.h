#ifndef LINKEDLIST
#define LINKEDLIST

struct ListNode {
  int data;
  ListNode *next;
};

class LinkedList {
  public: // Default constructor
    LinkedList();

    // TODO: Fix the initializer list and check why it doesn't work with print
    LinkedList(std::initializer_list<int> init_list);

    // Add a node to the linked list
    void AddNode(int data);

    // Prints the linkedlist
    void PrintList();

    // Inserts a node at the tail of the linkedlist
    void InsertNodeAtTail(int data);

    // Reverses a linkedlist
    void ReverseLinkedList();

    // Compares two linked list
    bool CompareLinkedLists(const LinkedList *l1, const LinkedList *l2);

    // Get n node from the tail
    int GetNodeFromTail(const LinkedList *l1, int position);

    // Removes duplicates from a sorted linked list
    void RemoveDuplicates(LinkedList *l1);

    // Remove duplicates from a sorted linked list Leetcode problem
    void RemoveDuplicatesLC();

  private:
    ListNode *head;

    // Prints the linkedlist starting from the head
    void PrintList(ListNode *head);

    // Inserts a node at the tail of the linkedlist
    ListNode* InsertNodeAtTail(ListNode *head, int data);

    // Helper function to reverse a linkedlist
    ListNode* ReverseLinkedList(ListNode *head);

    ListNode* ReverseLinkedListHelper(ListNode *head, ListNode *prev);

    // Compares two linked list. The lists are equal only if they have the
    // same number of nodes and corresponding nodes contain the same data.
    bool CompareLinkedLists(ListNode *head1, ListNode *head2);

    // Get n node from the tail helper function
    int GetNodeFromTail(ListNode *head, int position);

    // Removes duplicates from a sorted linked lis helper function
    ListNode* RemoveDuplicates(ListNode *head);

    // Remove duplicates from a sorted linked list Leetcode problem
    ListNode* RemoveDuplicatesLC(ListNode *head);
};

#endif
