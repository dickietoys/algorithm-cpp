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
    vector<double> result = twoSum(1);
    Show(result);
  }

  /*
    把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

    你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

    示例 1:
    输入: 1
    输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]

    示例 2:
    输入: 2
    输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
  */

  void Aux(int ori_n, int n, int sum, vector<int> &buffer)
  {
    if (n == 0)
    {
      ++buffer[sum - ori_n];
      return;
    }

    for (int i = 1; i <= 6; ++i)
    {
      Aux(ori_n, n-1, sum + i, buffer);
    }
  }

  vector<double> twoSum(int n) {
    /*
      6 * n - n + 1
    */
    // vector<int> buffer(5 * n + 1, 0);
    // Aux(n, n, 0, buffer);

    // vector<double> result;
    // for (int i = 0; i < buffer.size(); ++i)
    // {
    //   result.push_back(buffer[i] / std::pow(6.0, n));
    // }

    // return result;
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
