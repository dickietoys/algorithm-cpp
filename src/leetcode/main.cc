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

class Solution {
 public:
  void RunTest()
  {
    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    Show(node);
    reorderList(node);
    Show(node);
  }

  void Show(ListNode* head)
  {
    while (head)
    {
      cout << head->val << ", ";
      head = head->next;
    }

    cout << endl;
  }

  void reorderList(ListNode* head) {
    ListNode *cur_node = head;
    vector<ListNode *> even_index_node;
    stack<ListNode *> odd_index_node;
    int index = 0;
    while (cur_node)
    {
      ++index;
      if (index % 2 == 0)
      {
        odd_index_node.push(cur_node);
      }
      else
      {
        even_index_node.push_back(cur_node);
      }
      cur_node = cur_node->next;
    }
    int even_index_node_size = even_index_node.size();
    ListNode dummy(0);
    cur_node = &dummy;
    for (int i = 0; i < even_index_node_size; ++i)
    {
      cur_node->next = even_index_node[i];
      cur_node = cur_node->next;
      if (odd_index_node.size() != 0)
      {
        cur_node->next = odd_index_node.top();
        cur_node = cur_node->next;
        odd_index_node.pop();
      }
    }
    cur_node->next = nullptr;
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
