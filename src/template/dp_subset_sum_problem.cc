#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>
#include <queue>
#include <list>

using namespace std;


class Solution {
 public:
  void RunTest()
  {
    cout << "==================bruteforce======================" << endl;
    bool result = SubsetSumProblemRecur({3, 34, 4, 12, 5, 2}, 9);
    cout << "SubsetSumProblemRecur: " << result << endl;
    result = SubsetSumProblemRecur({3, 34, 4, 12, 5, 2}, 30);
    cout << "SubsetSumProblemRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = SubsetSumProblemDp({3, 34, 4, 12, 5, 2}, 9);
    cout << "SubsetSumProblemDp: " << result << endl;
    result = SubsetSumProblemDp({3, 34, 4, 12, 5, 2}, 30);
    cout << "SubsetSumProblemDp: " << result << endl;
  }

  bool SubsetSumProblemRecurAux(vector<int> arr, int pos, int sum)
  {
    if (sum == 0)
    {
      return true;
    }

    if (pos >= arr.size())
    {
      return false;
    }

    return SubsetSumProblemRecurAux(arr, pos + 1, sum - arr[pos]) ||
        SubsetSumProblemRecurAux(arr, pos + 1, sum);
  }

  bool SubsetSumProblemRecur(vector<int> arr, int sum)
  {
    return SubsetSumProblemRecurAux(arr, 0, sum);
  }

  bool SubsetSumProblemDp(vector<int> arr, int sum)
  {
    if (sum == 0)
    {
      return true;
    }

    int arr_size = arr.size();
    if (arr_size == 0)
    {
      return false;
    }

    vector<vector<bool>> dp(arr_size, vector<bool>(sum + 1, false));
    for (int i = 0; i < arr_size; ++i)
    {
      dp[i][arr[i]] = true;
    }

    for (int i = 1; i < arr_size; ++i)
    {
      for (int j = 0; j <= sum; ++j)
      {
        if (dp[i-1][j])
        {
          dp[i][j] = true;
          if (j + arr[i] <= sum)
          {
            dp[i][j+arr[i]] = true;
          }
        }
      }
    }

    return dp[arr_size - 1][sum];
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
