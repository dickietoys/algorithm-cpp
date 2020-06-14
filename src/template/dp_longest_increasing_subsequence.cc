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
    int result = LisRecur({ 10,9,2,5,3,7,101,18 });
    cout << "LisRecur: " << result << endl;

    result = LisDp({ 10, 22, 9, 33, 21, 50, 41, 60 });
    cout << "LisDp: " << result << endl;
  }

  int max_ = 1;

  int LisRecurAux(vector<int> &arr, int size)
  {
    if (size <= 1)
    {
      return 1;
    }

    int max = 1;
    for (int i = 0; i < size - 1; ++i)
    {
      int cur_max = LisRecurAux(arr, i + 1);
      if (arr[i] < arr[size - 1] && cur_max + 1 > max)
      {
        max = cur_max + 1;
      }
    }

    max_ = std::max(max_, max);

    return max;
  }

  int LisRecur(vector<int> arr)
  {
    if (arr.empty())
    {
      return 0;
    }

    LisRecurAux(arr, arr.size());

    return max_;
  }

  int LisDp(vector<int> arr)
  {
    if (arr.empty())
    {
      return 0;
    }

    int arr_size = arr.size();
    vector<int> dp(arr_size, 0);
    dp[0] = 1;
    int max = 1;
    for (int i = 1; i < arr_size; ++i)
    {
      int cur_max = 0;
      for (int j = 0; j < i; ++j)
      {
        if (arr[j] < arr[i])
        {
          cur_max = std::max(cur_max, dp[j]);
        }
      }
      dp[i] = cur_max + 1;
      max = std::max(max, dp[i]);
    }

    return max;
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
