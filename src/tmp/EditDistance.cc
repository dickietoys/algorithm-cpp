#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================EditDistance=========================" << endl;
    string str1 = "sunday";
    string str2 = "saturday";
    int count = BruteResult(str1, str2);
    cout << "BruteResult: " << count << endl;
    count = BruteResult(str1, str2);
    cout << "DpResult: " << count << endl;
    cout << "=========================EditDistance=========================" << endl;
  }

  int DpResult(string &s1, string &s2)
  {
    vector<vector<int>> bookmark(s1.size(), vector<int>(s2.size(), 0));
    if (s1[0] != s2[0])
    {
      bookmark[0][0] = 1;
    }

    for (size_t i = 1; i < s2.size(); ++i)
    {
      if (s1[0] == s2[i])
      {
        bookmark[0][i] = i;
      }
      else
      {
        bookmark[0][i] = bookmark[0][i-1] + 1;
      }
    }

    for (size_t i = 1; i < s1.size(); ++i)
    {
      if (s2[0] == s1[i])
      {
        bookmark[i][0] = i;
      }
      else
      {
        bookmark[i][0] = bookmark[i-1][0] + 1;
      }
    }

    for (int i = 1; i < s1.size(); ++i)
    {
      for (int j = 1; j < s2.size(); ++j)
      {
        if (s1[i] == s2[j])
        {
          bookmark[i][j] = bookmark[i-1][j-1];
        }
        else
        {
          bookmark[i][j] = std::min({bookmark[i-1][j], bookmark[i][j-1], bookmark[i-1][j-1]}) + 1;
        }
      }
    }

    return bookmark[s1.size() - 1][s2.size() - 1];
  }

  int BruteResult(string &s1, string &s2)
  {
    return BruteResultAux(s1, 0, s2, 0);
  }

  int BruteResultAux(string &s1, int pos1, string &s2, int pos2)
  {
    if (pos1 >= s1.size())
    {
      return s2.size() - pos2;
    }

    if (pos2 >= s2.size())
    {
      return s1.size() - pos1;
    }

    if (s1[pos1] == s2[pos2])
    {
      int sum1 = BruteResultAux(s1, pos1 + 1, s2, pos2 + 1);
      return sum1;
    }
    else
    {
      int sum2 = BruteResultAux(s1, pos1 + 1, s2, pos2 + 1) + 1;
      int sum3 = BruteResultAux(s1, pos1 + 1, s2, pos2) + 1;
      int sum4 = BruteResultAux(s1, pos1, s2, pos2 + 1) + 1;
      return std::min({sum2, sum3, sum4});
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
