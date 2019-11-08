#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <vector>
#include <functional>

#include <testsuit/TestBase.h>

using namespace std;

template<class CompareFunction = greater<int>>
class Heap
{
 public:
  Heap(int capacity, CompareFunction &compareFunction) :
      arr_(vector<int>(capacity, 0)),
      capacity_(capacity),
      size_(0),
      compareFunction_(compareFunction)
  {}

  static bool MakeHeap(vector<int> &unFormattedArr)
  {
    return true;
  }

  bool Insert(int value)
  {
    if (size_ == capacity_)
    {
      return false;
    }

    if (size_ == 0)
    {
      arr_[0] = value;
    }
    else
    {
      ++size_;
      int pos = size_;
      up(pos, value);
    }

    return true;
  }

  int Pop()
  {

  }

  int Peek()
  {

  }

  int FindValue(int value)
  {

  }

  bool RemovePos(int pos)
  {

  }

 private:
  void up(int pos, int value, )
  {
    int parentPos = (pos - 1) / 2;
    if (arr_(parentPos) < value)
  }

  int parent(int pos)
  {
    return (pos - 1) / 2;
  }

  int left(int pos)
  {
    return pos * 2 + 1;
  }

  int right(int pos)
  {
    return pos * 2 + 2;
  }

 private:
  vector<int> arr_;
  int capacity_;
  int size_;
  CompareFunction compareFunction_;
};


class HeapTest: public TestBase
{
 public:
  void DoTest()
  {}
};

#endif
