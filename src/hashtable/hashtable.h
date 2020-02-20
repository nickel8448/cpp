#ifndef HASHTABLE
#define HASHTABLE

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
    HashFunction(int tableSize) : tableSize(tableSize) {}

    unsigned long operator()(const K &key) const {
      return reinterpret_cast<unsigned long> (key % tableSize);
    }

  private:
    int tableSize;
};



template <typename K, typename V, typename F = HashFunction<K>>
class HashTable {
  public:
    // Constructor
    HashTable();

    // Function to add key and value pair to HashTable. Returns true if the
    // the key was added successfully
    bool Put(K key, V value);


  private:
    // Load factor for the HashTable
    const double loadFactor = 0.75;

    // Variable to track the number of items in the HashTable
    int capacity = 0;

    // Variable to track the current size of the HashTable
    int size = startingTableSize;

    // Starting size of the table
    const int startingTableSize = 10;

    // Table of nodes
    HashNode<K, V> **nodesTable;

    // Hash Function
    F HashFunction;
};

#endif
