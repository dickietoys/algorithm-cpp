#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================MinPartition=========================" << endl;
    int distance = 4;
    int count = BruteResult(distance);
    cout << "BruteResult: " << count << endl;
    count = DpResult(distance);
    cout << "DpResult: " << count << endl;
    cout << "=========================MinPartition=========================" << endl;
  }

  int DpResult(int distance)
  {
    vector<int> bookmark(distance+1, 0);
    bookmark[0] = 1;
    bookmark[1] = 1;
    bookmark[2] = 2;

    for (int i = 3; i <= distance; ++i)
    {
      bookmark[i] = bookmark[i-1] + bookmark[i-2] + bookmark[i-3];
    }

    return bookmark[distance];
  }

  int BruteResult(int distance)
  {
    return BruteResultAux(distance);
  }

  int BruteResultAux(int distance)
  {
    if (distance == 0)
    {
      return 1;
    }

    if (distance < 0)
    {
      return 0;
    }

    return BruteResultAux(distance - 1) + BruteResultAux(distance - 2) + BruteResultAux(distance - 3);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
