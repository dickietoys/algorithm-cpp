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

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
 public:
  void RunTest()
  {
    string result = longestPalindrome("abcda");
    cout << result << endl;
  }

  string longestPalindrome(string s) {
    int max_size = 0;
    string result;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
    for (int i = 0; i < s.size(); ++i)
    {
      dp[i][i] = true;
      max_size = 1;
      result = s.substr(i, 1);
    }

    for (int i = 1; i < s.size(); ++i)
    {
      if (s[i-1] == s[i])
      {
        dp[i-1][i] = true;
        max_size = 2;
        result = s.substr(i-1, 2);
      }
    }

    for (int i = 3; i <= s.size(); ++i)
    {
      for (int j = 0; j + i - 1 < s.size(); ++j)
      {
        int low = j;
        int high = j + i - 1;
        if (s[low] == s[high] && dp[low+1][high-1])
        {
          dp[low][high] = true;
          if (i > max_size)
          {
            max_size = i;
            result = s.substr(j, i);
          }
        }
      }
    }

    return result;
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
