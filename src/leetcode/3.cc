#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string s = "abcabcbb";
    int n =  0;
    n = lengthOfLongestSubstring(s);
    assert(n == 3);

    s = "bbbbb";
    n = lengthOfLongestSubstring(s);
    assert(n == 1);

    s = "pwwkew";
    n = lengthOfLongestSubstring(s);
    assert(n == 3);
  }

  int lengthOfLongestSubstring(string s)
  {
    int i = 0;
    int j = 0;
    unordered_set<char> bookmark;
    int max = 0;
    while (i < s.size() && j < s.size())
    {
      if (!bookmark.count(s[j]))
      {
        max = std::max(max, j - i + 1);
        bookmark.insert(s[j]);
        ++j;
      }
      else
      {
        bookmark.erase(s[i]);
        ++i;
      }
    }

    return max;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
