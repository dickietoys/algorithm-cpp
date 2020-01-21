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
    vector<vector<string>> result;

  }

  Node* cloneGraph(Node* node) {
    unordered_map<int, Node *> us;
    Node *new_node = DFS(node, us);

    return new_node;
  }

  Node *DFS(Node* node, unordered_map<int, Node *> &us)
  {
    if (!node)
    {
      return nullptr;
    }
    if (us.count(node->val) == 0)
    {
      Node *new_node = new Node(node->val);
      us[node->val] = new_node;
      for (int i = 0; i < node->neighbors.size(); ++i)
      {
        new_node->neighbors.push_back(DFS(node->neighbors[i], us));
      }

      return new_node;
    }
    else
    {
      return us[node->val];
    }
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
