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
    if (!root)
    {
      return result;
    }
    stack<TreeNode *> s;
    s.push(root);
    result.push_back(root->val);
    TreeNode *last_pop = root;
    while (!s.empty())
    {
      TreeNode *top = s.top();
      if (top->left && top->left != last_pop && top->right != last_pop)
      {
        s.push(top->left);
        result.push_back(top->left->val);
      }
      else if (top->right && top->right != last_pop)
      {
        s.push(top->right);
        result.push_back(top->right->val);
      }
      else
      {
        last_pop = top;
        s.pop();
      }
    }

    return result;
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root)
    {
      return result;
    }
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *last_pop = root;
    while (!s.empty())
    {
      TreeNode *top = s.top();
      if (top->left && top->left != last_pop && top->right != last_pop)
      {
        s.push(top->left);
      }
      else if (top->right && top->right != last_pop)
      {
        s.push(top->right);
        result.push_back(top->val);
      }
      else
      {
        if (!top->right)
        {
          result.push_back(top->val);
        }
        last_pop = top;
        s.pop();
      }
    }

    return result;
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root)
    {
      return result;
    }
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *last_pop = root;
    while (!s.empty())
    {
      TreeNode *top = s.top();
      if (top->left && top->left != last_pop && top->right != last_pop)
      {
        s.push(top->left);
      }
      else if (top->right && top->right != last_pop)
      {
        s.push(top->right);
      }
      else
      {
        result.push_back(top->val);
        last_pop = top;
        s.pop();
      }
    }

    return result;
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
