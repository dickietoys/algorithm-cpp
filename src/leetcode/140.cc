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

  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, vector<string>> dp;
    vector<string> result = Aux(s, wordDict, dp);

    return result;
  }

  vector<string> Aux(string s, vector<string>& wordDict, unordered_map<string, vector<string>> &dp)
  {
    if (dp.count(s))
    {
      return dp[s];
    }
    vector<string> result;
    if (s.empty())
    {
      return {""};
    }

    for (string word : wordDict)
    {
      if (s.size() >= word.size() && s.substr(0, word.size()) == word)
      {
        vector<string> subs = Aux(s.substr(word.size()), wordDict, dp);
        for (string sub : subs)
        {
          result.push_back(word + (sub.size() ? " " + sub : ""));
        }
      }
    }

    dp[s] = result;
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
