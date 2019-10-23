#ifndef LONGEST_INCREASING_SUB_SEQUENCE_H_
#define LONGEST_INCREASING_SUB_SEQUENCE_H_

#include <vector>
#include <iostream>

#include <testsuit/TestBase.h>

using namespace std;

class LongestIncreasingSubSequence : public TestBase
{
 public:
  void DoTest()
  {
    vector<int> data = {10,9,2,5,3,7,101,18};
    int longest = BruteFind(data);
    cout << "BruteFind longest: " << longest << endl;
    longest = DpFind(data);
    cout << "DpFind longest: " << longest << endl;
  }

  int BruteFind(const vector<int> &data)
  {
    vector<vector<int>> bookmark(data.size() + 1, vector<int>(data.size(), -1));
    return BruteFindAux(data, -1, 0, bookmark);
  }

  int DpFind(const vector<int> &data)
  {
    vector<int> bookmark(data.size(), 0);

  }

 private:
  int BruteFindAux(const vector<int> &data, int prevPos, int currentPos, vector<vector<int>> &bookmark)
  {
    if (currentPos == data.size())
    {
      return 0;
    }

    if (bookmark[prevPos+1][currentPos] != -1)
    {
      return bookmark[prevPos+1][currentPos];
    }

    int taken = 0;
    if (prevPos == -1 || data[currentPos] > data[prevPos])
    {
      taken = BruteFindAux(data, currentPos, currentPos + 1, bookmark) + 1;
    }

    int nottaken = BruteFindAux(data, prevPos, currentPos + 1, bookmark);

    int max = std::max(taken, nottaken);
    bookmark[prevPos+1][currentPos] = max;

    return max;
  }

  int DpFindAux(const vector<int> &data)
  {
    if (data.size() == 0)
    {
      return 0;
    }

    for (int i = 1; i < data.size(); ++i)
    {
      for (int j = 0; j < i; ++j)
      {

      }
    }
  }
};



#endif
