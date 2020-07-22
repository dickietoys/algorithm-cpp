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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    vector<vector<int>> result;
    int target;

    input = {10,1,2,7,6,1,5};
    target = 8;
    result = combinationSum2(input, target);
    show(result);
  }

  void Aux(vector<int>& candidates, int target, int pos, vector<int> &item, vector<vector<int>> &result)
  {
    if (target == 0)
    {
      result.push_back(item);
      return;
    }

    if (target < 0)
    {
      return;
    }

    for (int i = pos; i < candidates.size(); ++i)
    {
      if (i > pos && candidates[i] == candidates[i-1])
      {
        continue;
      }
      item.push_back(candidates[i]);
      Aux(candidates, target - candidates[i], i + 1, item, result);
      item.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> item;
    Aux(candidates, target, 0, item, result);

    return result;
  }

  void show(vector<vector<int>> &result)
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
