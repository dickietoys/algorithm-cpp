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
  {}

  void subsetsBacktrack(vector<vector<int>> &result,
                        vector<int> &item,
                        vector<int> &nums,
                        int start)
  {
    result.push_back(item);
    for (int i = start; i < nums.size(); ++i)
    {
      item.push_back(nums[i]);
      subsetsBacktrack(result, item, nums, i + 1);
      item.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums)
  {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> item;
    subsetsBacktrack(result, item, nums, 0);
    return result;
  }

  ////////////////////////////////////////////////////////////////

  void subsetsWithDupBacktrack(vector<vector<int>> &result,
                               vector<int> &item,
                               vector<int> &nums,
                               int start)
  {
    result.push_back(item);
    for (int i = start; i < nums.size(); ++i)
    {
      if (i > start && nums[i] == nums[i - 1])
      {
        continue;
      }
      item.push_back(nums[i]);
      subsetsWithDupBacktrack(result, item, nums, i + 1);
      item.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> item;
    subsetsWithDupBacktrack(result, item, nums, 0);

    return result;
  }

  //////////////////////////////////////////////////////////////////

  void permuteBacktrack(vector<vector<int>> &result, vector<int> &item, vector<int> &nums)
  {
    if (item.size() == nums.size())
    {
      result.push_back(item);
      return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
      if (std::find(item.begin(), item.end(), nums[i]) != item.end())
      {
        continue;
      }
      item.push_back(nums[i]);
      permuteBacktrack(result, item, nums);
      item.pop_back();
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> result;
    vector<int> item;
    permuteBacktrack(result, item, nums);

    return result;
  }


  //////////////////////////////////////////////
  void permuteUniqueBacktrack(vector<vector<int>> &result,
                              vector<int> &item,
                              vector<int> &nums,
                              vector<bool> &used)
  {
    if (item.size() == nums.size())
    {
      result.push_back(item);
      return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
      if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i-1]))
      {
        continue;
      }
      used[i] = true;
      item.push_back(nums[i]);
      permuteUniqueBacktrack(result, item, nums, used);
      used[i] = false;
      item.pop_back();
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> item;
    vector<bool> used(nums.size(), false);
    permuteUniqueBacktrack(result, item, nums, used);

    return result;
  }

  ///////////////////////////////////////////////////////////

  void combinationSumBacktrack(vector<vector<int>> &result,
                               vector<int> &item,
                               vector<int> &nums,
                               int remain,
                               int start)
  {
    if (remain < 0)
    {
      return;
    }
    else if (remain == 0)
    {
      result.push_back(item);
    }
    else
    {
      for (int i = start; i < nums.size(); ++i)
      {
        item.push_back(nums[i]);
        combinationSumBacktrack(result, item, nums, remain - nums[i], i); // not i + 1 because we can reuse same elements
        item.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int> &nums, int target)
  {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> item;
    combinationSumBacktrack(result, item, nums, target, 0);

    return result;
  }


  ///////////////////////////////////////////////////////////////
  void combinationSum2Backtrack(vector<vector<int>> &result,
                               vector<int> &item,
                               vector<int> &nums,
                               int remain,
                               int start)
  {
    if (remain < 0)
    {
      return;
    }
    else if (remain == 0)
    {
      result.push_back(item);
    }
    else
    {
      for (int i = start; i < nums.size(); ++i)
      {
        if (i > start && nums[i] == nums[i - 1])
        {
          continue;
        }
        item.push_back(nums[i]);
        combinationSum2Backtrack(result, item, nums, remain - nums[i], i + 1);
        item.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &nums, int target)
  {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> item;
    combinationSum2Backtrack(result, item, nums, target, 0);

    return result;
  }

  //////////////////////////////////////////////////////////

  bool isPalindrome(string &s, int low, int high)
  {
    while (low < high)
    {
      if (s[low++] != s[high--])
      {
        return false;
      }
    }

    return true;
  }

  void partitionBacktrack(vector<vector<string>> &result,
                          vector<string> &item,
                          string &s,
                          int start)
  {
    if (start == s.size())
    {
      result.push_back(item);
    }
    else
    {
      for (int i = start; i < s.size(); ++i)
      {
        if (isPalindrome(s, start, i))
        {
          item.push_back(s.substr(start, i - start + 1));
          partitionBacktrack(result, item, s, i + 1);
          item.pop_back();
        }
      }
    }
  }

  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> result;
    vector<string> item;
    partitionBacktrack(result, item, s, 0);

    return result;
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
