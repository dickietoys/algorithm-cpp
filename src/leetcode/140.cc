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
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> word_dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> result = wordBreak(s, word_dict);
    Show(result);
  }

  void Aux(string s,
           unordered_set<string> &dict,
           int s_pos,
           vector<string> &item,
           vector<string> &result,
           vector<bool> &dp)
  {
    if (s_pos < 0)
    {
      string one_result;
      for (vector<string>::const_reverse_iterator rit = item.crbegin(); rit != item.crend(); ++rit)
      {
        one_result += *rit + " ";
      }

      result.push_back(one_result.substr(0, one_result.size() - 1));
      return;
    }

    for (int i = s_pos; i >= 0; --i)
    {
      string cur_str = s.substr(i, s_pos - i + 1);
      if (dict.count(cur_str) != 0)
      {
        if (i == 0 || dp[i-1])
        {
          item.push_back(cur_str);
          Aux(s, dict, i - 1, item, result, dp);
          item.pop_back();
        }
      }
    }
  }

  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size(), false);

    unordered_set<string> dict;
    for (const string &item : wordDict)
    {
      dict.insert(item);
    }

    for (int i = 0; i < s.size(); ++i)
    {
      for (int j = 0; j <= i; ++j)
      {
        int left = i - j;
        int right = i;
        if (left == 0)
        {
          if (dict.count(s.substr(left, right - left + 1)) == 1)
          {
            dp[i] = true;
            break;
          }
        }
        else if (dp[left-1] && dict.count(s.substr(left, right - left + 1)) == 1)
        {
          dp[i] = true;
          break;
        }
      }
    }

    vector<string> result;
    vector<string> item;
    Aux(s, dict, s.size() - 1, item, result, dp);

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
