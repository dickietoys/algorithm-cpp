#ifndef MINIMUM_PARTITION_H_
#define MINIMUM_PARTITION_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

class MinimumPartition : public TestBase
{
 public:
  void DoTest()
  {
    vector<int> arr = {1, 6, 11, 5};
  }

  int BrutePartition(const vector<int> &arr)
  {
    return BrutePartitionAux(arr);
  }

 private:
  int BrutePartitionAux(const vector<int> &arr)
  {

  }
};

#endif
