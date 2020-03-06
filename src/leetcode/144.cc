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
  }

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *cur_node = root;
    while (cur_node)
    {
      result.push_back(cur_node->val);
      if (cur_node->right)
      {
        s.push(cur_node->right);
      }

      if (!cur_node->left && !s.empty())
      {
        cur_node = s.top();
        s.pop();
      }
      else
      {
        cur_node = cur_node->left;
      }
    }

    return result;
  }

  vector<int> Recusive(TreeNode* root)
  {
    vector<int> result;
    Aux(root, result);

    return result;
  }

  void Aux(TreeNode *node, vector<int> &result)
  {
    if (!node)
    {
      return;
    }
    result.push_back(node->val);
    Aux(node->left, result);
    Aux(node->right, result);
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
