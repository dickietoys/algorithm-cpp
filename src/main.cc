#include <container/vector.h>
#include <container/list.h>
#include <container/binary_search_tree.h>
#include <container/binary_heap.h>
#include <algo/maximum_conti_subsequence.h>
#include <algo/expression_convert.h>
#include <container/binary_heap.h>
#include <sort/sort.h>
#include <algo/find_kth_element.h>

#include <vector>
#include <iostream>

void vectorTest()
{
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  std::cout << v << std::endl;
}

void listTest()
{
  List<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.push_back(6);
  List<int>::const_iterator it;
  for (it = l.begin(); it != l.end(); ++it)
  {
    std::cout << *it << std::endl;
  }
}

void findMaxSubSequenceTest()
{
  FindMaxSubSequence findMaxSubSequence;
  std::vector<int> data;
  data.push_back(4);
  data.push_back(-3);
  data.push_back(5);
  data.push_back(-2);
  data.push_back(-1);
  data.push_back(2);
  data.push_back(6);
  data.push_back(-2);
  cout << findMaxSubSequence.findMax(data) << endl;
}

void infixConvert2PostfixTest()
{
  expression_convert expressionConvert;
  string infixStr = "a+b*c+(d*e+f)*g";

  string postfixData = expressionConvert.infix2postfix(infixStr);
  cout << postfixData << endl;
}

void binarySearchTreeTest()
{
  BinarySearchTree<int> bst;
  bst.insert(10);
  bst.insert(5);
  bst.insert(2);
  bst.insert(7);
  bst.insert(15);
  bst.insert(12);
  bst.insert(18);
  bst.printTree(cout, 0);
  cout << "===========================" << endl;
  bst.printTree(cout, 1);
  cout << "===========================" << endl;
  bst.printTree(cout, 2);
  cout << "===========================" << endl;
  cout << "height: " << bst.height() << endl;
}

void binaryHeapTest()
{
  vector<int> data = {9, 11, 8, 6, 7, 12};
  BinaryHeap<int> bh(data);
  bh.printHeap();
}

template<class T>
void printVector(vector<T> &data)
{
  for(size_t i = 0; i < data.size(); ++i)
  {
    cout << data[i] << ",  ";
  }

  cout << endl;
}

void findKthElementTest()
{
  FindKthElement<int> fke;
  vector<int> data = {9, 11, 8, 6, 7, 12};
  int kth = 1;
  printVector(data);

  int foundElement = fke.findKthByBinaryHeap(data, kth);
  cout << "use binary heap found " << kth << "th:" << foundElement << endl;

  foundElement = fke.findKthByBinarySearchTree(data, kth);
  cout << "use binary search tree found " << kth << "th:" << foundElement << endl;

  foundElement = fke.findKthByQuickSelect(data, kth);
  cout << "use quickselect found " << kth << "th:" << foundElement << endl;
}

void sortBoxTest()
{
  SortBox<int> sb;
  vector<int> data = {9, 11, 8, 6, 7, 12};
  sb.doAllSort(data);
  data = {11,12,13,14,15,16,17,18};
  sb.doAllSort(data);
  data = {18,17,16,15,14,13,12,11};
  sb.doAllSort(data);
  data = {17,11,18,13,15,14,12,16};
  sb.doAllSort(data);
}

int main()
{
  findKthElementTest();
  // sortBoxTest();
  return 0;
}
