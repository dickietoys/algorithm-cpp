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
  const T findKthByBinaryHeap(vector<T> &data, int kth)
  {
    BinaryHeap<T> bh(kth);
    for (int i = 0; i < kth; ++i)
    {
      bh.insert(data[i]);
    }
    bh.printHeap();

    for (size_t i = kth; i < data.size(); ++i)
    {
      if (data[i] > bh.findMin())
      {
        bh.deleteMin();
        bh.insert(data[i]);
      }
    }

    bh.printHeap();

    return bh.findMin();
  }

  const T findKthByBinarySearchTree(vector<T> &data, int kth)
  {
    BinarySearchTree<T> bst;
    for (size_t i = 0; i != data.size(); ++i)
    {
      bst.insert(data[i]);
    }

    T & kthElement = bst.findKthElement(kth);

    return s.top();
  }
};


#endif
