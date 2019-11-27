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
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode *head3 = new ListNode(2);
    head2->next = new ListNode(6);

    vector<ListNode *> lists = {head1, head2, head3};
    head1 = mergeKLists(lists);
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

  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    ListNode dummy(0);
    ListNode *curNode = &dummy;
    ListNode **minNode = nullptr;
    int empty_count = 0;
    while (true)
    {
      minNode = nullptr;
      empty_count = 0;
      for (size_t i = 0; i < lists.size(); ++i)
      {
        if (!lists[i])
        {
          ++empty_count;
          continue;
        }

        if (!minNode || (*minNode)->val > lists[i]->val)
        {
          minNode = &(lists[i]);
        }
      }

      if (empty_count == lists.size())
      {
        break;
      }
      curNode->next = *minNode;
      curNode = curNode->next;
      *minNode = (*minNode)->next;
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
