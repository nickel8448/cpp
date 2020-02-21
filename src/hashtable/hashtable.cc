#include <iostream>
#include <string>

#include "hashtable.h"

// TODO: Create an array of primes and check how to use them

template<typename K, typename V, typename F>
HashTable<K, V, F>::HashTable() {
  this->nodesTable = new HashNode<K, V>* [startingTableSize]();
  // for (int i = 0; i < startingTableSize; ++i) {
  //   nodesTable[i] = nullptr;
  // }
}


template<typename K, typename V, typename F>
void HashTable<K, V, F>::CheckLoadAndResize() {
  double currentLoad = static_cast<double>(capacity) / size;
  if(currentLoad > loadFactor) {
    this->Resize();
  }
}

template<typename K, typename V, typename F>
bool HashTable<K, V, F>::Put(K key, V value) {
  CheckLoadAndResize();
  unsigned long hashValue = HashFunction(key, this->size);
  std::cout << hashValue << std::endl;
  return false;
}


int main() {
  HashTable<int, std::string> ht;
  ht.Put(10, "Hello");
}
