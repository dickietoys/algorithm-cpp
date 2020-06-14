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
    int result = WaysToCoverDistanceRecur(3);
    cout << "WaysToCoverDistanceRecur: " << result << endl;
    result = WaysToCoverDistanceRecur(4);
    cout << "WaysToCoverDistanceRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = WaysToCoverDistanceDp(3);
    cout << "WaysToCoverDistanceDp: " << result << endl;
    result = WaysToCoverDistanceDp(4);
    cout << "WaysToCoverDistanceDp: " << result << endl;
  }

  int WaysToCoverDistanceRecur(int n)
  {
  }

  int WaysToCoverDistanceDp(int n)
  {

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
