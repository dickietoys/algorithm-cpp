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

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
 public:
  void RunTest()
  {
    int package_size = 1000;
    vector<int> goods_weight = {3,68,24,80,76,9,24,2,46,75,56,41,95,46,23,34,64,76,6,48,25,73,87,67,58,7,93,66,55,75,38,27,53,6,100,36,26,17,53,88,21,9,34,90,32,47,4,6,57,50,30,25,41,24,12,74,92,17,32,96,35,76,52,93,64,55,1,70,26,35,2,97,82,22,41,37,63,28,90,13,18,55,28,58,59,74,71,32,71,66,4,5,48,52,70,62,28,36,39,48};
    vector<int> goods_value = {38,16,29,47,22,25,17,49,15,15,75,11,56,99,51,92,59,37,13,98,61,50,32,17,44,79,41,53,45,29,62,64,2,23,31,45,57,68,57,26,51,26,86,83,94,20,98,24,91,89,1,63,21,46,74,56,64,72,58,8,74,24,27,35,94,49,65,21,16,25,1,45,63,4,37,25,39,68,49,11,31,95,5,79,20,21,52,50,8,19,67,21,24,89,28,88,38,96,64,84};

    int result = backPackII(package_size, goods_weight, goods_value);
    cout << result << endl;
  }

  int Aux(int package_size,
          vector<int> &goods_weight,
          vector<int> &goods_value,
          int goods_pos,
          int cur_size,
          int cur_value,
          vector<vector<int>> &dp)
  {
    if (goods_pos >= goods_weight.size())
    {
      return 0;
    }

    if (dp[goods_pos][cur_size] != -1)
    {
      return dp[goods_pos][cur_size];
    }

    int value1 = 0;
    int value2 = 0;
    if (cur_size + goods_weight[goods_pos] <= package_size)
    {
      value1 = goods_value[goods_pos] + Aux(package_size,
                                            goods_weight,
                                            goods_value,
                                            goods_pos + 1,
                                            cur_size + goods_weight[goods_pos],
                                            cur_value,
                                            dp);
    }
    value2 = Aux(package_size,
                 goods_weight,
                 goods_value,
                 goods_pos + 1,
                 cur_size,
                 cur_value,
                 dp);

    dp[goods_pos][cur_size] = std::max(value1, value2);

    return dp[goods_pos][cur_size];
  }

  int backPackII(int package_size, vector<int> &goods_weight, vector<int> &goods_value) {
    vector<vector<int>> dp(goods_weight.size(), vector<int>(package_size + 1, -1));
    return Aux(package_size,
               goods_weight,
               goods_value,
               0,
               0,
               0,
               dp);
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
