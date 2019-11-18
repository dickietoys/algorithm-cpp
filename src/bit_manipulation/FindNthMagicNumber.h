#ifndef FIND_NTH_MAGIC_NUMBER_H
#define FIND_NTH_MAGIC_NUMBER_H

#include <iostream>
#include <testsuit/TestBase.h>

using namespace std;

class FindNthMagicNumber : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindNthMagicNumber====================" << endl;
    cout << "Find(1): " << Find(1) << endl;
    cout << "Find(2): " << Find(2) << endl;
    cout << "Find(3): " << Find(3) << endl;
    cout << "Find(4): " << Find(4) << endl;
    cout << "Find(5): " << Find(5) << endl;
    cout << "=================FindNthMagicNumber====================" << endl;
  }

  int Find(int n)
  {
    int power = 1;
    int answer = 0;
    while (n)
    {
      power = power * 5;
      if (n & 1)
      {
        answer += power;
      }

      n >>= 1;
    }

    return answer;
  }
};

#endif
