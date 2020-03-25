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

class MinStack {
 private:
  vector<int> data_;
  int min_;
 public:
  /** initialize your data structure here. */
  MinStack()
      : min_(std::numeric_limits<int>::max())
  {}

  void push(int x) {
    if (x <= min_)
    {
      data_.push_back(min_);
      min_ = x;
    }
    data_.push_back(x);
  }

  void pop() {
    int data = data_.back();
    data_.pop_back();
    if (data == min_)
    {
      min_ = data_.back();
      data_.pop_back();
    }
  }

  int top() {
    return data_.back();
  }

  int getMin() {
    return min_;
  }
};

class Solution {
 public:
  void RunTest()
  {
  }

  int findMin(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size == 0)
    {
      return 0;
    }

    int left = 0;
    int right = nums_size - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[right])
      {
        left = mid + 1;
      }
      else if (nums[mid] < nums[right])
      {
        right = mid;
      }
      else
      {
        --right;
      }
    }

    return nums[left];
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
