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

  TreeNode* Aux(vector<int>& inorder,
                int inorder_start,
                int inorder_stop,
                vector<int>& postorder,
                int postorder_start,
                int postorder_stop)
  {
    if (inorder_start > inorder_stop)
    {
      return nullptr;
    }

    TreeNode *root = new TreeNode(postorder[postorder_stop]);
    int pos = inorder_start;
    for (; pos <= inorder_stop; ++pos)
    {
      if (inorder[pos] == root->val)
      {
        break;
      }
    }
    /*
      [9,3,15,20,7]
      [9,15,7,20,3]

      [9] [3] [15, 20, 7]

      [9] [15, 7, 20] [3]
     */
    int size = pos - inorder_start;
    root->left = Aux(inorder,
                     inorder_start,
                     pos - 1,
                     postorder,
                     postorder_start,
                     postorder_start + size - 1);
    root->right = Aux(inorder,
                      pos + 1,
                      inorder_stop,
                      postorder,
                      postorder_start + size,
                      postorder_stop - 1);

    return root;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return Aux(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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
