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

class PatternSearch
{
 public:
  PatternSearch()
  {}


  bool BfSearch(string s, string pattern)
  {
    int s_size = s.size();
    int pattern_size = pattern.size();
    if (s_size < pattern_size)
    {
      return false;
    }

    for (int i = 0; i < s_size - pattern_size; ++i)
    {
      int s_pos = i;
      int p_pos = 0;
      while (p_pos < pattern_size)
      {
        if (s[s_pos] == pattern[p_pos])
        {
          ++s_pos;
          ++p_pos;
        }
        else
        {
          break;
        }
      }
      if (p_pos == pattern_size)
      {
        return true;
      }
    }

    return false;
  }
};

class Solution {
 public:
  void RunTest()
  {
    PatternSearch ps;
    int result = ps.BfSearch("THIS IS A TEST TEXT", "TEST");
    cout << result << endl;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
