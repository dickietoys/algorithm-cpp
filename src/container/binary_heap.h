#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <iostream>
#include <exception>

using namespace std;

template<class T>
class BinaryHeap
{
 public:
  explicit BinaryHeap(int capacity = 100)
  {
    array.resize(capacity);
    currentSize = 0;
  }

  explicit BinaryHeap(const vector<T> & items) :
      currentSize(items.size()), array(items.size() + 10)
  {
    for(size_t i = 0; i < items.size(); ++i)
    {
      array[i+1] = items[i];
    }
    buildHeap();
  }

  void printHeap()
  {
    for (size_t i = 1; i <= currentSize; ++i)
    {
      cout << array[i] << "; ";
    }

    cout << endl;
  }

  bool isEmpty() const
  {
    return currentSize == 0;
  }

  const T & findMin() const
  {
    if (isEmpty())
    {
      throw exception();
    }

    return array[1];
  }

  void insert(const T &x)
  {
    if (currentSize == array.size() - 1)
    {
      array.resize(array.size() * 2);
    }

    int hole = ++currentSize;
    array[hole] = x;
    percolateUp(hole);
  }

  void deleteMin()
  {
    if (isEmpty())
    {
      throw exception();
    }

    array[1] = array[currentSize--];
    percolateDown(1);
  }

  void deleteMin(T & minItem)
  {
    if (isEmpty())
    {
      throw exception();
    }

    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
  }

  void makeEmpty()
  {
    currentSize = 0;
  }

 private:
  size_t currentSize;
  vector<T> array;

  void buildHeap()
  {
    for (size_t pos = currentSize/2; pos > 0; --pos)
    {
      percolateDown(pos);
    }
  }

  void percolateDown(size_t hole)
  {
    size_t child;
    T value = array[hole];
    for (; hole * 2 <= currentSize; hole = child)
    {
      child = hole * 2;
      if (child != currentSize && array[child+1] < array[child])
      {
        ++child;
      }
      if (array[child] < value)
      {
        array[hole] = array[child];
      }
      else
      {
        break;
      }
    }

    array[hole] = value;
  }

  void percolateUp(int hole)
  {
    T value = array[hole];
    for (; value < array[hole / 2]; hole = hole / 2)
    {
      array[hole] = array[hole / 2];
    }

    array[hole] = value;
  }
};


#endif
