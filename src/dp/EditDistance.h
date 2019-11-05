#ifndef EDIT_DISTANCE_H_
#define EDIT_DISTANCE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

/*
  两个字符串，最少编辑几次才能相同
*/
class EditDistance : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================EditDistance====================" << endl;
    string s1 = "horse";
    string s2 = "ros";
    printf("BruteEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), BruteEdit(s1, s2));
    printf("DpEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), DpEdit(s1, s2));

    s1 = "intention";
    s2 = "execution";
    printf("BruteEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), BruteEdit(s1, s2));
    printf("DpEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), DpEdit(s1, s2));

    s1 = "ABCDE";
    s2 = "B";
    printf("BruteEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), BruteEdit(s1, s2));
    printf("DpEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), DpEdit(s1, s2));
    cout << "=================EditDistance====================" << endl;
  }

  int BruteEdit(const string &s1, const string &s2)
  {
    return BruteEditAux(s1, s1.size(), s2, s2.size());
  }

  int DpEdit(const string &s1, const string &s2)
  {
    return DpEditAux(s1, s2);
  }

 private:
  int BruteEditAux(const string &s1, int s1Pos, const string &s2, int s2Pos)
  {
    if (s1Pos == 0)
    {
      return s2Pos;
    }

    if (s2Pos == 0)
    {
      return s1Pos;
    }

    if (s1[s1Pos - 1] == s2[s2Pos - 1])
    {
      return BruteEditAux(s1, s1Pos - 1, s2, s2Pos - 1);
    }
    else
    {
      int size1 = BruteEditAux(s1, s1Pos, s2, s2Pos - 1) + 1;
      int size2 = BruteEditAux(s1, s1Pos - 1, s2, s2Pos) + 1;
      int size3 = BruteEditAux(s1, s1Pos - 1, s2, s2Pos - 1) + 1;
      return std::min({size1, size2, size3});
    }
  }

  int DpEditAux(const string &s1, const string &s2)
  {
    vector<vector<int>> bookmark(s1.size(), vector<int>(s2.size(), 0));
    if (s1[0] == s2[0])
    {
      bookmark[0][0] = 0;
    }
    else
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
        bookmark[0][i] = bookmark[0][i - 1] + 1;
      }
    }

    for (size_t i = 1; i < s1.size(); ++i)
    {
      if (s1[i] == s2[0])
      {
        bookmark[i][0] = i;
      }
      else
      {
        bookmark[i][0] = bookmark[i - 1][0] + 1;
      }
    }

    for (size_t i = 1; i < s1.size(); ++i)
    {
      for (size_t j = 1; j < s2.size(); ++j)
      {
        if (s1[i] == s2[j])
        {
          bookmark[i][j] = bookmark[i - 1][j - 1];
        }
        else
        {
          int min1 = bookmark[i - 1][j] + 1;
          int min2 = bookmark[i - 1][j - 1] + 1;
          int min3 = bookmark[i][j - 1] + 1;
          bookmark[i][j] = std::min({min1, min2, min3});
        }
      }
    }

    return bookmark[s1.size() - 1][s2.size() - 1];
  }
};

#endif
