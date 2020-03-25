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

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
  }

  vector<int> twoSum(vector<int>& numbers, int target) {
    int num_size = numbers.size();
    if (num_size <= 1)
    {
      return vector<int>();
    }

    int left = 0;
    int right = num_size - 1;
    int sum = 0;
    while (left < right)
    {
      sum = numbers[left] + numbers[right];
      if (sum == target)
      {
        return {left + 1, right + 1};
      }
      else if (sum > target)
      {
        --right;
      }
      else
      {
        ++left;
      }
    }
    return vector<int>();
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
