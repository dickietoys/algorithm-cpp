#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================LPS=========================" << endl;
    string str = "forgeeksskeegfor";
    int longest = BruteResult(str);
    cout << "BruteResult: " << longest << endl;
    longest = DpResult(str);
    cout << "DpResult: " << longest << endl;
    cout << "=========================LPS=========================" << endl;
  }

  int DpResult(string &s)
  {
    int length = s.size();
    vector<vector<int>> bookmark(s.size(), vector<int>(s.size(), 0));
    int max = 0;
    for (int i = 0; i < length; ++i)
    {
      bookmark[i][i] = 1;
      max = 1;
    }

    for (int i = 0; i < length - 1; ++i)
    {
      if (s[i] == s[i+1])
      {
        bookmark[i][i+1] = 1;
        max = 2;
      }
    }

    for (int i = 3; i <= length; ++i)
    {
      for (int j = 0; j <= length - i; ++j)
      {
        int k = j + i - 1;
        if (s[j] == s[k] && bookmark[j+1][k-1])
        {
          bookmark[j][k] = 1;
          max = std::max(max, k - j + 1);
        }
      }
    }

    return max;
  }

  int BruteResult(string &s)
  {
    int max = 0;
    int length = s.size();
    for (int i = 0; i < length; ++i)
    {
      for (int j = i; j < length; ++j)
      {
        int left = i;
        int right = j;
        bool isPs = true;
        while (left <= right)
        {
          if (s[left] == s[right])
          {
            ++left;
            --right;
          }
          else
          {
            isPs = false;
            break;
          }
        }

        if (isPs)
        {
          max = std::max(max, j - i + 1);
        }
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
