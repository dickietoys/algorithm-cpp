#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
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
      array(items.size() + 10), currentSize(items.size())
  {
    for(int i = 0; i < items.size(); ++i)
    {
      array[i+1] = items[i];
    }
    buildHeap();
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
  int currentSize;
  vector<T> array;

  void buildHeap()
  {

  }

  void percolateDown(int hole)
  {
    int child;
    int value = array[hole];
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

    array[child] = value;
  }

  void percolateUp(int hole)
  {
    int value = array[hole];
    for (; value < array[hole / 2]; hole = hole / 2)
    {
      array[hole] = array[hole / 2];
    }

    array[hole] = value;
  }
};


#endif
