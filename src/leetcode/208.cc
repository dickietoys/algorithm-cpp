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

using namespace std;

class Trie {
public:
  struct TrieNode
  {
    vector<TrieNode *> children;
    bool is_end;
    TrieNode() :
        children(26, nullptr),
        is_end(false)
    {}
  };

  TrieNode *root;

  /** Initialize your data structure here. */
  Trie() :
      root(new TrieNode())
  {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *node = root;
    int word_size = word.size();
    for (int i = 0; i < word_size; ++i)
    {
      int index = word[i] - 'a';
      if (!node->children[index])
      {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->is_end = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *node = root;
    int word_size = word.size();
    for (int i = 0; i < word_size; ++i)
    {
      int index = word[i] - 'a';
      if (!node->children[index])
      {
        return false;
      }
      node = node->children[index];
    }

    return (node != nullptr && node->is_end);
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode *node = root;
    int prefix_size = prefix.size();
    for (int i = 0; i < prefix_size; ++i)
    {
      int index = prefix[i] - 'a';
      if (!node->children[index])
      {
        return false;
      }
      node = node->children[index];
    }

    return (node != nullptr);
  }
};

// ["Trie","insert","search","search","startsWith","insert","search"]
// [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
