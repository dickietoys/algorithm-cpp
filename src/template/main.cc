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

 public:
  BinaryTree()
      : root_(nullptr)
  {}

  TreeNode *root()
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

  void GenBySortedArray(vector<int> arr)
  {
    root_ = GenBySortedArrayAux(arr, 0, arr.size() - 1);
  }

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

  void GenBySortedList(list<int> l)
  {
    list<int>::const_iterator it = l.begin();
    root_ = GenBySortedListAux(l, it, l.size());
  }

  TreeNode *GenByLevelOrderAux(TreeNode *node, int data)
  {
    if (!node)
    {
      return new TreeNode(data);
    }

    if (node->val >= data)
    {
      node->left = GenByLevelOrderAux(node->left, data);
    }
    else
    {
      node->right = GenByLevelOrderAux(node->right, data);
    }

    return node;
  }

  void GenByLevelOrder(vector<int> arr)
  {
    for (int data : arr)
    {
      root_ = GenByLevelOrderAux(root_, data);
    }
  }

  struct NodeDetail
  {
    int val;
    int min;
    int max;
    NodeDetail(int value,
               int limit_min = std::numeric_limits<int>::min(),
               int limit_max = std::numeric_limits<int>::max())
        : val(value)
        , min(limit_min)
        , max(limit_max)
    {}
  };

  bool CheckValidByLevelOrder(vector<int> arr)
  {
    int pos = 0;
    queue<NodeDetail *> q;
    q.push(new NodeDetail(arr[pos++]));
    while (pos < arr.size() && !q.empty())
    {
      NodeDetail *detail_node = q.front();
      q.pop();
      if (pos < arr.size() && arr[pos] < detail_node->val && arr[pos] > detail_node->min)
      {
        q.push(new NodeDetail(arr[pos++], detail_node->min, detail_node->val));

      }

      if (pos < arr.size() && arr[pos] > detail_node->val && arr[pos] < detail_node->max)
      {
        q.push(new NodeDetail(arr[pos++], detail_node->val, detail_node->max));
      }
    }

    if (pos != arr.size())
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  bool CheckValidByPreOrder(vector<int> arr)
  {
    stack<int> st;
    int root = std::numeric_limits<int>::min();
    st.push(root);
    for (int i = 0; i < arr.size(); ++i)
    {
      if (arr[i] < root)
      {
        return false;
      }

      while (!st.empty() && arr[i] > st.top())
      {
        root = st.top();
        st.pop();
      }

      st.push(arr[i]);
    }

    return true;
  }

  bool CheckValidByInOrder(vector<int> arr)
  {
    //check sorted
    for (int i = 1; i < arr.size(); ++i)
    {
      if (arr[i] < arr[i-1])
      {
        return false;
      }
    }

    return true;
  }

  TreeNode * FindKthSmallestAux(TreeNode *node, int &kth)
  {
    if (!node)
    {
      return nullptr;
    }

    TreeNode *result = nullptr;
    result = FindKthSmallestAux(node->left, kth);
    if (result)
    {
      return result;
    }

    --kth;
    if (kth == 0)
    {
      return node;
    }

    return FindKthSmallestAux(node->right, kth);
  }

  int FindKthSmallest(int kth)
  {
    TreeNode *target = FindKthSmallestAux(root_, kth);

    if (target)
    {
      return target->val;
    }
    else
    {
      return -1;
    }
  }

  TreeNode *FindKthLargestAux(TreeNode *node, int &kth)
  {
    if (!node)
    {
      return node;
    }

    TreeNode *result = FindKthLargestAux(node->right, kth);
    if (result)
    {
      return result;
    }

    --kth;
    if (kth == 0)
    {
      return node;
    }

    return FindKthLargestAux(node->left, kth);
  }

  int FindKthLargest(int kth)
  {
    TreeNode *target = FindKthLargestAux(root_, kth);

    if (target)
    {
      return target->val;
    }
    else
    {
      return -1;
    }
  }
};

class Solution {
 public:
  void RunTest()
  {
    // TestIsValid();
    // TestGenByPreOrder();
    // TestGenBySortedArray();
    // TestGenBySortedArray();
    // TestGenBySortedList();
    // TestGenByLevelOrder();
    // TestCheckValidByLevelOrder();
    // TestCheckValidByPreOrder();
    TestFindKth();
  }

  void TestFindKth()
  {
    BinaryTree bt;

    bt.InsertLevel(10);
    bt.root()->left = new TreeNode(5);
    bt.root()->left->left = new TreeNode(2);
    bt.root()->left->right = new TreeNode(6);
    bt.root()->right = new TreeNode(15);
    bt.root()->right->left = new TreeNode(12);
    bt.root()->right->right = new TreeNode(18);

    cout << bt.FindKthSmallest(3) << endl;
    cout << bt.FindKthLargest(3) << endl;
  }

  void TestCheckValidByPreOrder()
  {
    BinaryTree bt;
    // true
    cout << bt.CheckValidByPreOrder({2, 4, 3}) << endl;
    // false
    cout << bt.CheckValidByPreOrder({2, 4, 1}) << endl;
    // true
    cout << bt.CheckValidByPreOrder({40, 30, 35, 80, 100}) << endl;
    // false
    cout << bt.CheckValidByPreOrder({40, 30, 35, 20, 80, 100}) << endl;
  }

  void TestCheckValidByLevelOrder()
  {
    BinaryTree bt;
    // true
    cout << bt.CheckValidByLevelOrder({7, 4, 12, 3, 6, 8, 1, 5, 10}) << endl;
    // false
    cout << bt.CheckValidByLevelOrder({11, 6, 13, 5, 12, 10}) << endl;
  }

  void TestGenByLevelOrder()
  {
    BinaryTree bt;
    bt.GenByLevelOrder({7, 4, 12, 3, 6, 8, 1, 5, 10});
    bt.InOrderRecur();
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
    bt.root()->left = new TreeNode(2);
    bt.root()->right = new TreeNode(5);
    bt.root()->left->left = new TreeNode(1);
    bt.root()->left->right = new TreeNode(4);
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
    bt.root()->left = new TreeNode(11);
    bt.root()->left->left = new TreeNode(7);
    bt.root()->right = new TreeNode(9);
    bt.root()->right->left = new TreeNode(15);
    bt.root()->right->right = new TreeNode(8);

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
