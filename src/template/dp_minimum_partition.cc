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
    int result = MinimumPartitionRecur({1, 6, 11, 5});
    cout << "MinimumPartitionRecur: " << result << endl;
    result = MinimumPartitionRecur({3, 1, 4, 2, 2, 1});
    cout << "MinimumPartitionRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = MinimumPartitionDp({1, 6, 11, 5});
    cout << "MinimumPartitionDp: " << result << endl;
    result = MinimumPartitionDp({3, 1, 4, 2, 2, 1});
    cout << "MinimumPartitionDp: " << result << endl;
  }

  int min_;
  void MinimumPartitionRecurAux(vector<int> arr, int pos, int cur_sum, int sum)
  {
    if (pos >= arr.size())
    {
      min_ = std::min(min_, std::abs(sum - 2 *cur_sum));
      return;
    }

    MinimumPartitionRecurAux(arr, pos + 1, cur_sum + arr[pos], sum);
    MinimumPartitionRecurAux(arr, pos + 1, cur_sum, sum);
  }

  int MinimumPartitionRecur(vector<int> arr)
  {
    if (arr.empty())
    {
      return 0;
    }

    min_ = std::numeric_limits<int>::max();
    int arr_size = arr.size();
    int sum = 0;
    for (int data : arr)
    {
      sum += data;
    }

    MinimumPartitionRecurAux(arr, 0, 0, sum);

    return min_;
  }

  int MinimumPartitionDp(vector<int> arr)
  {
    if (arr.empty())
    {
      return 0;
    }

    int arr_size = arr.size();
    int sum = 0;
    for (int data : arr)
    {
      sum += data;
    }

    vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, false));
    for (int i = 0; i < arr.size(); ++i)
    {
      dp[i][arr[i]] = true;
    }

    for (int i = 1; i < arr.size(); ++i)
    {
      for (int j = 1; j <= sum; ++j)
      {
        if (dp[i-1][j])
        {
          dp[i][j] = true;
        }
        if (dp[i][j])
        {
          dp[i][j+arr[i]] = true;
        }
      }
    }

    for (int i = sum / 2; i >= 0; --i)
    {
      if (dp[arr.size() - 1][i])
      {
        return sum - 2 * i;
      }
    }

    return std::numeric_limits<int>::max();
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
