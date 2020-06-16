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
    // 15
    int result = OptimalStrategyForAGameRecur({5, 3, 7, 10});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;
    // 22
    result = OptimalStrategyForAGameRecur({8, 15, 3, 7});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;
    // 4
    result = OptimalStrategyForAGameRecur({2, 2, 2, 2});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;
    // 42
    result = OptimalStrategyForAGameRecur({20, 30, 2, 2, 2, 10});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = OptimalStrategyForAGameDp({5, 3, 7, 10});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
    result = OptimalStrategyForAGameDp({8, 15, 3, 7});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
    result = OptimalStrategyForAGameDp({2, 2, 2, 2});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
    result = OptimalStrategyForAGameDp({20, 30, 2, 2, 2, 10});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
  }

  int OptimalStrategyForAGameRecur(vector<int> arr)
  {

  }

  int OptimalStrategyForAGameDp(vector<int> arr)
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
