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
    int n = 1;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    removeNthFromEnd(head, n);
  }


  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (n)
    {
      fast = fast->next;
      --n;
    }

    ListNode *prevNode = head;
    while (fast)
    {
      prevNode = slow;
      slow = slow->next;
      fast = fast->next;
    }

    if (slow == head)
    {
      head = head->next;
    }
    else
    {
      prevNode->next = slow->next;
    }

    delete slow;

    return head;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
