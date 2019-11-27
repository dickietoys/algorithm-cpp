#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

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
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    Show(head1);
    head1 = swapPairs(head1);
    Show(head1);
  }

  ListNode* swapPairs(ListNode* head) {
    if (!head)
    {
      return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *cur = head;
    ListNode *next = cur->next;

    while (next)
    {
      prev->next = next;
      cur->next = next->next;
      next->next = cur;
      prev = cur;
      cur = cur->next;
      if (!cur)
      {
        break;
      }
      next = cur->next;
    }

    return dummy.next;
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
