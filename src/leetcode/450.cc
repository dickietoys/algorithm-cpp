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
#include <functional>

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

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//         left = NULL;
//         right = NULL;
//     }

//     Node(int _val, Node* _left, Node* _right) {
//         val = _val;
//         left = _left;
//         right = _right;
//     }
// };


class Solution {
 public:
  void RunTest()
  {

  }

  /*
                        9
                      /    \
                     3      14
                    / \     / \
                   2   4   12 15
                           / \
                          10 13
   */

  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
    {
      return nullptr;
    }

    if (root->val == key)
    {
      if (!root->right && !root->left)
      {
        return nullptr;
      }
      else if (root->left && !root->right)
      {
        return root->left;
      }
      else if (root->right && !root->left)
      {
        return root->right;
      }
      else
      {
        TreeNode *cur = root->right;
        while (cur->left)
        {
          cur = cur->left;
        }
        root->val = cur->val;
        root->right = deleteNode(root->right, root->val);
      }
    }
    else if (root->val > key)
    {
      root->left = deleteNode(root->left, key);
    }
    else
    {
      root->right = deleteNode(root->right, key);
    }

    return root;
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
