#ifndef FROG_JUMP_H
#define FROG_JUMP_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <map>
#include <vector>

using namespace std;

class FrogJump : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FrogJump====================" << endl;
    vector<int> arr = {0,1,3,5,6,8,12,17};
    bool can_jump = BruteResult(arr);
    cout << "BruteResult: " << can_jump << endl;

    arr = {0,1,2,3,4,8,9,11};
    can_jump = BruteResult(arr);
    cout << "BruteResult: " << can_jump << endl;
    cout << "=================FrogJump====================" << endl;
  }

  bool BruteResult(vector<int> &arr)
  {
    return BruteResultAux(arr, 0, 1);
  }

  bool BruteResultAux(vector<int> &arr, int pos, int jumpUnit)
  {
    int length = arr.size();
    if (jumpUnit <= 0)
    {
      return false;
    }

    if (pos == length - 1)
    {
      return true;
    }

    for (int i = pos + 1; i < length; ++i)
    {
      if (arr[pos] + jumpUnit == arr[i])
      {
        return BruteResultAux(arr, i,jumpUnit) ||
            BruteResultAux(arr, i, jumpUnit - 1) ||
            BruteResultAux(arr, i, jumpUnit + 1);
      }
    }

    return false;
  }
};

#endif
