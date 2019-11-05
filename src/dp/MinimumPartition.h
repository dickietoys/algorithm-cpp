#ifndef MINIMUM_PARTITION_H_
#define MINIMUM_PARTITION_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

/*
  将数组分成两个序列，两个序列和的差值最小
*/
class MinimumPartition : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================MinimumPartition====================" << endl;
    vector<int> arr = {1, 6, 11, 5};

    cout << "BrutePartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BrutePartition(arr) << endl;
    cout << "DpPartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpPartition(arr) << endl;

    arr = {3, 1, 4, 2, 2, 1};
    cout << "BrutePartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BrutePartition(arr) << endl;
    cout << "DpPartition(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpPartition(arr) << endl;
    cout << "=================MinimumPartition====================" << endl;
  }

  int BrutePartition(const vector<int> &arr)
  {
    int sum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      sum += arr[i];
    }

    return BrutePartitionAux(arr, arr.size(), 0, sum);
  }

  int DpPartition(const vector<int> &arr)
  {
    return DpPartitionAux(arr);
  }

 private:
  int BrutePartitionAux(const vector<int> &arr, int pos, int leftSum, int sum)
  {
    if (pos == 0)
    {
      return std::abs(sum - leftSum -leftSum);
    }
    return std::min(BrutePartitionAux(arr, pos - 1, leftSum, sum),
                    BrutePartitionAux(arr, pos - 1, leftSum + arr[pos - 1], sum));
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

    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(sum + 1, 0));
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
        bookmark[i][j] = bookmark[i - 1][j];
        if (arr[i - 1] <= j)
        {
          bookmark[i][j] |= bookmark[i][j - arr[i-1]];
        }
      }
    }

    int diff = std::numeric_limits<int>::max();
    for (int i = sum / 2; i >=0; --i)
    {
      if (bookmark[arr.size()][i] == 1)
      {
        diff = sum - 2 * i;
        break;
      }
    }

    return diff;
  }
};

#endif
