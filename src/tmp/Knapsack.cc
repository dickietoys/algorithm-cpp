#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Goods{
  int value;
  int weight;
};

class Solution {
public:
  void RunTest()
  {
    cout << "=========================MinPartition=========================" << endl;
    vector<Goods> arr = {{60, 10}, {100, 20}, {120, 30}};
    int maxWeight = 50;
    int maxValue = BruteResult(arr, maxWeight);
    cout << "BruteResult: " << maxValue << endl;
    maxValue = DpResult(arr, maxWeight);
    cout << "DpResult: " << maxValue << endl;
    cout << "=========================MinPartition=========================" << endl;
  }

  int DpResult(vector<Goods> &arr, int maxWeight)
  {
    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(maxWeight+1, 0));
    for (size_t i = 1; i < arr.size() + 1; ++i)
    {
      for (size_t j = 1; j < maxWeight + 1; ++j)
      {
        bookmark[i][j] = bookmark[i-1][j];
        if (arr[i-1].weight <= j)
        {
          bookmark[i][j] = std::max(bookmark[i][j], arr[i-1].value + bookmark[i-1][j - arr[i-1].weight]);
        }
      }
    }

    return bookmark[arr.size()][maxWeight];
  }

  int BruteResult(vector<Goods> &arr, int maxWeight)
  {
    return BruteResultAux(arr, 0, maxWeight, 0, 0);
  }

  int BruteResultAux(vector<Goods> &arr, int pos, int maxWeight, int curWeight, int value)
  {
    if (pos >= arr.size())
    {
      return value;
    }

    int sum1 = 0;
    int sum2 = 0;
    if (arr[pos].weight + curWeight <= maxWeight)
    {
      sum1 = BruteResultAux(arr, pos+1, maxWeight, arr[pos].weight + curWeight, value + arr[pos].value);
    }

    sum2 = BruteResultAux(arr, pos+1, maxWeight, curWeight, value);

    return std::max(sum1, sum2);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
