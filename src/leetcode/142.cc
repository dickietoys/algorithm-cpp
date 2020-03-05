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
    int x = 0;
    x = x ^ 0;
    cout << x << endl;
  }

  ListNode *detectCycle(ListNode *head) {
    bool has_cycle = false;
    ListNode *fast = head;
    ListNode *slow = head;
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
        has_cycle = true;
        break;
      }
    }

    if (!has_cycle)
    {
      return nullptr;
    }

    slow = head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }

  bool hasCycle(ListNode *head) {


    return false;
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
