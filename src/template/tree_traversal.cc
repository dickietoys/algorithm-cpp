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
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(7);
    cout << *s.begin() << endl;
    s.erase(s.begin());
    cout << *s.begin() << endl;
    s.erase(s.begin());
    cout << *s.begin() << endl;
    s.erase(s.begin());
    cout << "s.size(): " << s.size() << endl;
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

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *cur_node = root;
    while (cur_node || !s.empty())
    {
      if (cur_node)
      {
        s.push(cur_node);
        cur_node = cur_node->left;
        continue;
      }

      if (!s.empty())
      {
        cur_node = s.top();
        s.pop();
        result.push_back(cur_node->val);
        cur_node = cur_node->right;
        continue;
      }
    }

    return result;
  }

  vector<int> postorderTraversal(TreeNode* root) {
    TreeNode *cur_node = root;
    vector<int> result;
    stack<TreeNode *> s;
    while (cur_node)
    {
      s.push(cur_node);
      cur_node = cur_node->left;
      if (cur_node)
      {
        continue;
      }

      if (!s.empty())
      {
        cur_node = s.top();
      }
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

  return 0;
}
