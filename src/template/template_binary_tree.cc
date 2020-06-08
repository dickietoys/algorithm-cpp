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
#include <list>

using namespace std;

struct TreeNode
{
  TreeNode *left;
  TreeNode *right;
  int val;
  TreeNode(int value)
      : left(nullptr)
      , right(nullptr)
      , val(value)
  {}
};

class BinaryTree
{
 private:
  TreeNode *root_;
  void PreOrderRecurAux(TreeNode *node)
  {
    if (!node)
    {
      return;
    }
    cout << node->val << ", ";
    PreOrderRecurAux(node->left);
    PreOrderRecurAux(node->right);
  }

  void InOrderRecurAux(TreeNode *node)
  {
    if (!node)
    {
      return;
    }

    InOrderRecurAux(node->left);
    cout << node->val << ", ";
    InOrderRecurAux(node->right);
  }

  void PostOrderRecurAux(TreeNode *node)
  {
    if (!node)
    {
      return;
    }

    PostOrderRecurAux(node->left);
    PostOrderRecurAux(node->right);
    cout << node->val << ", ";
  }
 public:
  BinaryTree()
      : root_(nullptr)
  {}

  TreeNode *GetRoot()
  {
    return root_;
  }

  void InsertLevel(int val)
  {
    TreeNode *new_node = new TreeNode(val);
    if (!root_)
    {
      root_ = new_node;
      return;
    }

    queue<TreeNode *> q;
    q.push(root_);
    TreeNode *node = nullptr;
    while (!q.empty())
    {
      int q_size = q.size();
      for (int i = 0; i < q_size; ++i)
      {
        node = q.front();
        q.pop();
        if (!node->left)
        {
          node->left = new_node;
          return;
        }

        q.push(node->left);
        if (!node->right)
        {
          node->right = new_node;
          return;
        }
        q.push(node->right);
      }
    }

    node = root_;
    while (node->left)
    {
      node = node->left;
    }
    node->left = new_node;
  }

  void PreOrderRecur()
  {
    PreOrderRecurAux(root_);
    cout << endl;
  }

  void InOrderRecur()
  {
    InOrderRecurAux(root_);
    cout << endl;
  }

  void PostOrderRecur()
  {
    PostOrderRecurAux(root_);
    cout << endl;
  }

  vector<int> PreOrderInter()
  {
    vector<int> result;
    if (!root_)
    {
      return result;
    }

    stack<TreeNode *> st;
    st.push(root_);
    result.push_back(root_->val);
    TreeNode *last_pop = root_;
    while (!st.empty())
    {
      TreeNode *node = st.top();
      if (node->left && node->left != last_pop && node->right != last_pop)
      {
        st.push(node->left);
        result.push_back(node->left->val);
      }
      else if (node->right && node->right != last_pop)
      {
        st.push(node->right);
        result.push_back(node->right->val);
      }
      else
      {
        st.pop();
        last_pop = node;
      }
    }

    return result;
  }

  vector<int> InOrderInter()
  {
    vector<int> result;
    if (!root_)
    {
      return result;
    }
    stack<TreeNode *> st;
    st.push(root_);
    TreeNode *last_pop = root_;
    while (!st.empty())
    {
      TreeNode *node = st.top();
      if (node->left && node->left != last_pop && node->right != last_pop)
      {
        st.push(node->left);
      }
      else if (node->right && node->right != last_pop)
      {
        st.push(node->right);
        result.push_back(node->val);
      }
      else
      {
        last_pop = node;
        st.pop();
        if (!node->right)
        {
          result.push_back(node->val);
        }
      }
    }

    return result;
  }

  vector<int> PostOrderInter()
  {
    vector<int> result;
    if (!root_)
    {
      return result;
    }

    stack<TreeNode *> st;
    st.push(root_);
    TreeNode *last_pop = root_;
    while (!st.empty())
    {
      TreeNode *node = st.top();
      if (node->left && node->left != last_pop && node->right != last_pop)
      {
        st.push(node->left);
      }
      else if (node->right && node->right != last_pop)
      {
        st.push(node->right);
      }
      else
      {
        last_pop = node;
        st.pop();
        result.push_back(node->val);
      }
    }

    return result;
  }

  void LevelOrder()
  {}
};

class Solution {
 public:

  void RunTest()
  {
    BinaryTree bt;
    bt.InsertLevel(10);
    bt.GetRoot()->left = new TreeNode(11);
    bt.GetRoot()->left->left = new TreeNode(7);
    bt.GetRoot()->right = new TreeNode(9);
    bt.GetRoot()->right->left = new TreeNode(15);
    bt.GetRoot()->right->right = new TreeNode(8);

    bt.InOrderRecur();
    bt.InsertLevel(12);
    bt.InOrderRecur();
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", " << endl;
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
