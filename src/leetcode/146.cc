#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>
#include <list>

using namespace std;

class LRUCache {
 public:
private:
  int capacity_;
  list<int> lru_;
  unordered_map<int, list<int>::iterator> data_;
  unordered_map<int, int> key_value;

public:
  LRUCache(int capacity) :
      capacity_(capacity)
  {}

  int get(int key) {
    if (data_.count(key) == 0)
    {
      return -1;
    }
    refreshValue(key);

    return key_value[key];
  }

  void put(int key, int value) {
    if (data_.count(key) == 0)
    {
      if (capacity_ == lru_.size())
      {
        int dirty_key = lru_.back();
        lru_.erase(data_[dirty_key]);
        key_value.erase(dirty_key);
        data_.erase(dirty_key);
      }
      key_value[key] = value;
      lru_.push_front(key);
      data_[key] = lru_.begin();
    }
    else
    {
      key_value[key] = value;
      refreshValue(key);
    }
  }

  void refreshValue(int key)
  {
    lru_.erase(data_[key]);
    lru_.push_front(key);
    data_[key] = lru_.begin();
  }
};
