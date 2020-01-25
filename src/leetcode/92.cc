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
#include <bitset>

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
    ListNode *input;
    ListNode *result;
    input = new ListNode(1);
    input->next = new ListNode(2);
    input->next->next = new ListNode(3);
    input->next->next->next = new ListNode(4);
    input->next->next->next->next = new ListNode(5);

    cout << "(2, 4) :";
    Show(input);
    result = reverseBetween(input, 2, 4);
    Show(result);

    input = new ListNode(5);
    cout << "(1, 1) :";
    Show(input);
    result = reverseBetween(input, 1, 1);
    Show(result);

    input = new ListNode(3);
    input->next = new ListNode(5);
    cout << "(1, 2) :";
    Show(input);
    result = reverseBetween(input, 1, 2);
    Show(result);
  }


  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    int left = std::min(m, n);
    int right = std::max(m, n);

    int count = right;
    ListNode *leftPrev = &dummy;
    ListNode *leftNode = &dummy;
    ListNode *rightNode = &dummy;

    while (count)
    {
      if (left)
      {
        --left;
        leftPrev = leftNode;
        leftNode = leftNode->next;
      }

      if (right)
      {
        --right;
        rightNode = rightNode->next;
      }

      --count;
    }

    ListNode *rightNext = rightNode->next;
    ListNode *prev = rightNext;
    ListNode *cur = leftNode;
    ListNode *next;
    while (cur != rightNext)
    {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    leftPrev->next = prev;

    return dummy.next;
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

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
