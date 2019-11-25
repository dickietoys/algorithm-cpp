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
    int max = lengthOfLongestSubstring(s);
    cout << "result: " << max << endl;
    assert(max == 3);

    s = "bbbbb";
    max = lengthOfLongestSubstring(s);
    cout << "result: " << max << endl;
    assert(max == 1);

    s = "pwwkew";
    max = lengthOfLongestSubstring(s);
    cout << "result: " << max << endl;
    assert(max == 3);
  }

  int lengthOfLongestSubstring(string s) {
    unordered_set<char> bookmark;
    int maxSize = 0;
    int i = 0;
    int j = 0;
    while (i <= j)
    {
      if (j >= s.size())
      {
        break;
      }

      char curChar = s[j];
      if (!bookmark.count(curChar))
      {
        maxSize = std::max(maxSize, j - i + 1);
        ++j;
        bookmark.insert(curChar);
      }
      else
      {
        char repeatChar = s[i];
        bookmark.erase(repeatChar);
        ++i;
      }
    }

    return maxSize;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
