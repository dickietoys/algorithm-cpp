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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<vector<int>> input;
    vector<vector<int>> result;

    input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    result = merge(input);
    Show(result);

    input = {{1, 4}, {4, 5}};
    result = merge(input);
    Show(result);
  }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    std::sort(intervals.begin(),
              intervals.end(),
              [](vector<int> &v1,
                 vector<int> &v2)
              {
                return v1[0] < v2[0];
              });
    if (intervals.size() == 0)
    {
      return result;
    }
    Aux(intervals, 0, 1, result);
    return result;
  }

  void Aux(vector<vector<int>>& intervals, int pos1, int pos2, vector<vector<int>> &result)
  {
    int size = intervals.size();
    if (pos2 >= size)
    {
      result.push_back(intervals[pos1]);
      return;
    }

    if (intervals[pos1][1] >= intervals[pos2][0])
    {
      intervals[pos1][1] = std::max(intervals[pos1][1], intervals[pos2][1]);
      ++pos2;
    }
    else
    {
      result.push_back(intervals[pos1]);
      pos1 = pos2;
      ++pos2;
    }

    Aux(intervals, pos1, pos2, result);
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
