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
    string s = "babad";
    string result = "";
    result = longestPalindrome(s);
    cout << "result: " << result << endl;
    assert(result == "bab");

    s = "cbbd";
    result = longestPalindrome(s);
    cout << "result: " << result << endl;
    assert(result == "bb");
  }

  string longestPalindrome(string s) {
    if (s == "")
    {
      return "";
    }
    vector<int> maxPos(2, 0);
    int max = 0;
    vector<vector<bool>> bookmark(s.size(), vector<bool>(s.size(), 0));
    for (int i = 0; i < s.size(); ++i)
    {
      bookmark[i][i] = true;
      max = 1;
      maxPos[0] = i;
      maxPos[1] = i;
    }

    for (int i = 0; i < s.size() - 1; ++i)
    {
      if (s[i] == s[i+1])
      {
        bookmark[i][i+1] = true;
        max = 2;
        maxPos[0] = i;
        maxPos[1] = i+1;
      }
    }

    for (int i = 3; i <= s.size(); ++i)
    {
      for (int j = 0; j <= s.size() - i; ++j)
      {
        int k = j + i - 1;
        if (s[j] == s[k] && bookmark[j+1][k-1])
        {
          bookmark[j][k] = true;
          if (max < k-j+1)
          {
            maxPos[0] = j;
            maxPos[1] = k;
            max = k-j+1;
          }
        }
      }
    }

    return s.substr(maxPos[0], maxPos[1] - maxPos[0] + 1);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
