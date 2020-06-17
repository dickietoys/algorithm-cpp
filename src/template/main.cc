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
    // 22
    int result = RodCuttingRecur({0, 1, 5, 8, 9, 10, 17, 17, 20});
    cout << "RodCuttingRecur: " << result << endl;
    // 24
    result = RodCuttingRecur({0, 3, 5, 8, 9, 10, 17, 17, 20});
    cout << "RodCuttingRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = RodCuttingDp({0, 1, 5, 8, 9, 10, 17, 17, 20});
    cout << "RodCuttingDp: " << result << endl;
    result = RodCuttingDp({0, 3, 5, 8, 9, 10, 17, 17, 20});
    cout << "RodCuttingDp: " << result << endl;
  }

  int RodCuttingRecurAux(vector<int> &prices, int n)
  {
    if (n <= 1)
    {
      return prices[n];
    }

    int max = 0;
    for (int i = 1; i <= n; ++i)
    {
      int current = prices[i] + RodCuttingRecurAux(prices, n - i);
      max = std::max(current, max);
    }

    return max;
  }

  int RodCuttingRecur(vector<int> prices)
  {
    return RodCuttingRecurAux(prices, prices.size() - 1);
  }

  int RodCuttingDp(vector<int> prices)
  {
    return 0;
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
