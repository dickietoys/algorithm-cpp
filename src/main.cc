#include <container/vector.h>
#include <container/list.h>
#include <container/binary_search_tree.h>
#include <container/binary_heap.h>
#include <container/graph_container.h>
#include <algo/maximum_conti_subsequence.h>
#include <algo/expression_convert.h>
#include <container/binary_heap.h>
#include <sort/sort.h>
#include <algo/find_kth_element.h>
#include <algo/dp_algo.h>
#include <testsuit/TestBase.h>
#include <dp/LongestIncreasingSubSequence.h>
#include <dp/LongestCommonSubSequence.h>
#include <dp/EditDistance.h>
#include <dp/MinimumPartition.h>
#include <dp/PartitionProblem.h>


#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

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
  // data = {11,12,13,14,15,16,17,18};
  // sb.doAllSort(data);
  // data = {18,17,16,15,14,13,12,11};
  // sb.doAllSort(data);
  // data = {17,11,18,13,15,14,12,16};
  // sb.doAllSort(data);
}

void graphTest()
{
  GraphAdjacentArray graphAdjacentArray(7);
  graphAdjacentArray.setVertexRelation(1, 2);
  graphAdjacentArray.setVertexRelation(1, 4);
  graphAdjacentArray.setVertexRelation(2, 4);
  graphAdjacentArray.setVertexRelation(2, 5);
  graphAdjacentArray.setVertexRelation(3, 1);
  graphAdjacentArray.setVertexRelation(3, 6);
  graphAdjacentArray.setVertexRelation(4, 6);
  graphAdjacentArray.setVertexRelation(4, 7);
  graphAdjacentArray.setVertexRelation(4, 3);
  graphAdjacentArray.setVertexRelation(4, 5);
  graphAdjacentArray.setVertexRelation(5, 7);
  graphAdjacentArray.setVertexRelation(7, 6);
  graphAdjacentArray.BFS(3, 6);
  graphAdjacentArray.BFS(3, 7);
  graphAdjacentArray.BFS(3, 4);
  graphAdjacentArray.resetAuxData();
  graphAdjacentArray.DFS();
}

void dpCutSteelBarTest()
{
  vector<int> initPrice = {0,
                           1,
                           5,
                           8,
                           9,
                           10,
                           17,
                           17,
                           20,
                           24,
                           30};
  CutSteelBar cutSteelBar(initPrice);
  int length = 0;
  cout << "===========================using top down strategy===========================" << endl;
  length = 12;
  printf("length: %d, max price: %d\n", length, cutSteelBar.calcByTopDown(length));
  cutSteelBar.showCutStrategy();
  length = 4;
  printf("length: %d, max price: %d\n", length, cutSteelBar.calcByTopDown(length));
  cutSteelBar.showCutStrategy();
  length = 7;
  printf("length: %d, max price: %d\n", length, cutSteelBar.calcByTopDown(length));
  cutSteelBar.showCutStrategy();

  cout << "===========================using bottom up strategy===========================" << endl;
  length = 12;
  printf("length: %d, max price: %d\n", length, cutSteelBar.calcByTopDown(length));
  cutSteelBar.showCutStrategy();
  length = 4;
  printf("length: %d, max price: %d\n", length, cutSteelBar.calcByTopDown(length));
  cutSteelBar.showCutStrategy();
  length = 7;
  printf("length: %d, max price: %d\n", length, cutSteelBar.calcByTopDown(length));
  cutSteelBar.showCutStrategy();
}

void dpLCSTest()
{
  LCS lcs;
  string s1 = "abcdefg";
  string s2 = "acfdd";
  printf("bruteFind:  %s, %s LCS: %s\n", s1.c_str(), s2.c_str(), lcs.bruteFind(s1, s2).c_str());
  printf("findLCS:    %s, %s LCS: %s\n", s1.c_str(), s2.c_str(), lcs.FindLCS(s1, s2).c_str());
}

int main()
{
  // TestBase *testCase = new LongestIncreasingSubSequence();
  // TestBase *testCase = new LongestCommonSubSequence();
  // TestBase *testCase = new EditDistance();
  // TestBase *testCase = new MinimumPartition();
  TestBase *testCase = new PartitionProblem();
  testCase->DoTest();

  delete testCase;

  return 0;
}
