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

class WordDictionary {
public:
  struct TrieNode {
    vector<TrieNode *> children;
    bool is_end;
    TrieNode() :
        children(26, nullptr),
        is_end(false)
    {}
  };

  TrieNode *root;
  /** Initialize your data structure here. */
  WordDictionary() :
      root(new TrieNode())
  {}

  /** Adds a word into the data structure. */
  void addWord(string word) {
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

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return search(word, 0, root);
  }

  bool search(string &word, int pos, TrieNode *node)
  {
    int word_size = word.size();
    if (pos == word_size)
    {
      return node->is_end;
    }
    if (word[pos] == '.')
    {
      for (int j = 0; j < 26; ++j)
      {
        if (node->children[j])
        {
          if (search(word, pos + 1, node->children[j]))
          {
            return true;
          }
        }
      }
    }
    else
    {
      int index = word[pos] - 'a';
      if (node->children[index])
      {
        return search(word, pos + 1, node->children[index]);
      }
    }

    return false;
  }
};
