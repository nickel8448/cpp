/**
 * tree.cc
 * Purpose: Implementation of Huffman coding
 *  
 * @author Rahul W
 * @version 0.1 02/11/20
 */

#include "huffman.h"


Huffman::Huffman() {

}


Huffman::Huffman(std::string str) {

}


void Huffman::ConstructCoding(std::string str) {
  
}


bool CompareNodes::operator()(Node *one, Node *two) {
  return (one->frequency > two->frequency);
}