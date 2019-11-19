#ifndef ACTIVITY_SELECTION_H
#define ACTIVITY_SELECTION_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  int startTime;
  int endTime;
} ActivityT;

class ActivitySelection : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================ActivitySelection====================" << endl;
    vector<ActivityT> arr = {
      {10, 20},
      {12, 25},
      {20, 30}
    };
    string result = Select(arr);
    cout << "result: " << result << endl;

    arr = {
      {1, 2},
      {3, 4},
      {0, 6},
      {5, 7},
      {8, 9},
      {5, 9},
    };
    result = Select(arr);
    cout << "result: " << result << endl;
    cout << "=================ActivitySelection====================" << endl;
  }

  string Select(vector<ActivityT> &arr)
  {
    string buffer = "0, ";
    int prevIndex = 0;
    for (size_t i = 1; i < arr.size(); ++i)
    {
      if (arr[i].startTime >= arr[prevIndex].endTime)
      {
        buffer.append(std::to_string(i)).append(", ");
        prevIndex = i;
      }
    }

    return buffer;
  }
};

#endif
