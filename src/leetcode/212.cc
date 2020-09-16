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

  bool startWith(string word)
  {
    TrieNode *node = root;
    if (!node)
    {
      return false;
    }
    for (int i = 0; i < word.size(); ++i)
    {
      int index = word[i] - 'a';
      if (!node->children[index])
      {
        return false;
      }
      node = node->children[index];
    }

    return true;
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


class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    WordDictionary word_dict;
    for (auto word : words)
    {
      word_dict.addWord(word);
    }

    unordered_set<string> unique_result;
    int row_size = board.size();
    int col_size = board[0].size();
    vector<vector<bool>> visited(row_size, vector<bool>(col_size, false));
    for (int i = 0; i < row_size; ++i)
    {
      for (int j = 0; j < col_size; ++j)
      {
        Search(board, word_dict, i, j, visited, "", unique_result);
      }
    }

    vector<string> result(unique_result.begin(), unique_result.end());
    return result;
  }

  void Search(vector<vector<char>>& board,
              WordDictionary &word_dict,
              int row_pos,
              int col_pos,
              vector<vector<bool>> visited,
              string str,
              unordered_set<string> &unique_result)
  {
    int row_size = board.size();
    int col_size = board[0].size();
    if (row_pos < 0 || row_pos >= row_size || col_pos < 0 || col_pos >= col_size)
    {
      return;
    }
    if (visited[row_pos][col_pos])
    {
      return;
    }
    str += board[row_pos][col_pos];
    if (!word_dict.startWith(str))
    {
      return;
    }

    if (word_dict.search(str))
    {
      unique_result.insert(str);
    }

    visited[row_pos][col_pos] = true;
    Search(board, word_dict, row_pos - 1, col_pos, visited, str, unique_result);
    Search(board, word_dict, row_pos + 1, col_pos, visited, str, unique_result);
    Search(board, word_dict, row_pos, col_pos - 1, visited, str, unique_result);
    Search(board, word_dict, row_pos, col_pos + 1, visited, str, unique_result);
    visited[row_pos][col_pos] = false;
  }
};
