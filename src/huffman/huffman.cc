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
  minHeap = ConstructPriorityQueue(wordFrequencyMap);
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


void Huffman::PrintCodes() {
  PrintCodes(minHeap.top(), "");
}


void Huffman::PrintCodes(Node *root, std::string str) {
  if (root == nullptr) return;
  if (root->data != '$') std::cout << root->data << ": " << str << "\n";
  PrintCodes(root->left, str + "0");
  PrintCodes(root->right, str + "1");
}


bool CompareNodes::operator()(Node *one, Node *two) {
  return (one->frequency > two->frequency);
}


void Huffman::Decode(std::string str) {
  std::cout << "Decoding: " << str << "\n";
  DecodeLoop(minHeap.top(), str);
}


void Huffman::Decode(Node *root, std::string str, int doneUntil) {
  if(root == nullptr) return;
  if (root->left == nullptr && root->right == nullptr) {
    std::cout << root->data;
    if (doneUntil != str.length()) {
      Decode(minHeap.top(), str, doneUntil);
    }
  }
  if(doneUntil == str.length()) return;
  if(str.at(doneUntil) == '1') {
    Decode(root->right, str, doneUntil + 1);
  } else {
    Decode(root->left, str, doneUntil + 1);
  }
}


void Huffman::DecodeLoop(Node *root, std::string str) {
  Node *current = root;
  for(int i = 0; i < str.length(); ++i) {
    current = str.at(i) == '1' ? current->right : current->left;
    if(current->left == nullptr && current->right == nullptr) {
      std::cout << current->data;
      current = root;
    }
  }
}


int main() {
  Huffman h("aaabc");
  h.PrintCodes();
  h.Decode("1001011");
}
