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

static int a = 0;

class Solution {
 public:
  void RunTest()
  {
  }

  TreeNode* Aux(vector<int>& preorder, int start_pos, int stop_pos)
  {
    if (start_pos > stop_pos || start_pos > preorder.size())
    {
      return nullptr;
    }

    TreeNode *node = new TreeNode(preorder[start_pos]);
    int left_end_pos = start_pos + 1;
    for (; left_end_pos < preorder.size(); ++left_end_pos)
    {
      if (preorder[left_end_pos] > node->val)
      {
        break;
      }
    }

    node->left = Aux(preorder, start_pos + 1, left_end_pos - 1);
    node->right = Aux(preorder, left_end_pos, stop_pos);

    return node;
  }

  TreeNode* bstFromPreorder(vector<int>& preorder) {
    // 8,5,1,7,10,12
    return Aux(preorder, 0, preorder.size() - 1);
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
