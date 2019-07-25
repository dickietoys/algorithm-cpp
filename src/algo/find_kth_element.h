#ifndef FIND_KTH_ELEMENT_H
#define FIND_KTH_ELEMENT_H

#include <container/binary_heap.h>
#include <container/binary_search_tree.h>
#include <vector>
#include <stack>

using namespace std;

template<class T>
class FindKthElement
{
 public:
  T findKthByBinaryHeap(vector<T> &data, int kth)
  {
    BinaryHeap<T> bh(kth);
    for (int i = 0; i < kth; ++i)
    {
      bh.insert(data[i]);
    }

    for (size_t i = kth; i < data.size(); ++i)
    {
      if (data[i] > bh.findMin())
      {
        bh.deleteMin();
        bh.insert(data[i]);
      }
    }

    return bh.findMin();
  }

  T findKthByBinarySearchTree(vector<T> &data, int kth)
  {
    BinarySearchTree<T> bst;
    for (size_t i = 0; i != data.size(); ++i)
    {
      bst.insert(data[i]);
    }

    T kthElement = bst.findKthElement(data.size() - kth + 1);

    return kthElement;
  }

  T findKthByQuickSelect(vector<T> &data, int kth)
  {
    return findKthByQuickSelect(data, 0, data.size() - 1, kth);
  }

 private:
  T findKthByQuickSelect(vector<T> &data, int leftPos, int rightPos, int kth)
  {
    int i = 0;
    int j = rightPos - 1;
    int pivot = data[rightPos];
    while (i <= j)
    {
      if (data[i] < pivot)
      {
        ++i;
        continue;
      }

      if (data[j] > pivot)
      {
        ++j;
        continue;
      }

      swap(data[i], data[j]);
    }

    swap(data[i], data[rightPos]);
    if (kth < (i - leftPos))
    {
      return findKthByQuickSelect(data, leftPos, i, kth);
    }
    else if (kth > (rightPos - i))
    {
      return findKthByQuickSelect(data, i + 1, rightPos, kth - i);
    }
    else
    {
      return data[i];
    }
  }
};


#endif
