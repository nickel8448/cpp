/**
 * insertionsort.cc
 * Purpose: Functions to sort an int using insertion sort algo
 * 
 * @author Rahul W
 * @version 0.1 10/06/19
 */

class ListNode {

public:
    ListNode();
    ListNode(int val);
    ~ListNode();

    inline void setPrev(ListNode &node) { *prev = node; }
    inline ListNode* getPrev() { return prev; }
    inline void setNext(ListNode &node) { *next = node; }
    inline ListNode* getNext() { return next; }
    inline void setValue(int value) { this->value = value; }
    inline int getValue() { return value; }

private:
    ListNode* prev;
    ListNode* next;
    int value;

};