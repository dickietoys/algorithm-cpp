#ifndef PARTITION_PROBLEM_H_
#define PARTITION_PROBLEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

class PartitionProblem : public TestBase
{
 public:
  void DoTest()
  {
    vector<int> arr = {1, 5, 11, 5};

    cout << "BrutePartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BrutePartition(arr) << endl;
    cout << "DpPartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpPartition(arr) << endl;

    arr = {1, 5, 3};
    cout << "BrutePartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BrutePartition(arr) << endl;
    cout << "DpPartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpPartition(arr) << endl;
  }

  int BrutePartition(const vector<int> &arr)
  {
    int sum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      sum += arr[i];
    }

    if (sum % 2 == 1)
    {
      return 0;
    }

    return BrutePartitionAux(arr, arr.size(), sum / 2);
  }

  int DpPartition(const vector<int> &arr)
  {
    return DpPartitionAux(arr);
  }

 private:
  int BrutePartitionAux(const vector<int> &arr, int pos, int sum)
  {
    if (pos == 0 && sum != 0)
    {
      return 0;
    }

    if (sum == 0)
    {
      return 1;
    }

    return BrutePartitionAux(arr, pos - 1, sum) || BrutePartitionAux(arr, pos - 1, sum - arr[pos - 1]);
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

  int DpPartitionAux(const vector<int> &arr)
  {
    int sum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      sum += arr[i];
    }

    if (sum % 2 == 1)
    {
      return 0;
    }

    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(sum +1, 0));
    for (size_t i = 0; i <= arr.size(); ++i)
    {
      bookmark[i][0] = 1;
    }

    for (int i = 1; i <= sum; ++i)
    {
      bookmark[0][i] = 0;
    }

    for (size_t i = 1; i <= arr.size(); ++i)
    {
      for (int j = 1; j <= sum; ++j)
      {
        bookmark[i][j] = bookmark[i-1][j];
        if (arr[i-1] <= j)
        {
          bookmark[i][j] = bookmark[i][j] | bookmark[i-1][j-arr[i-1]];
        }
      }
    }

    return bookmark[arr.size()][sum / 2];
  }
};

#endif
