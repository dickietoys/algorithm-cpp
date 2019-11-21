#ifndef LONGEST_PALINDROMIC_SUB_STRING_H 
#define LONGEST_PALINDROMIC_SUB_STRING_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class LongestPalindromicSubString : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================LongestPalindromicSubString====================" << endl;
    string str = "forgeeksskeegfor";
    int longest = BruteFindLongestLoop(str);
    cout << "BruteFindLongestLoop: " << str << ", longest: " << longest << endl;
    longest = BruteFindRecursive(str);
    cout << "BruteFindRecursive: " << str << ", longest: " << longest << endl;
    longest = DpFindLongest(str);
    cout << "DpFindLongest: " << str << ", longest: " << longest << endl;

    str = "cdabaabacd";
    longest = BruteFindLongestLoop(str);
    cout << "BruteFindLongestLoop: " << str << ", longest: " << longest << endl;
    longest = BruteFindRecursive(str);
    cout << "BruteFindRecursive: " << str << ", longest: " << longest << endl;
    longest = DpFindLongest(str);
    cout << "DpFindLongest: " << str << ", longest: " << longest << endl;
    cout << "=================LongestPalindromicSubString====================" << endl;
  }

  int BruteFindLongestLoop(const string &str)
  {
    return BruteFindLongestLoopAux(str);
  }

  int BruteFindRecursive(const string &str)
  {
    int max = 0;
    BruteFindRecursiveAux(str, 0, str.size() - 1, max);
    return max;
  }

  int DpFindLongest(const string &str)
  {
    return DpFindLongestAux(str);
  }

 private:
  int DpFindLongestAux(const string &str)
  {
    int max = 0;
    int length = str.size();
    vector<vector<int>> bookmark(length, vector<int>(length, 0));
    for (int i = 0; i < length; ++i)
    {
      bookmark[i][i] = 1;
      max = 0;
    }

    for (int i = 0; i < length - 1; ++i)
    {
      if (str[i] == str[i+1])
      {
        bookmark[i][i+1] = 1;
        max = 2;
      }
    }

    for (int i = 3; i <= length; ++i)
    {
      for (int j = 0; j < length - i + 1; ++j)
      {
        int k = j + i - 1;
        if (str[j] == str[k] && bookmark[j+1][k-1])
        {
          bookmark[j][k] = 1;
          max = std::max(k - j + 1, max);
        }
      }
    }

    return max;
  }

  bool BruteFindRecursiveAux(const string &str, int leftPos, int rightPos, int &max)
  {
    if (leftPos == rightPos)
    {
      return true;
    }

    if (str[leftPos] == str[rightPos])
    {
      bool ok = true;
      if (rightPos - 1 >= leftPos + 1)
      {
        ok = BruteFindRecursiveAux(str, leftPos + 1, rightPos - 1, max);
      }

      if (ok)
      {
        max = std::max(max, rightPos - leftPos + 1);
      }

      return ok;
    }
    else
    {
      if (leftPos + 1 <= rightPos)
      {
        bool ok = BruteFindRecursiveAux(str, leftPos + 1, rightPos, max);
        if (ok)
        {
          max = std::max(max, rightPos - leftPos);
        }

        ok = BruteFindRecursiveAux(str, leftPos, rightPos - 1, max);
        if (ok)
        {
          max = std::max(max, rightPos - leftPos);
        }
      }

      return false;
    }
  }

  int BruteFindLongestLoopAux(const string &str)
  {
    int length = str.size();
    int longest = 0;
    for (int i = 0; i < length; ++i)
    {
      for (int j = i + 1; j < length; ++j)
      {
        bool isPalindromic = true;
        int left = i;
        int right = j;
        while (left < right)
        {
          if (str[left] == str[right])
          {
            ++left;
            --right;
          }
          else
          {
            isPalindromic = false;
            break;
          }
        }

        if (isPalindromic)
        {
          longest = std::max(longest, j - i + 1);
        }
      }
    }

    return longest;
  }

  void Show(const vector<int> &arr)
  {
    for (size_t i = 0; i < arr.size(); ++i)
    {
      cout << arr[i] << ", ";
    }

    cout << endl;
  }
};

#endif
