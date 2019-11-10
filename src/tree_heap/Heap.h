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
  Heap(int capacity) :
      arr_(vector<int>(capacity, 0)),
      capacity_(capacity),
      size_(0)
  {}

  Heap(int capacity, const CompareFunction &compareFunction) :
      arr_(vector<int>(capacity, 0)),
      capacity_(capacity),
      size_(0),
      compareFunction_(compareFunction)
  {}

  bool MakeHeap(vector<int> &unFormattedArr)
  {
    arr_ = unFormattedArr;
    size_ = arr_.size();
    capacity_ = arr_.size();
    int pos = size_ / 2 - 1;
    for (; pos >= 0; --pos)
    {
      down(pos);
    }

    return true;
  }

  bool Insert(int value)
  {
    if (size_ == capacity_)
    {
      return false;
    }

    arr_[size_++] = value;
    up(size_ - 1);
    return true;
  }

  int Pop()
  {
    if (size_ == 0)
    {
      return 0;
    }
    int value = arr_[0];
    arr_[0] = arr_[size_ - 1];
    --size_;
    down(0);

    return value;
  }

  int Peek()
  {
    return arr_[0];
  }

  void Show()
  {
    if (size_ == 0)
    {
      cout << "empty";
    }
    else
    {
      for (int i = 0; i < size_; ++i)
      {
        cout << arr_[i] << ", ";
      }
    }
    cout << endl;
  }

 private:
  void up(int pos)
  {
    int parentPos = parent(pos);
    while (compareFunction_(arr_[pos], arr_[parentPos]))
    {
      std::swap(arr_[pos], arr_[parentPos]);
      pos = parentPos;
      parentPos = parent(pos);
    }
  }

  void down(int pos)
  {
    int holePos = left(pos);
    for (; holePos <= size_ - 1;)
    {
      if (holePos != size_ - 1 && compareFunction_(arr_[holePos + 1], arr_[holePos]))
      {
        ++holePos;
      }

      if (compareFunction_(arr_[holePos], arr_[pos]))
      {
        std::swap(arr_[pos], arr_[holePos]);
        pos = holePos;
        holePos = left(pos);
      }
      else
      {
        break;
      }
    }
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
  {
    cout << "=================HeapTest====================" << endl;
    vector<int> unFormatted = {4, 5, 8, 3, 2, 7, 6, 1};
    Heap<> myHeap1(8);
    myHeap1.Insert(7);
    myHeap1.Insert(5);
    myHeap1.Insert(8);
    myHeap1.Insert(1);
    myHeap1.Insert(2);
    myHeap1.Insert(4);
    myHeap1.Insert(6);
    myHeap1.Insert(3);
    myHeap1.Show();
    cout << myHeap1.Pop() << endl;
    cout << myHeap1.Pop() << endl;
    cout << myHeap1.Pop() << endl;
    cout << myHeap1.Pop() << endl;
    cout << myHeap1.Pop() << endl;
    cout << myHeap1.Pop() << endl;
    cout << myHeap1.Pop() << endl;
    cout << myHeap1.Pop() << endl;
    myHeap1.Show();
    myHeap1.Insert(6);
    myHeap1.Insert(4);
    myHeap1.Insert(7);
    myHeap1.Insert(8);
    myHeap1.Show();

    myHeap1.MakeHeap(unFormatted);
    myHeap1.Show();


    Heap<less<int>> myHeap2(8);
    myHeap2.Insert(7);
    myHeap2.Insert(5);
    myHeap2.Insert(8);
    myHeap2.Insert(1);
    myHeap2.Insert(2);
    myHeap2.Insert(4);
    myHeap2.Insert(6);
    myHeap2.Insert(3);
    myHeap2.Show();
    cout << myHeap2.Pop() << endl;
    cout << myHeap2.Pop() << endl;
    cout << myHeap2.Pop() << endl;
    cout << myHeap2.Pop() << endl;
    cout << myHeap2.Pop() << endl;
    cout << myHeap2.Pop() << endl;
    cout << myHeap2.Pop() << endl;
    cout << myHeap2.Pop() << endl;
    myHeap2.Show();
    myHeap2.Insert(6);
    myHeap2.Insert(4);
    myHeap2.Insert(7);
    myHeap2.Insert(8);
    myHeap2.Show();

    myHeap2.MakeHeap(unFormatted);
    myHeap2.Show();
    cout << "=================HeapTest====================" << endl;
  }
};

#endif
