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

class Codec {
 public:

  // Encodes a tree to a single string.
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string result = "";
    deque<TreeNode *> dq;
    dq.push_back(root);
    while (!dq.empty())
    {
      int dq_size = dq.size();
      for (int i = 0; i < dq_size; ++i)
      {
        TreeNode *node = dq.front();
        dq.pop_front();
        if (!node)
        {
          result += "null,";
        }
        else
        {
          result += std::to_string(node->val) + ",";
          dq.push_back(node->left);
          dq.push_back(node->right);
        }
      }
    }

    if (result != "")
    {
      result = result.substr(0, result.size() - 1);
    }

    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    queue<TreeNode *> q;
    string s;
    while (getline(ss, s, ','))
    {
      if (s == "null")
      {
        q.push(nullptr);
      }
      else
      {
        q.push(new TreeNode(std::stoi(s)));
      }
    }

    if (q.size() <= 0)
    {
      return nullptr;
    }

    TreeNode *root = q.front();
    q.pop();
    int depth = 1;
    queue<TreeNode *> last_depth;
    last_depth.push(root);
    while (!q.empty())
    {
      int last_depth_size = last_depth.size();
      for (int i = 0; i < last_depth_size; ++i)
      {
        TreeNode *node = last_depth.front();
        last_depth.pop();
        node->left = q.front();
        q.pop();
        node->right = q.front();
        q.pop();
        if (node->left)
        {
          last_depth.push(node->left);
        }
        if (node->right)
        {
          last_depth.push(node->right);
        }
      }
    }

    return root;
  }
};
