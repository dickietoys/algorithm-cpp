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
#include <functional>
#include <list>
#include <exception>

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

class Solution {
 public:
  void RunTest()
  {
    vector<int> result = findAnagrams("cbaebabacd", "abc");
    Show(result);
  }

  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int left = 0;
    int right = 0;
    unordered_map<int, int> hashmap;
    for (char c : p)
    {
      ++hashmap[c];
    }

    int count = 0;
    while (right < s.size())
    {
      --hashmap[s[right]];
      if (hashmap[s[right]] >= 0)
      {
        ++count;
      }

      if (right - left + 1 != p.size())
      {
        ++right;
        continue;
      }

      if (count == p.size())
      {
        result.push_back(left);
      }

      ++hashmap[s[left]];
      if (hashmap[s[left]] > 0)
      {
        --count;
      }

      ++left;
      ++right;
    }

    return result;
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
  delete solution;
  return 0;
}
