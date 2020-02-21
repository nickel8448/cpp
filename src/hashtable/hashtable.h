#ifndef HASHTABLE
#define HASHTABLE

#include <vector>

template <typename K, typename V>
class HashNode {
  public:
    // Constructor to create a node with key value pair
    HashNode(K key, V value) : key(key), value(value), next(nullptr) {}
    
    K GetKey() {
      return this->key;
    }

    V GetValue() {
      return this->value;
    }

    HashNode *GetNext() {
      return this->next;
    }

    void SetValue(V value) {
      this->value = value;
    }

    void SetNext(HashNode *next) {
      this->next = next;
    }
  
  private:
    // Key value pair
    K key;
    V value;

    // Next node for separate chaining
    HashNode *next;
};


template <typename K>
class HashFunction {
  public:
    unsigned long operator()(const K &key, int tableSize) const {
      return static_cast<unsigned long> (key % tableSize);
    }
};



template <typename K, typename V, typename F = HashFunction<K>>
class HashTable {
  public:
    // Constructor
    HashTable();

    // Prints the hash table
    void PrintTable();

    // Function to add key and value pair to HashTable. Returns true if the
    // the key was added successfully
    bool Put(K key, V value);


  private:
    // Load factor for the HashTable
    const double loadFactor = 0.75;

    // Variable to track the number of items in the HashTable
    int capacity = 0;

    // Starting size of the table
    int startingTableSize = 11;

    // Variable to track the current size of the HashTable
    int size = startingTableSize;

    // Table of nodes
    HashNode<K, V> **nodesTable;

    // Hash Function
    F HashFunction;

    // Checks the current load factor and resizes the table if required
    void CheckLoadAndResize();

    // Resize function
    void Resize();

    // Tracking the current prime number being used
    int currentPrimeIndex = 2;

    const int numberOfPrimeNumbersAvailable = 76;

    // Array of primes
    int PrimeNumbers[76] = {
      3, 7, 11, 17, 23, 29, 37, 47, 59, 71, 89, 107, 131, 163, 197, 239, 293,
      353, 431, 521, 631, 761, 919, 1103, 1327, 1597, 1931, 2333, 2801, 3371,
      4049, 4861, 5839, 7013, 8419, 10103, 12143, 14591, 17519, 21023, 25229,
      30293, 36353, 43627, 52361, 62851, 75431, 90523, 108631, 130363, 156437,
      187751, 225307, 270371, 324449, 389357, 467237, 560689, 672827, 807403,
      968897, 1162687, 1395263, 1674319, 2009191, 2411033, 2893249, 3471899,
      4166287, 4999559, 5999471, 7199369
    };
};

#endif
