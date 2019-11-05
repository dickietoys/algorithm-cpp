#ifndef SUBSET_SUM_PROBLEM_H_
#define SUBSET_SUM_PROBLEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;


/*
  数组子序的和能否是n
*/
class SubsetSumProblem : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================SubsetSumProblem====================" << endl;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << "BruteHasSubset(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") has subset sum = " << sum  <<": " << BruteHasSubset(arr, sum) << endl;
    cout << "DpPartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") has subset sum = " << sum  <<": " << DpHasSubset(arr, sum) << endl;

    sum = 20;
    cout << "BruteHasSubset(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") has subset sum = " << sum  <<": " << BruteHasSubset(arr, sum) << endl;
    cout << "DpPartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") has subset sum = " << sum  <<": " << DpHasSubset(arr, sum) << endl;


    sum = 25;
    cout << "BruteHasSubset(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") has subset sum = " << sum  <<": " << BruteHasSubset(arr, sum) << endl;
    cout << "DpPartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") has subset sum = " << sum  <<": " << DpHasSubset(arr, sum) << endl;
    cout << "=================SubsetSumProblem====================" << endl;
  }

  int BruteHasSubset(const vector<int> &arr, int targetSum)
  {
    int sum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      sum += arr[i];
    }

    if (sum < targetSum)
    {
      return 0;
    }

    return BruteHasSubsetAux(arr, 0, targetSum, 0);
  }

  int DpHasSubset(const vector<int> &arr, int targetSum)
  {
    return DpHasSubsetAux(arr, targetSum);
  }

 private:
  int BruteHasSubsetAux(const vector<int> &arr, int pos, int sum, int currentSum)
  {
    if (currentSum > sum || pos >= static_cast<int>(arr.size()))
    {
      return 0;
    }

    if (currentSum == sum)
    {
      return 1;
    }

    return BruteHasSubsetAux(arr, pos + 1, sum, currentSum + arr[pos]) || BruteHasSubsetAux(arr, pos + 1, sum, currentSum);
  }

  int DpHasSubsetAux(const vector<int> &arr, int sum)
  {
    int totalSum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      totalSum += arr[i];
    }
    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(totalSum + 1, 0));
    for (size_t i = 0; i <= arr.size(); ++i)
    {
      bookmark[i][0] = 1;
    }
    for (size_t i = 1; i <= arr.size(); ++i)
    {
      for (int j = 1; j <= totalSum; ++j)
      {
        bookmark[i][j] = bookmark[i-1][j];
        if (arr[i-1] <= j)
        {
          bookmark[i][j] = bookmark[i][j] || bookmark[i - 1][j - arr[i - 1]];
        }
      }
    }

    return bookmark[arr.size()][sum];
  }

  void showBookmark(vector<vector<int>> &bookmark)
  {
    cout << endl;
    for (size_t i = 0; i < bookmark.size(); ++i)
    {
      for (size_t j = 0; j < bookmark[i].size(); ++j)
      {
        cout << bookmark[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

#endif
