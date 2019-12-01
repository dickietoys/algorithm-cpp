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

    input = {2, 3, 5};
    target = 8;
    result = combinationSum(input, target);
    show(result);
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> item;
    std::sort(candidates.begin(), candidates.end(), greater<int>());
    Aux(candidates, target, candidates.size() - 1, item, result);
    return result;
  }

  void Aux(vector<int>& candidates, int target, int pos, vector<int> item, vector<vector<int>> &result)
  {
    if (target == 0)
    {
      result.push_back(item);
      return;
    }

    for (int i = pos; i >= 0 && target >= candidates[i]; --i)
    {
      item.push_back(candidates[i]);
      Aux(candidates, target - candidates[i], i, item, result);
      item.pop_back();
    }
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
