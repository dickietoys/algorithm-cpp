#ifndef FIND_LONGEST_SUB_STRING_H
#define FIND_LONGEST_SUB_STRING_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <set>

using namespace std;

// 最长子串，没有重复字符
class FindLongestSubString : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindLongestSubString====================" << endl;
    string str = "abcabcbb";
    int length = FindLongest(str);
    cout << "length: " << length << endl;

    str = "bbbbb";
    length = FindLongest(str);
    cout << "length: " << length << endl;

    str = "pwwkew";
    length = FindLongest(str);
    cout << "length: " << length << endl;
    cout << "=================FindLongestSubString====================" << endl;
  }

  int FindLongest(const string &str)
  {
    set<char> repeatChecker;
    int i = 0;
    int j = 0;
    int maxLength = 0;
    int length = str.size();
    while (j < length)
    {
      if (repeatChecker.find(str[j]) == repeatChecker.end())
      {
        repeatChecker.insert(str[j++]);
        maxLength = std::max(maxLength, j - i);
      }
      else
      {
        repeatChecker.erase(str[i++]);
      }
    }
    return maxLength;
  }
};

#endif
