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


int main()
{
  // TestBase *testCase = new LongestIncreasingSubSequence();
  // TestBase *testCase = new LongestCommonSubSequence();
  // TestBase *testCase = new EditDistance();
  // TestBase *testCase = new MinimumPartition();
  // TestBase *testCase = new PartitionProblem();
  // TestBase *testCase = new CoverDistance();
  // TestBase *testCase = new FindLongestPath();
  // TestBase *testCase = new SubsetSumProblem();
  TestBase *testCase = new OptimalStrategyForGame();
  testCase->DoTest();

  // delete testCase;

  return 0;
}
