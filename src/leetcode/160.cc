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

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
    {
      return nullptr;
    }

    ListNode *new_head = headA;
    ListNode *cur_node = headA;
    bool has_intersection = false;
    while (cur_node->next)
    {
      cur_node = cur_node->next;
    }
    cur_node->next = headB;

    ListNode *fast = new_head;
    ListNode *slow = new_head;
    while (fast)
    {
      fast = fast->next;
      if (fast && fast->next)
      {
        slow = slow->next;
        fast = fast->next;
      }

      if (slow == fast)
      {
        has_intersection = true;
        break;
      }
    }

    if (!has_intersection)
    {
      cur_node->next = nullptr;
      return nullptr;
    }
    slow = new_head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }

    cur_node->next = nullptr;

    return slow;
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
