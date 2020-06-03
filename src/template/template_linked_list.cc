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
#include <queue>
#include <list>

using namespace std;

struct LinkedListNode
{
  int data;
  struct LinkedListNode *next;
  LinkedListNode()
      : data(0)
      , next(nullptr)
  {}

  LinkedListNode(int value)
      : data(value)
      , next(nullptr)
  {}
};

class LinkedList
{
 private:
  LinkedListNode *head_;
  LinkedListNode *tail_;
 public:
  LinkedList()
      :head_(new LinkedListNode())
      ,tail_(head_)
  {}

  void Insert(int value)
  {
    LinkedListNode *node = new LinkedListNode(value);
    tail_->next = node;
    tail_ = node;
  }

  void ShowList()
  {
    LinkedListNode *node = head_->next;
    while (node)
    {
      cout << node->data << ", ";
      node = node->next;
    }

    cout << endl;
  }
};


class Solution {
 public:
  void RunTest()
  {
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", " << endl;
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
