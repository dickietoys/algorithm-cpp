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

  int Aux(int m, vector<int> &A, int A_pos)
  {
    if (m == 0 || A_pos >= A.size())
    {
      return 0;
    }

    int max_size = std::numeric_limits<int>::min();
    if (m >= A[A_pos])
    {
      max_size = std::max(max_size, Aux(m - A[A_pos], A, A_pos + 1) + A[A_pos]);
    }

    max_size = std::max(max_size, Aux(m, A, A_pos + 1));

    return max_size;
  }

  int backPack(int m, vector<int> &A) {
    vector<vector<int>> dp(m + 1, vector<int>(A.size(), 0));
    return Aux(m, A, 0);
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
