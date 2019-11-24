#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================LCS=========================" << endl;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int longest = BruteResult(s1, s2);
    cout << "BruteResult: "  << longest << endl;
    longest = DpResult(s1, s2);
    cout << "DpResult: "  << longest << endl;
    cout << "=========================LCS=========================" << endl;
  }

  int DpResult(string &s1, string &s2)
  {
    vector<vector<int>> bookmark(s1.size(), vector<int>(s2.size(), 0));
    if (s1[0] == s2[0])
    {
      bookmark[0][0] = 1;
    }

    for (size_t i = 1; i < s1.size(); ++i)
    {
      if (s1[i] == s2[0])
      {
        bookmark[i][0] = 1;
      }
      else
      {
        bookmark[i][0] = bookmark[i-1][0];
      }
    }

    for (size_t i = 1; i < s2.size(); ++i)
    {
      if (s1[0] == s2[i])
      {
        bookmark[0][i] = 1;
      }
      else
      {
        bookmark[0][i] = bookmark[0][i-1];
      }
    }

    for (size_t i = 1; i < s1.size(); ++i)
    {
      for (size_t j = 1; j < s2.size(); ++j)
      {
        if (s1[i] == s2[j])
        {
          bookmark[i][j] = bookmark[i-1][j-1] + 1;
        }
        else
        {
          bookmark[i][j] = std::max(bookmark[i-1][j], bookmark[i][j-1]);
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
    if (pos1 >= s1.size() || pos2 >= s2.size())
    {
      return 0;
    }

    if (s1[pos1] == s2[pos2])
    {
      return BruteResultAux(s1, pos1 + 1, s2, pos2 + 1) + 1;
    }
    else
    {
      return std::max(BruteResultAux(s1, pos1 + 1, s2, pos2), BruteResultAux(s1, pos1, s2, pos2 + 1));
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
