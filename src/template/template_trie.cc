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
#include <queue>
#include <list>

using namespace std;


struct TrieNode {
  vector<TrieNode *> children;
  bool end_of_word;

  TrieNode()
      : children(26, NULL)
  {}
};

class Trie
{
 private:
  TrieNode root;
 public:
  Trie()
  {}

  void Insert(const string &s)
  {
    TrieNode *node = &root;
    int s_size = s.size();
    for (int i = 0; i < s_size; ++i)
    {
      int index = s[i] - 'a';
      if (!node->children[index])
      {
        node->children[index] = new TrieNode();
      }

      node = node->children[index];
    }

    node->end_of_word = true;
  }

  bool Search(const string &s)
  {
    TrieNode *node = &root;
    int s_size = s.size();
    for (int i = 0; i < s_size; ++i)
    {
      int index = s[i] - 'a';
      if (!node->children[index])
      {
        return false;
      }

      node = node->children[index];
    }

    return node->end_of_word;
  }

  bool HasChildren(TrieNode *node)
  {
    for (TrieNode *item : node->children)
    {
      if (item)
      {
        return true;
      }
    }

    return false;
  }

  TrieNode *DeleteAux(TrieNode *node, const string &s, int depth)
  {
    if (!node)
    {
      return nullptr;
    }

    if (depth == s.size())
    {
      if (node->end_of_word)
      {
        node->end_of_word = false;
      }

      if (!HasChildren(node))
      {
        delete node;
        node = nullptr;
      }

      return node;
    }

    int index = s[depth] - 'a';
    node->children[index] = DeleteAux(node->children[index], s, depth + 1);
    if (!HasChildren(node) && !node->end_of_word)
    {
      delete  node;
      node = nullptr;
    }

    return node;
  }

  void Delete(const string &s)
  {
    if (s.empty())
    {
      return;
    }

    DeleteAux(&root, s, 0);
  }
};


class Solution {
 public:
  void RunTest()
  {
    Trie t;
    vector<string> keys = {"the", "a", "there",
                           "answer", "any", "by",
                           "bye", "their"};
    for (string &s : keys)
    {
      t.Insert(s);
    }

    cout << t.Search("the") << endl;
    cout << t.Search("these") << endl;
    cout << t.Search("answer") << endl;
    t.Delete("the");
    cout << t.Search("the") << endl;
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", " << endl;
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
