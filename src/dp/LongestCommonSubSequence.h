#ifndef LONGEST_COMMON_SUB_SEQUENCE_H_
#define LONGEST_COMMON_SUB_SEQUENCE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

/*
  最长公共序列
*/
class LongestCommonSubSequence : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================LongestCommonSubSequence====================" << endl;
    int max = 0;
    string s1 = "abcde";
    string s2 = "ace";
    max = BruteFind(s1, s2);
    printf("BruteFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);
    max = DpFind(s1, s2);
    printf("DpFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);

    s1 = "abc";
    s2 = "abc";
    max = BruteFind(s1, s2);
    printf("BruteFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);
    max = DpFind(s1, s2);
    printf("DpFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);

    s1 = "abc";
    s2 = "def";
    max = BruteFind(s1, s2);
    printf("BruteFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);
    max = DpFind(s1, s2);
    printf("DpFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);
    s1 = "AGGTAB";
    s2 = "GXTXAYB";
    max = BruteFind(s1, s2);
    printf("BruteFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);
    max = DpFind(s1, s2);
    printf("DpFind(%s, %s), max: %d\n", s1.c_str(), s2.c_str(), max);
    cout << "=================LongestCommonSubSequence====================" << endl;
  }

  int BruteFind(const string &s1, const string &s2)
  {
    return BruteFindAux(s1, s1.size(), s2, s2.size());
  }

  int DpFind(const string &s1, const string &s2)
  {
    return DpFindAux(s1, s2);
  }

 private:
  int BruteFindAux(const string &s1, int s1Pos, const string &s2, int s2Pos)
  {
    if (s1Pos == 0 || s2Pos == 0)
    {
      return 0;
    }

    if (s1[s1Pos - 1] == s2[s2Pos - 1])
    {
      return BruteFindAux(s1, s1Pos - 1, s2, s2Pos - 1) + 1;
    }
    else
    {
      return std::max(BruteFindAux(s1, s1Pos - 1, s2, s2Pos), BruteFindAux(s1, s1Pos, s2, s2Pos - 1));
    }
  }

  int DpFindAux(const string &s1, const string &s2)
  {
    vector<vector<int>> bookmark(s1.size(), vector<int>(s2.size(), 0));
    if (s1[0] == s2[0])
    {
      bookmark[0][0] = 1;
    }

    for (size_t i = 1; i < s2.size(); ++i)
    {
      if (s1[0] == s2[i])
      {
        bookmark[0][i] = 1;
      }
      else
      {
        bookmark[0][i] = bookmark[0][i - 1];
      }
    }

    for (size_t i = 1; i < s1.size(); ++i)
    {
      if (s1[i] == s2[0])
      {
        bookmark[i][0] = 1;
      }
      else
      {
        bookmark[i][0] = bookmark[i - 1][0];
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
};


#endif
