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

class Solution {
 public:
  void RunTest()
  {
    vector<string> wordDict = {"image", "classify"};
    string s = "imageclassify";

    bool result = wordBreak(s, wordDict);
    cout << result << endl;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool> word_map;
    for (string &item : wordDict)
    {
      word_map[item] = true;
    }

    return DpAux(word_map, s);
  }

  bool DpAux(unordered_map<string, bool> &word_map, const string &s)
  {
    int s_size = s.size();
    vector<bool> dp(s_size + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        if (dp[j] && word_map.count(s.substr(j, i - j)) != 0)
        {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[s_size];
  }

  bool Aux(unordered_map<string, bool> &word_map, const string &s)
  {
    int s_size = s.size();
    if (s_size == 0)
    {
      return true;
    }

    for (int i = 1; i <= s.size(); ++i)
    {
      if (word_map.count(s.substr(0, i)) != 0 && Aux(word_map, s.substr(i, s.size() - i + 1)))
      {
        return true;
      }
    }

    return false;
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
