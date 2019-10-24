#ifndef LONGEST_COMMON_SUB_SEQUENCE_H_
#define LONGEST_COMMON_SUB_SEQUENCE_H_

#include <iostream>
#include <string>

#include <testsuit/TestBase.h>

using namespace std;

class LongestCommonSubSequence : public TestBase
{
 public:
  void DoTest()
  {
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
  }

  int BruteFind(const string &s1, const string &s2)
  {}

  int DpFind(const string &s1, const string &s2)
  {}

 private:
};


#endif
