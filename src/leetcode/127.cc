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
#include <bitset>

using namespace std;

class Solution {
 public:

  void RunTest()
  {
    int result = 0;
  }

  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {

  }

  int ladderLength(string &beginWord, string &endWord, vector<string>& wordList)
  {
    if (beginWord == endWord)
    {
      return 0;
    }

    int size = beginWord.size();
    for (int i = 0; i < size; ++i)
    {
      if (beginWord[i] == endWord[i])
      {
        for (int j = 0; i < wordList[j].size(); ++j)
        {
          if (IsValid(beginWord, wordList[j]))
          {

          }
        }
      }
    }
  }

  bool IsValid(string &src, string &target)
  {
    int diff_count = 0;
    int size = src.size();
    for (int i = 0; i < size; ++i)
    {
      if (src[i] != target[i])
      {
        ++diff_count;
      }
    }

    if (diff_count == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int Aux(string &beginWord, string &endWord, vector<string>& wordList)
  {

  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
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
