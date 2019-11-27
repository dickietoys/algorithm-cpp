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
    int n = 2;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    Show(head1);
    head1 = reverseKGroup(head1, n);
    Show(head1);
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head)
    {
      return head;
    }

    ListNode dummy(0);
    dummy.next = head;

    ListNode *prev = head;
    ListNode *cur = prev->next;
    ListNode *next = nullptr;
    int count = 1;

    while (cur && count == k)
    {
      next = cur->next;
      cur->next = prev;
      prev = prev;
      cur = next;
      ++count;
    }

    head->next = cur;
    Show(prev);
    return prev;
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
