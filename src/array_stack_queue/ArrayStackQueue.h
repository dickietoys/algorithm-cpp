#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <vector>
#include <testsuit/TestBase.h>

using namespace std;

class Stack
{
 public:
  Stack(int capacity) :
      data_(vector<int>(capacity, 0)),
      capacity_(capacity)
  {}
  int top()
  {
    return data_[data_.size()-1];
  }

  bool empty()
  {
    return data_.size() == 0 ? true : false;
  }

  void push(int value)
  {
    data_.push_back(value);
  }

  void pop()
  {
    data_.pop_back();
  }

  int size()
  {
    return data_.size();
  }
 private:
  vector<int> data_;
  int capacity_;
};

class Queue
{
 public:
  Queue(int capacity) :
      //need one more place for identify empty or full
      data_(vector<int>(capacity + 1, 0)),
      frontPos_(0),
      endPos_(0),
      size_(0),
      capacity_(capacity + 1)
  {}

  int back()
  {
    return data_[endPos_-1];
  }

  int front()
  {
    return data_[frontPos_];
  }

  bool empty()
  {
    return endPos_ == frontPos_ ? true : false;
  }

  bool push(int value)
  {
    if ((endPos_ + 1) % capacity_ == frontPos_)
    {
      return false;
    }
    else
    {
      data_[endPos_] = value;
      endPos_ = (endPos_ + 1) % capacity_;
      ++size_;
      return true;
    }
  }

  bool pop()
  {
    if (frontPos_ == endPos_)
    {
      return false;
    }
    else
    {
      data_[frontPos_] = 0;
      frontPos_ = (frontPos_ + 1 ) % capacity_;
      --size_;
      return true;
    }
  }

  int size()
  {
    return size_;
  }

 private:
  vector<int> data_;
  int frontPos_;
  int endPos_;
  int size_;
  int capacity_;
};

class ArrayStackQueueTest : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================ArrayStackQueueTest====================" << endl;
    cout << "                 stack                                      " << endl;

    cout << "                 queue                                      " << endl;
    Queue myQueue(6);
    cout << "myQueue.pop()" << myQueue.pop() << endl;
    cout << "myQueue.push(1)" << myQueue.push(1) << endl;
    cout << "myQueue.push(2)" << myQueue.push(2) << endl;
    cout << "myQueue.push(3)" << myQueue.push(3) << endl;
    cout << "myQueue.pop()" << myQueue.pop() << endl;
    cout << "myQueue.push(4)" << myQueue.push(4) << endl;
    cout << "myQueue.push(5)" << myQueue.push(5) << endl;
    cout << "myQueue.push(6)" << myQueue.push(6) << endl;
    cout << "myQueue.pop()" << myQueue.pop() << endl;
    cout << "myQueue.push(7)" << myQueue.push(7) << endl;
    cout << "myQueue.push(8)" << myQueue.push(8) << endl;
    cout << "myQueue.push(9)" << myQueue.push(9) << endl;

    cout << "                 heap                                       " << endl;

    cout << "=================ArrayStackQueueTest====================" << endl;
  }
};

#endif
