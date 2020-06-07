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
  int data;
  TreeNode(int value)
      : left(nullptr)
      , right(nullptr)
      , data(value)
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
    cout << node->data << ", ";
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
    cout << node->data << ", ";
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
    cout << node->data << ", ";
  }
 public:
  BinaryTree()
      : root_(nullptr)
  {}

  TreeNode *GetRoot()
  {
    return root_;
  }

  void InsertLevel(int value)
  {
    TreeNode *new_node = new TreeNode(value);
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

  void PreOrderInter()
  {

  }

  void InOrderInter()
  {

  }

  void PostOrderInter()
  {

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
