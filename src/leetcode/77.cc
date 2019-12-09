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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<vector<int>> input;
    vector<vector<int>> result;

    result = combine(4, 2);
    Show(result);
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> buffer;
    Aux(n, k, 1, 0, buffer, result);
    return result;
  }

  void Aux(int n, int k, int pos, int count, vector<int> &buffer, vector<vector<int>> &result)
  {
    if (count == k)
    {
      result.push_back(buffer);
      return;
    }

    if (pos > n)
    {
      return;
    }

    for (int i = pos; i <= n; ++i)
    {
      buffer.push_back(i);
      Aux(n, k, i+1, count + 1, buffer, result);
      buffer.pop_back();
    }
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
