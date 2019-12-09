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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    string result;

    input = {1};
    result = minWindow("ADOBECODEBANC", "ABC");
    cout << "result: " << result << endl;
    assert(result == "BANC");

  }

  string minWindow(string s, string t)
  {
    vector<int> bookmark(128, 0);
    int size = s.size();
    int begin = 0;
    int end = 0;
    int counter = t.size();
    int minStart = 0;
    int minLen = std::numeric_limits<int>::max();
    for (size_t i = 0; i < t.size(); ++i)
    {
      ++bookmark[t[i]];
    }

    while (end < size)
    {
      if (bookmark[s[end]] > 0)
      {
        --counter;
      }
      --bookmark[s[end]];
      ++end;
      while (counter == 0)
      {
        if (end - begin < minLen)
        {
          minLen = end - begin;
          minStart = begin;
        }
        ++bookmark[s[begin]];
        if (bookmark[s[begin]] > 0)
        {
          ++counter;
        }
        ++begin;
      }
    }

    if (minLen != std::numeric_limits<int>::max())
    {
      return s.substr(minStart, minLen);
    }

    return "";
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
