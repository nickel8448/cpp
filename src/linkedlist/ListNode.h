/**
 * insertionsort.cc
 * Purpose: Functions to sort an int using insertion sort algo
 * 
 * @author Rahul W
 * @version 0.1 10/06/19
 */

class ListNode {

public:
    ListNode() = default;

    explicit ListNode(int val) : value(val) {} 

    inline void setValue(int value) { this->value = value; }
    inline int getValue() { return value; }

private:
    ListNode* prev;
    ListNode* next;
    int value;

};