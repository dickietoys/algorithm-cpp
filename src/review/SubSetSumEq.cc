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
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int result = BruteResult(arr, sum);
    cout << "BruteResult: " << result << endl;
    result = DpResult(arr, sum);
    cout << "DpResult: " << result << endl;
    cout << "=========================MinPartition=========================" << endl;
  }

  int DpResult(vector<int> &arr, int sum)
  {
    // int totalSum = 0;
    // for (size_t i = 0; i < arr.size(); ++i)
    // {
    //   totalSum += arr[i];
    // }

    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(sum + 1, 0));
    for (size_t i = 0; i < arr.size() + 1; ++i)
    {
      bookmark[i][0] = 1;
    }

    for (size_t i = 1; i < arr.size() + 1; ++i)
    {
      for (size_t j = 1; j < sum + 1; ++j)
      {
        bookmark[i][j] = bookmark[i-1][j];
        if (arr[i-1] <= j)
        {
          bookmark[i][j] |= bookmark[i-1][j-arr[i-1]];
        }
      }
    }

    return bookmark[arr.size()][sum];
  }

  int BruteResult(vector<int> &arr, int sum)
  {
    return BruteResultAux(arr, 0, sum, 0);
  }

  int BruteResultAux(vector<int> &arr, int pos, int sum, int nowSum)
  {
    if (sum == nowSum)
    {
      return 1;
    }

    if (pos >= arr.size())
    {
      return 0;
    }

    return BruteResultAux(arr, pos + 1, sum, nowSum + arr[pos]) || BruteResultAux(arr, pos + 1, sum, nowSum);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
