#include <testsuit/TestBase.h>
#include <dp/LongestIncreasingSubSequence.h>
#include <dp/LongestCommonSubSequence.h>
#include <dp/EditDistance.h>
#include <dp/MinimumPartition.h>
#include <dp/PartitionProblem.h>
#include <dp/CoverDistance.h>
#include <dp/FindLongestPath.h>
#include <dp/SubsetSumProblem.h>
#include <dp/OptimalStrategyForGame.h>
#include <dp/KnapsackProblem.h>
#include <dp/BooleanParenthesizationProblem.h>
#include <dp/CutRod.h>
#include <dp/CoinChange.h>
#include <dp/WordBreak.h>
#include <array_stack_queue/ArrayStackQueue.h>
#include <tree_heap/Heap.h>
#include <tree_heap/Tree.h>
#include <graph/Graph.h>

int main()
{
  TestBase *testCase = nullptr;
  // testCase = new LongestIncreasingSubSequence();
  // testCase = new LongestCommonSubSequence();
  // testCase = new EditDistance();
  // testCase = new MinimumPartition();
  // testCase = new PartitionProblem();
  // testCase = new CoverDistance();
  // testCase = new FindLongestPath();
  // testCase = new SubsetSumProblem();
  // testCase = new OptimalStrategyForGame();
  // testCase = new BooleanParenthesizationProblem();
  // testCase = new KnapsackIgnoreGoodsValueProblem();
  // testCase = new KnapsackProblem();
  // testCase = new CutRod();
  // testCase = new CoinChange();
  // testCase = new WordBreak();
  // testCase = new ArrayStackQueueTest();
  // testCase = new HeapTest();
  // testCase = new TreeTest();
  testCase = new GraphTest();
  testCase->DoTest();

  delete testCase;
  return 0;
}
