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
    int n = 10;
    int result = BruteResult(n);
    cout << "bruteResult: "<< result << endl;
    result = DpResult(n);
    cout << "DpResult: "<< result << endl;
    cout << "=========================MinPartition=========================" << endl;
  }
  int DpResult(int n)
  {
    vector<int> bookmark(n + 1, 0);
    bookmark[0] = 1;
    bookmark[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
      int curMax = 0;
      for (int j = 0; j < i; ++j)
      {
        curMax = std::max(curMax, bookmark[j] * (i - j));
      }
      bookmark[i] = curMax;
    }

    return bookmark[n];
  }

  int BruteResult(int n)
  {
    return BruteResultAux(n, 1);
  }


  int BruteResultAux(int n, int curSum)
  {
    if (n <= 0)
    {
      return curSum;
    }

    int max = 0;
    for (int i = 1; i <= n; ++i)
    {
      max = std::max(max, BruteResultAux(n - i, curSum * i));
    }

    return max;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
