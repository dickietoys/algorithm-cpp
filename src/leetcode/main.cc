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
#include <functional>
#include <list>
#include <exception>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
  }

  /*
    matrix = [
      [ 1,  5,  9],
      [10, 11, 13],
      [12, 13, 15]
    ],

    [1 5 9 19 11 12 13 13 15]
    mid = 8,
    count = 7

    return 13.
  */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix.front().front();
    int right = matrix.back().back();
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      int count = 0;
      for (int i = 0; i < matrix.size(); ++i)
      {
        count += std::upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
      }

      // 比k大的的

      if (count )
    }
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
  delete solution;
  return 0;
}
