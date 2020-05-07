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

class MyQueue {
 public:
  stack<int> input;
  stack<int> output;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    input.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int value = peek();
    output.pop();
    return value;
  }

  /** Get the front element. */
  int peek() {
    if (output.empty())
    {
      while (!input.empty())
      {
        output.push(input.top());
        input.pop();
      }
    }

    return output.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return input.empty() && output.empty();
  }
};
