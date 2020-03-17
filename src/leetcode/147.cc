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
  }

  ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next)
    {
      return head;
    }

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev_node = dummy;
    ListNode *cur_node = head;
    ListNode *next_node = nullptr;
    while (cur_node)
    {
      if (cur_node->next && cur_node->val > cur_node->next->val)
      {
        while (prev_node->next && prev_node->next->val < cur_node->next->val)
        {
          prev_node = prev_node->next;
        }
        ListNode *tmp_node = prev_node->next;
        prev_node->next = cur_node->next;
        cur_node->next = cur_node->next->next;
        prev_node->next->next = tmp_node;
        prev_node = dummy;
      }
      else
      {
        cur_node = cur_node->next;
      }
    }

    return dummy->next;
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
