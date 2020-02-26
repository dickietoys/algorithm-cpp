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
#include <bitset>

using namespace std;

class Solution {
 public:

  void RunTest()
  {
    vector<int> input = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(input);
    cout << "result: " << result << endl;
  }

  int maxProfit(vector<int>& prices)
  {
    if (prices.size() < 2)
    {
      return 0;
    }

    int sum = 0;
    for (int i = 0; i < prices.size() - 1; ++i)
    {
      if (prices[i+1] > prices[i])
      {
        sum += prices[i+1] - prices[i];
      }
    }

    return sum;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
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
