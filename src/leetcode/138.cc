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
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  void RunTest()
  {

  }

  Node* copyRandomList(Node* head) {
    Node dummy(0);
    Node *last_new_node = &dummy;
    Node *new_node = nullptr;
    Node *old_node = head;
    unordered_map<Node *, Node *> bookmark;
    bookmark[nullptr] = nullptr;
    while (old_node)
    {
      new_node = new Node(old_node->val);
      last_new_node->next = new_node;
      bookmark[old_node] = new_node;
      old_node = old_node->next;
      last_new_node = new_node;
    }

    old_node = head;
    new_node = dummy.next;
    while(old_node)
    {
      new_node->random = bookmark[old_node->random];
      old_node = old_node->next;
      new_node = new_node->next;
    }

    return dummy.next;
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
