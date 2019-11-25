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
    vector<int> arr = {1, 2, 3};
    int n = 4;
    int result = BruteResult(arr, n);
    cout << "BruteResult: " << result << endl;
    result = DpResult(arr, n);
    cout << "DpResult: " << result << endl;
    cout << "=========================MinPartition=========================" << endl;
  }

  int DpResult(vector<int> &arr, int n)
  {
    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(n + 1, 0));
    for (size_t i = 0; i <= arr.size(); ++i)
    {
      bookmark[i][0] = 1;
    }

    for (size_t i = 1; i <= arr.size(); ++i)
    {
      for (size_t j = 1; j <= n; ++j)
      {
        bookmark[i][j] = bookmark[i-1][j];
        if (arr[i-1] <= j)
        {
          bookmark[i][j] += bookmark[i][j-arr[i-1]];
        }
      }
    }

    return bookmark[arr.size()][n];
  }

  int BruteResult(vector<int> &arr, int n)
  {
    return BruteResultAux(arr, arr.size() - 1, n);
  }

  int BruteResultAux(vector<int> &arr, int pos, int n)
  {
    if (n == 0)
    {
      return 1;
    }

    if (n < 0 || pos < 0)
    {
      return 0;
    }

    // return BruteResultAux(arr, n - arr[0]) + BruteResultAux(arr, n - arr[1]) + BruteResultAux(arr, n - arr[2]);
    return BruteResultAux(arr, pos, n - arr[pos]) + BruteResultAux(arr, pos - 1, n);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
