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

using namespace std;

class MyStack {
 public:

  queue<int> que;
  /** Initialize your data structure here. */
  MyStack() {

  }

  /** Push element x onto stack. */
  void push(int x) {
    que.push(x);
    for (int i = 0; i < que.size() - 1; ++i)
    {
      que.push(que.front());
      que.pop();
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int value = que.front();
    que.pop();
    return value;
  }

  /** Get the top element. */
  int top() {
    return que.front();
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return que.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
