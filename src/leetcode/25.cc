#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>

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
    int n = 2;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    // head1->next->next = new ListNode(3);
    // head1->next->next->next = new ListNode(4);
    // head1->next->next->next->next = new ListNode(5);
    Show(head1);
    head1 = reverseKGroup(head1, n);
    Show(head1);
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next)
    {
      return head;
    }

    ListNode *cur = head;
    ListNode *next = nullptr;
    int count = 0;
    deque<ListNode *> dq;
    ListNode *newHead = nullptr;
    ListNode *newCurNode = nullptr;
    while (cur)
    {
      next = cur->next;
      cur->next = nullptr;
      dq.push_back(cur);
      cur = next;
      ++count;
      if (count == k)
      {
        count = 0;
        while (!dq.empty())
        {
          if (newCurNode)
          {
            newCurNode->next = dq.back();
            newCurNode = newCurNode->next;
            dq.pop_back();
          }
          else
          {
            newHead = dq.back();
            dq.pop_back();
            newCurNode = newHead;
          }
        }
      }
    }

    ListNode *remainNode = nullptr;
    while (!dq.empty())
    {
      if (remainNode)
      {
        remainNode->next = dq.front();
        remainNode = remainNode->next;
        dq.pop_front();
      }
      else
      {
        remainNode = dq.front();
        dq.pop_front();
        if (!newCurNode)
        {
          newCurNode = remainNode;
          newHead = newCurNode;
        }
        else
        {
          newCurNode->next = remainNode;
        }
      }
    }

    return newHead;
  }

  void Show(ListNode *node)
  {
    while (node)
    {
      cout << node->val << ", ";
      node = node->next;
    }
    cout << endl;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
