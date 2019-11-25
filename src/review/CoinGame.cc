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
    vector<int> arr = {8, 15, 3, 7};
    int result = BruteResult(arr);
    cout << "BruteResult: " << result << endl;
    result = DpResult(arr);
    cout << "DpResult: " << result << endl;

    arr = {2, 2, 2, 2};
    result = BruteResult(arr);
    cout << "BruteResult: " << result << endl;
    result = DpResult(arr);
    cout << "DpResult: " << result << endl;

    arr = {20, 30, 2, 2, 2, 10};
    result = BruteResult(arr);
    cout << "BruteResult: " << result << endl;
    result = DpResult(arr);
    cout << "DpResult: " << result << endl;

    cout << "=========================MinPartition=========================" << endl;
  }

  int DpResult(vector<int> &arr)
  {
    vector<vector<int>> bookmark(arr.size(), vector<int>(arr.size(), 0));
    for (size_t i = 0; i < arr.size(); ++i)
    {
      bookmark[i][i] = arr[i];
    }

    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
      bookmark[i][i+1] = std::max(arr[i], arr[i+1]);
    }

    for (int i = 2; i < arr.size(); ++i)
    {
      for (int j = 0; j < arr.size() - i; ++j)
      {
        int k = j + i;
        int left = arr[j] + std::min(bookmark[j+1][k-1], bookmark[j+2][k]);
        int right = arr[k] + std::min(bookmark[j+1][k-1], bookmark[j][k-2]);
        bookmark[j][k] = std::max(left, right);
      }
    }

    return bookmark[0][arr.size() - 1];
  }

  int BruteResult(vector<int> &arr)
  {
    return BruteResultAux(arr, 0, arr.size() - 1);
  }

  int BruteResultAux(vector<int> &arr, int leftPos, int rightPos)
  {
    if (leftPos >= rightPos)
    {
      return 0;
    }

    int sum1 = arr[leftPos] + std::min(BruteResultAux(arr, leftPos + 1, rightPos - 1),
                                       BruteResultAux(arr, leftPos + 2, rightPos));

    int sum2 = arr[rightPos] + std::min(BruteResultAux(arr, leftPos, rightPos - 2),
                                        BruteResultAux(arr, leftPos + 1, rightPos - 1));

    return std::max(sum1, sum2);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
