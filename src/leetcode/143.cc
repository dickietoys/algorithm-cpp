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
    if (!head)
    {
      return;
    }
    // find middle
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      fast = fast->next;
      if (fast->next)
      {
        fast = fast->next;
        slow = slow->next;
      }
    }

    // reverse
    ListNode *prev_node = nullptr;
    ListNode *cur_node = slow->next;
    ListNode *next_node = nullptr;
    while (cur_node)
    {
      next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }

    slow->next = nullptr;
    ListNode *first_list_node = head;
    ListNode *second_list_node = prev_node;
    while (first_list_node && second_list_node)
    {
      ListNode *first_list_node_next = first_list_node->next;
      first_list_node->next = second_list_node;
      ListNode *second_list_node_next = second_list_node->next;
      second_list_node->next = first_list_node_next;
      first_list_node =  first_list_node_next;
      second_list_node = second_list_node_next;
    }
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
