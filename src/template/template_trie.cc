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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

  void Delete(const string &s)
  {}
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
