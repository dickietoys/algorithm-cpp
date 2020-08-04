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
  }

  TreeNode* Aux(vector<int>& pre,
                int pre_start,
                int pre_stop,
                vector<int>& in,
                int in_start,
                int in_stop)
  {
    if (pre_start > pre_stop)
    {
      return nullptr;
    }

    TreeNode *root = new TreeNode(pre[pre_start]);
    int pos = in_start;
    for (; pos <= in_stop; ++pos)
    {
      if (in[pos] == root->val)
      {
        break;
      }
    }
    /*
      [3,9,20,15,7]
      [9,3,15,20,7]

      [3]

      [9] [3] [15, 20, 7]
     */
    int size = pos - in_start;
    root->left = Aux(pre,
                     pre_start + 1,
                     pre_start + size,
                     in,
                     in_start,
                     pos - 1);
    root->right = Aux(pre,
                      pre_start + size + 1,
                      pre_stop,
                      in,
                      pos + 1,
                      in_stop);

    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return Aux(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
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
  delete solution;
  return 0;
}
