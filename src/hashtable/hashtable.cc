#include "hashtable.h"


template<typename K, typename V, typename F>
HashTable<K, V, F>::HashTable() {
  this->nodesTable = new HashNode<K, V>* [startingTableSize]();
}


int main() {

}
