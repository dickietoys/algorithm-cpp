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
    vector<int> arr = {1, 6, 11, 5};
    int min = BruteResult(arr);
    cout << "BruteResult: " << min << endl;
    min = DpResult(arr);
    cout << "DpResult: " << min << endl;
    cout << "=========================MinPartition=========================" << endl;
  }

  int DpResult(vector<int> &arr)
  {
    int sum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      sum += arr[i];
    }

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

    int diff = 0;
    for (int i = sum / 2; i >= 0; --i)
    {
      if (bookmark[arr.size()][i] == 1)
      {
        diff = sum - i * 2;
        break;
      }
    }

    return diff;
  }

  int BruteResult(vector<int> &arr)
  {
    return BruteResultAux(arr, 0, 0, 0);
  }

  int BruteResultAux(vector<int> &arr, int leftSum, int rightSum, int pos)
  {
    if (pos >= arr.size())
    {
      return std::abs(leftSum - rightSum);
    }

    return std::min(BruteResultAux(arr, leftSum + arr[pos], rightSum, pos + 1),
                    BruteResultAux(arr, leftSum, rightSum + arr[pos], pos + 1));
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
