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

  void preorder_traversal_iteratively(TreeNode* root)
  {
    if (root == 0)
      return;
    stack<TreeNode*> s;
    s.push(root);
    cout << root->val << ' '; // visit root
    TreeNode* last_pop = root;
    while (!s.empty())
    {
      TreeNode* top = s.top();
      if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
      {
        s.push(top->left);
        cout << top->left->val << ' '; // visit top->left
      }
      else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
      {
        s.push(top->right);
        cout << top->right->val << ' '; // visit top->right
      }
      else // pop
      {
        s.pop();
        last_pop = top;
      }
    }
  }

  void inorder_traversal_iteratively(TreeNode* root)
  {
    if (root == 0)
      return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* last_pop = root;
    while (!s.empty())
    {
      TreeNode* top = s.top();
      if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
      {
        s.push(top->left);
      }
      else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
      {
        s.push(top->right);
        cout << top->val << ' '; // visit top
      }
      else // pop
      {
        s.pop();
        last_pop = top;
        if (top->right == 0)
          cout << top->val << ' '; // visit top
      }
    }
  }

  void postorder_traversal_iteratively(TreeNode* root)
  {
    if (root == 0)
      return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* last_pop = root;
    while (!s.empty())
    {
      TreeNode* top = s.top();
      if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
      {
        s.push(top->left);
      }
      else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
      {
        s.push(top->right);
      }
      else // pop
      {
        s.pop();
        last_pop = top;
        cout << top->val << ' '; // visit top
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
