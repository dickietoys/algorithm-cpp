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

class Solution {
 public:
  void RunTest()
  {
    string result;
    result = longestPalindrome("bb");
  }

  string longestPalindrome(string s) {
    string result = "";
    if (s.empty())
    {
      return result;
    }
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    vector<int> memory(2, 0);
    for (int i = 0; i < s.size(); ++i)
    {
      dp[i][i] = true;
      memory[0] = i;
      memory[1] = 1;
    }

    for (int i = 1; i < s.size(); ++i)
    {
      if (s[i] == s[i-1])
      {
        dp[i-1][i] = true;
        memory[0] = i-1;
        memory[1] = 2;
      }
    }

    for (int i = 3; i <= s.size(); ++i)
    {
      for (int j = 0; j + i - 1 < s.size(); ++j)
      {
        if (s[j] == s[j+i-1] && dp[j+1][j+i-1-1])
        {
          dp[j][j+i-1] = true;
          memory[0] = j;
          memory[1] = i;
        }
      }
    }

    return s.substr(memory[0], memory[1]);
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
