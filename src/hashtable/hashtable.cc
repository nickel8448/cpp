#include <iostream>
#include <string>
#include <typeinfo>

#include "hashtable.h"

// TODO: Create an array of primes and check how to use them

template<typename K, typename V, typename F>
HashTable<K, V, F>::HashTable() {
  this->nodesTable = new HashNode<K, V>* [startingTableSize]();
  for (int i = 0; i < startingTableSize; ++i) {
    nodesTable[i] = nullptr;
  }
}


template<typename K, typename V, typename F>
void HashTable<K, V, F>::PrintTable() {
  for(int i = 0; i < this->size; ++i) {
    std::cout << i << " - ";
    HashNode<K, V> *node = nodesTable[i];
    if(nodesTable[i] != nullptr) {
      while (node != nullptr) {
        std::cout << node->GetKey() << ": " << node->GetValue();
        node = node->GetNext();
        if (node != nullptr)
          std::cout << " -> ";
      }
    }
    std::cout << std::endl;
  }
}


template<typename K, typename V, typename F>
void HashTable<K, V, F>::CheckLoadAndResize() {
  double currentLoad = static_cast<double>(capacity) / size;
  if(currentLoad > loadFactor) {
    this->Resize();
  }
}


template<typename K, typename V, typename F>
void HashTable<K, V, F>::Resize() {
  // If the size of the table increases more than 7199369 the next prime
  // number will need to be calculated
  for (int i = currentPrimeIndex + 1; i < numberOfPrimeNumbersAvailable; ++i) {
    if (PrimeNumbers[i] > (size * 2)) {
      size = PrimeNumbers[i];
      break;
    }
  }
  std::cout << "New size: " << size << std::endl;
}


template<typename K, typename V, typename F>
bool HashTable<K, V, F>::Put(K key, V value) {
  CheckLoadAndResize();
  unsigned long hashValue = HashFunction(key, this->size);
  HashNode<K, V> *position = nodesTable[hashValue];
  HashNode<K, V> *nodeToInsert = new HashNode<K, V>(key, value);
  if (position == nullptr) {
    // There is no node in the position right now
    nodesTable[hashValue] = nodeToInsert;  
    ++capacity;
    return true;
  } else {
    // There is already a node in the slot
    HashNode<K, V> *currentNode = nodesTable[hashValue];
    while(currentNode->GetNext() != nullptr) {
      currentNode = currentNode->GetNext();
    }
    currentNode->SetNext(nodeToInsert);
    return true;
  }
  return false;
}


int main() {
  HashTable<int, std::string> ht;
  ht.Put(10, "Hello");
  ht.Put(11, "Yo");
  ht.Put(10, "World");
  ht.PrintTable();
}
