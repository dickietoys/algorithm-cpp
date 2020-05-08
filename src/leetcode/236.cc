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

class Solution {
 public:
  void RunTest()
  {
  }

  bool Aux(TreeNode *node, vector<TreeNode*> &path, int target_value)
  {
    if (!node)
    {
      return false;
    }

    path.push_back(node);
    if (node->val == target_value)
    {
      return true;
    }

    if (Aux(node->left, path, target_value) || Aux(node->right, path, target_value))
    {
      return true;
    }

    path.pop_back();
    return false;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    if (!Aux(root, path1, p->val) || !Aux(root, path2, q->val))
    {
      return nullptr;
    }

    int i = 0;
    for (; i < path1.size() && i < path2.size(); ++i)
    {
      if (path1[i] != path2[i])
      {
        break;
      }
    }

    return path1[i-1];
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
