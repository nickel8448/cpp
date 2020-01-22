#ifndef LINKEDLIST
#define LINKEDLIST

struct ListNode {
  int data;
  ListNode *next;
};

class LinkedList {
  public:
    // Default constructor
    LinkedList();

    // Add a node to the linked list
    void AddNode(int data);

    // Prints the linkedlist
    void PrintList();

    // Inserts a node at the tail of the linkedlist
    void InsertNodeAtTail(int data);

    // Reverses a linkedlist
    void ReverseLinkedList();

    bool CompareLinkedLists(LinkedList *l1, LinkedList *l2);
  private:
    ListNode *head;

    // Prints the linkedlist starting from the head
    void PrintList(ListNode *head);

    // Inserts a node at the tail of the linkedlist
    ListNode* InsertNodeAtTail(ListNode *head, int data);

    // Helper function to reverse a linkedlist
    ListNode* ReverseLinkedList(ListNode *head);

    // Compares two linked list. The lists are equal only if they have the
    // same number of nodes and corresponding nodes contain the same data.
    bool CompareLinkedLists(ListNode *head1, ListNode *head2);
};

#endif
