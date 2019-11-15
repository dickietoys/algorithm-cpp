#ifndef FIND_PAIR_EQ_SUM_H
#define FIND_PAIR_EQ_SUM_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

#include <testsuit/TestBase.h>

using namespace std;

class FindPairEqSum: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindPairEqSum====================" << endl;
    vector<int> arr = {1, 4, 45, 6, 10, -8};
    int sum = 16;
    cout << "BruteResult: " << BruteResult(arr, sum) << endl;
    cout << "HashResult: " << HashResult(arr, sum) << endl;
    cout << "=================FindPairEqSum====================" << endl;
  }

  string BruteResult(const vector<int> &arr, int sum)
  {
    string s = "NONE";
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
      for (size_t j = i + 1; j < arr.size(); ++j)
      {
        if (arr[i] + arr[j] == sum)
        {
          s = string().append(std::to_string(arr[i])).append(", ").append(std::to_string(arr[j]));

          return s;
        }
      }
    }

    return s;
  }

  string HashResult(const vector<int> &arr, int sum)
  {
    string s = "NONE";
    map<int, bool> bookmark;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      if (bookmark[sum - arr[i]])
      {
        s = string().append(std::to_string(arr[i])).append(", ").append(std::to_string(sum- arr[i]));
        return s;
      }

      bookmark[arr[i]] = true;
    }

    return s;
  }
};

#endif
