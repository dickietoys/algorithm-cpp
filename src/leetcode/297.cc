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
    string data = "1,2,3,null,null,4,5";
    deserialize(data);
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root)
    {
      return "";
    }

    string result = "";
    deque<TreeNode *> dq;
    dq.push_back(root);
    while (!dq.empty())
    {
      int dq_size = dq.size();
      while (dq_size > 0)
      {
        TreeNode *node = dq.front();
        dq.pop_front();
        if (node)
        {
          dq.push_back(node->left);
          dq.push_back(node->right);
          result += std::to_string(node->val) + ",";
        }
        else
        {
          result += "null,";
        }
        --dq_size;
      }
    }

    result = result.substr(0, result.size() - 1);

    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "")
    {
      return nullptr;
    }

    std::stringstream ss(data);
    std::string item;
    vector<TreeNode *> items;
    while (std::getline(ss, item, ','))
    {
      if (item == "null")
      {
        items.push_back(nullptr);
      }
      else
      {
        items.push_back(new TreeNode(std::stoi(item)));
      }
    }

    /*
                 1
             2         3
         null null   4   5

      [1,2,3,null,null,4,5]

      [1] [2,3,null] [null, 4, 5]

      [2] [3] [null]
    */

    TreeNode *root = items[0];
    if (!root)
    {
      return root;
    }

    int pos = 1;
    deque<TreeNode*> dq;
    dq.push_back(root);
    while (pos < items.size())
    {
      int dq_size = dq.size();
      while (dq_size > 0)
      {
        TreeNode *node = dq.front();
        dq.pop_front();
        node->left = items[pos++];
        node->right = items[pos++];
        if (node->left)
        {
          dq.push_back(node->left);
        }
        if (node->right)
        {
          dq.push_back(node->right);
        }
        --dq_size;
      }
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
