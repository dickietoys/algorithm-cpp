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
  }

  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> um1;
    unordered_map<char, int> um2;
    int s_size = s.size();
    int t_size = t.size();
    if (s_size != t_size)
    {
      return false;
    }

    for (int i = 0; i < s_size; ++i)
    {
      um1[s[i]] = um1[s[i]] == 0 ? i + 1 : um1[s[i]];
      um2[t[i]] = um2[t[i]] == 0 ? i + 1 : um2[t[i]];
      if (um1[s[i]] != um2[t[i]])
      {
        return false;
      }
    }

    return true;
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
