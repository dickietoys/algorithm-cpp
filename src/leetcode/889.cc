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
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    constructFromPrePost(preorder, postorder);
  }

  /*
    [1]  [2,4,5] [3,6,7]
    [4,5,2] [6,7,3] [1]
   */

  TreeNode* Aux(vector<int>& pre,
                int pre_start,
                int pre_stop,
                vector<int>& post,
                int post_start,
                int post_stop)
  {
    if (pre_start > pre_stop || post_start > post_stop)
    {
      return nullptr;
    }


    TreeNode *root = new TreeNode(pre[pre_start]);
    if (pre_start == pre_stop)
    {
      return root;
    }

    int found_pos = FindPos(post, pre[pre_start+1]);
    int size = found_pos - post_start + 1;

    root->left = Aux(pre,
                     pre_start + 1,
                     pre_start + size,
                     post,
                     post_start,
                     found_pos);
    root->right = Aux(pre,
                      pre_start + size + 1,
                      pre_stop,
                      post,
                      post_start + size,
                      post_stop - 1);

    return root;
  }

  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return Aux(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
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
