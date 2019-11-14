#ifndef FIND_PAIR_SUM_CLOSEST_H
#define FIND_PAIR_SUM_CLOSEST_H

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

class FindPairSumClosest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindPairSumClosest====================" << endl;
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    int sum = 54;
    cout << "BruteResult: " << BruteResult(arr, sum) << endl;

    arr =  {1, 3, 4, 7, 10};
    sum = 15;
    cout << "BruteResult: " << BruteResult(arr, sum) << endl;

    cout << "=================FindPairSumClosest====================" << endl;
  }

  string BruteResult(const vector<int> &arr, int sum)
  {
    map<int, string> buffer;
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
      for (size_t j = i + 1; j < arr.size(); ++j)
      {
        buffer.insert({
            std::abs(sum - arr[i] - arr[j]),
                string().append(std::to_string(arr[i]).append(", ").append(std::to_string(arr[j])))
                });
      }
    }

    return buffer.cbegin()->second;
  }
};

#endif
