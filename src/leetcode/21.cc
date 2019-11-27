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
    head1->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    head1 = mergeTwoLists(head1, head2);
    Show(head1);
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

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode *curNode = &dummy;
    while (l1 || l2)
    {
      if (!l1)
      {
        curNode->next = l2;
        curNode = curNode->next;
        l2 = l2->next;
        continue;
      }

      if (!l2)
      {
        curNode->next = l1;
        curNode = curNode->next;
        l1 = l1->next;
        continue;
      }

      if (l1->val < l2->val)
      {
        curNode->next = l1;
        curNode = curNode->next;
        l1 = l1->next;
      }
      else
      {
        curNode->next = l2;
        curNode = curNode->next;
        l2 = l2->next;
      }
    }

    return dummy.next;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
