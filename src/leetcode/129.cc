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
    TreeNode input(1);
    input.left = new TreeNode(2);
    input.right = new TreeNode(3);
    int result = sumNumbers(&input);

    cout << result << endl;
  }

  int sumNumbers(TreeNode* root) {
    stack<int> s;
    int sum = 0;
    Aux(root, s, sum);

    return sum;
  }

  void Aux(TreeNode* node, stack<int> &s, int &sum)
  {
    if (!node)
    {
      sum += NumValue(s);
      return;
    }
    s.push(node->val);
    if (node->left)
    {
      Aux(node->left, s, sum);
    }
    if (node->right)
    {
      Aux(node->right, s, sum);
    }
    if (!node->left && !node->right)
    {
      sum += NumValue(s);
    }
    s.pop();
  }

  int NumValue(stack<int> s)
  {
    int num = 0;
    int i = 0;
    while (!s.empty())
    {
      num += s.top() * pow(10, i++);
      s.pop();
    }

    return num;
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
