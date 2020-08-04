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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    buildTree(inorder, postorder);
  }

  TreeNode* Aux(vector<int>& inorder,
                int in_start,
                int in_stop,
                vector<int>& postorder,
                int post_start,
                int post_stop)
  {
    if (in_start > in_stop || post_start > post_stop)
    {
      return nullptr;
    }

    TreeNode *root = new TreeNode(postorder[post_stop]);
    int found_pos = FindPos(inorder, root->val);
    int left_size = found_pos - in_start;
    root->left = Aux(inorder,
                     in_start,
                     found_pos - 1,
                     postorder,
                     post_start,
                     post_start + left_size - 1);
    root->right = Aux(inorder,
                      found_pos + 1,
                      in_stop,
                      postorder,
                      post_start + left_size,
                      post_stop - 1);
    return root;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return Aux(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
  }

  int FindPos(vector<int> &arr, int val)
  {
    int i = 0;
    for (; i < arr.size(); ++i)
    {
      if (arr[i] == val)
      {
        return i;
      }
    }

    return i;
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
