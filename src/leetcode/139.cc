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

    return Aux(word_map, s);
  }

  bool Aux(unordered_map<string, bool> &word_map, const string &s)
  {
    int s_size = s.size();
    if (s_size == 0)
    {
      return true;
    }

    bool has = false;
    for (int i = 1; i <= s_size; ++i)
    {
      string tmp_s = s.substr(0, i);
      if (word_map[tmp_s])
      {
        has = Aux(word_map, s.substr(i, s_size - i + 1));
        if (has)
        {
          return has;
        }
      }
    }

    return has;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
