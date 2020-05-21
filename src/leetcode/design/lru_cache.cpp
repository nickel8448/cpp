#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
 public:
  LRUCache(int capacity) { _capacity = capacity; }

  int get(int key) {
    if (_position_map.find(key) == _position_map.end()) {
      // key not found in the map
      return -1;
    }
    // find the position of the key
    auto itr = _position_map[key];
    // move the found cache to the front
    _lru.push_front(*itr);
    // delete the duplicate copy of the original one
    _lru.erase(itr);
    // update the position of key to new position: begin()
    _position_map[key] = _lru.begin();
    return _position_map[key]->_value;
  }

  void put(int key, int value) {
    // 1. if the map already contains it then the linked list needs to be
    // updated too - done
    // 2. if the map does not contain it then then a new node is created at the
    // head - completed
    if (_position_map.find(key) == _position_map.end()) {
      // insert the new cache value to the front
      _lru.push_front(cache_node(key, value));
      _position_map[key] = _lru.begin();
      if (_lru.size() > _capacity) {
        // delete the last elements' iterator in the map, and delete the last
        // element
        cache_node last_node = _lru.back();
        _position_map.erase(last_node._key);
        _lru.pop_back();
      }
    } else {
      // find the position and update it
      auto itr = _position_map[key];
      itr->_value = value;
      _lru.push_front(*itr);
      _lru.erase(itr);
      _position_map[key] = _lru.begin();
    }
  }

 private:
  struct cache_node {
    int _key;
    int _value;
    cache_node(int key, int value) : _key(key), _value(value) {}
  };

  // list of element 1. MSU and last = LRU
  std::list<cache_node> _lru;
  // <key, <value, key iterator>>
  // The iterator is as good as the position of the node
  std::unordered_map<int, std::list<cache_node>::iterator> _position_map;
  int _capacity;
};

int main() {
  LRUCache lr(2);
  lr.put(1, 1);
  lr.put(2, 2);
  std::cout << lr.get(1) << std::endl;
  lr.put(3, 3);
  std::cout << lr.get(2) << std::endl;
}
