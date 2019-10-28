#ifndef LONGEST_COMMON_SUB_SEQUENCE_H_
#define LONGEST_COMMON_SUB_SEQUENCE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

class EditDistance : public TestBase
{
 public:
  void DoTest()
  {
    string s1 = "horse";
    string s2 = "ros";
    printf("BruteEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), BruteEdit(s1, s2));
    printf("BruteEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), DpEdit(s1, s2));

    s1 = "intention";
    s2 = "execution";
    printf("BruteEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), BruteEdit(s1, s2));
    printf("BruteEdit(%s, %s): %d\n", s1.c_str(), s2.c_str(), DpEdit(s1, s2));
  }

  int BruteEdit(const string &s1, const string &s2)
  {
    return 0;
  }

  int DpEdit(const string &s1, const string &s2)
  {
    return 0;
  }

 private:
};


#endif
