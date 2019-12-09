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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    int input;
    int result;

    result = mySqrt(4);
    cout << "result: " << result << endl;
    result = mySqrt(8);
    cout << "result: " << result << endl;
  }

  int mySqrt(int x) {
    if (x == 0)
    {
      return 0;
    }
    int left = 0;
    int right = std::numeric_limits<int>::max();
    while (left <= right)
    {
      int middle = (left + right) / 2;
      if (middle > x / middle)
      {
        right = middle - 1;
      }
      else
      {
        if (middle + 1 > x / (middle + 1))
        {
          return middle;
        }

        left = middle + 1;
      }
    }

    return 0;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
