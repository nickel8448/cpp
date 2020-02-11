/**
 * tree.cc
 * Purpose: Implementation of Huffman coding
 *  
 * @author Rahul W
 * @version 0.1 02/11/20
 */

#include <iostream>

#include "huffman.h"


Huffman::Huffman(std::string str) {
  ConstructCoding(str);
}


void Huffman::ConstructCoding(std::string str) {
  std::map<char, int> wordFrequencyMap = ReturnFrequencyMap(str);
  pq minHeap = ConstructPriorityQueue(wordFrequencyMap);
  while(minHeap.size() != 1) {
    Node *left = minHeap.top();
    minHeap.pop();
    Node *right = minHeap.top();
    minHeap.pop();
    Node *top = new Node('$', left->frequency + right->frequency);
    top->left = left;
    top->right = right;
    minHeap.push(top);
  }
  std::cout << "top node: " << minHeap.top()->data << std::endl;
  std::cout << "top node frequency: " << minHeap.top()->frequency << std::endl;
}


std::map<char, int> Huffman::ReturnFrequencyMap(std::string str) {
  std::map<char, int> toReturn;
  for (unsigned i = 0; i < str.length(); ++i) {
    char toInsert = str.at(i);
    auto itrKey = toReturn.find(toInsert);
    if (itrKey != toReturn.end()) {
      // Value is in the map
      itrKey->second = itrKey->second+1;
    } else {
      // Value is not in the map
      toReturn.insert(std::make_pair(toInsert, 1));
    }
  }
  return toReturn;
}


pq Huffman::ConstructPriorityQueue(std::map<char, int> frequencyMap) {
  // Inserting all the nodes in the priority queue
  pq toReturn;
  for(auto itr = frequencyMap.begin(); itr != frequencyMap.end(); ++itr) {
    toReturn.push(new Node(itr->first, itr->second));
  }
  return toReturn;
}


bool CompareNodes::operator()(Node *one, Node *two) {
  return (one->frequency > two->frequency);
}


int main() {
  Huffman h("hello");  
}
