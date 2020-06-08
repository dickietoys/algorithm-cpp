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

  TreeNode *GenBySortedListAux(list<int> &l, list<int>::const_iterator &cur_it, int n)
  {
    if (n <= 0)
    {
      return nullptr;
    }

    TreeNode *left = GenBySortedListAux(l, cur_it, n / 2);
    TreeNode *node =  new TreeNode(*cur_it);
    node->left = left;
    ++cur_it;
    node->right = GenBySortedListAux(l, cur_it, n - n / 2 - 1);

    return node;
  }

  TreeNode * GenBySortedArrayAux(vector<int> &arr, int low, int high)
  {
    if (low > high)
    {
      return nullptr;
    }

    if (low == high)
    {
      return new TreeNode(arr[low]);
    }
    int mid = low + (high-low) / 2;
    TreeNode *new_node = new TreeNode(arr[mid]);
    new_node->left = GenBySortedArrayAux(arr, low, mid - 1);
    new_node->right = GenBySortedArrayAux(arr, mid + 1, high);

    return new_node;
  }

  bool IsBSTAux(TreeNode *node, TreeNode *min, TreeNode *max)
  {
    if (!node)
    {
      return true;
    }

    if (min && node->val <= min->val)
    {
      return false;
    }

    if (max && node->val >= max->val)
    {
      return false;
    }

    return IsBSTAux(node->left, min, node) &&
        IsBSTAux(node->right, node, max);
  }

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

  vector<vector<int>> LevelOrder()
  {
    vector<vector<int>> result;
    if (!root_)
    {
      return result;
    }
    queue<TreeNode *> q;
    q.push(root_);
    while (!q.empty())
    {
      int q_size = q.size();
      vector<int> item;
      for (int i = 0; i < q_size; ++i)
      {
        TreeNode *node = q.front();
        q.pop();
        item.push_back(node->val);
        if (node->left)
        {
          q.push(node->left);
        }
        if (node->right)
        {
          q.push(node->right);
        }
      }
      result.push_back(item);
    }

    return result;
  }

  bool IsBST()
  {
    return IsBSTAux(root_, nullptr, nullptr);
  }

  TreeNode * GenByPreOrderAux(vector<int> &arr, int &cur_pos, TreeNode *min, TreeNode *max)
  {
    if (cur_pos >= arr.size())
    {
      return nullptr;
    }

    TreeNode *node = nullptr;
    if ((!min or arr[cur_pos] > min->val) && (!max or arr[cur_pos] < max->val))
    {
      node = new TreeNode(arr[cur_pos]);
      ++cur_pos;
      node->left = GenByPreOrderAux(arr, cur_pos, min, node);
      node->right = GenByPreOrderAux(arr, cur_pos, node, max);
    }

    return node;
  }

  void GenByPreOrder(vector<int> arr)
  {
    int cur_pos = 0;
    root_ = GenByPreOrderAux(arr, cur_pos, nullptr, nullptr);
  }

  void GenBySortedArray(vector<int> arr)
  {
    root_ = GenBySortedArrayAux(arr, 0, arr.size() - 1);
  }

  void GenBySortedList(list<int> l)
  {
    list<int>::const_iterator it = l.begin();
    root_ = GenBySortedListAux(l, it, l.size());
  }
};

class Solution {
 public:
  void RunTest()
  {
    // TestIsValid();
    // TestGenByPreOrder();
    // TestGenBySortedArray();
    TestGenBySortedArray();
    TestGenBySortedList();
  }

  void TestGenBySortedList()
  {
    BinaryTree bt;
    bt.GenBySortedList({1,2,3,4,5,6});
    bt.InOrderRecur();
    Show(bt.LevelOrder());
  }

  void TestGenBySortedArray()
  {
    BinaryTree bt;
    bt.GenBySortedArray({1,2,3,4,5,6});
    bt.InOrderRecur();
    Show(bt.LevelOrder());
  }

  void TestGenByPreOrder()
  {
    BinaryTree bt;
    bt.GenByPreOrder({10, 5, 1, 7, 40, 50});
    bt.InOrderRecur();
  }

  void TestIsValid()
  {
    BinaryTree bt;
    bt.InsertLevel(3);
    bt.GetRoot()->left = new TreeNode(2);
    bt.GetRoot()->right = new TreeNode(5);
    bt.GetRoot()->left->left = new TreeNode(1);
    bt.GetRoot()->left->right = new TreeNode(4);
    if (bt.IsBST())
    {
      cout << "Is BST" << endl;
    }
    else
    {
      cout << "Not BST" << endl;
    }
  }

  void TestTraversal()
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
