/**
 * huffman.h
 * Purpose: Header file for huffman
 *  
 * @author Rahul W
 * @version 0.1 02/11/20
 */

#include <string>
#include <queue>
#include <map>


// Node in the huffman tree
struct Node {
  unsigned frequency;
  char data;
  Node *left;
  Node *right;

  Node(char data, unsigned frequency) {
    left = right = nullptr;
    this->data = data;
    this->frequency = frequency;
  }
};

// Functor for comparing two nodes in Huffman tree
class CompareNodes {
  public:
    bool operator()(Node *one, Node *two);
};


// Class for huffman
class Huffman {
  public:
    // Default constructor
    Huffman();

    // Constructor with string input
    Huffman(std::string str);

    // Constructs the Huffman coding for a string
    void ConstructCoding(std::string str);

    // Print codes
    void PrintCodes();

    // Decode a constructed Huffman code
    void Decode();

  private:
    // Root node
    Node *root;

    // Type definition for priority queue
    typedef std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;

    // Constructs a priority queue using the frequency map
    pq ConstructPriorityQueue(std::map<std::string, int> frequencyMap);
};