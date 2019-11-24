#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================LIS=========================" << endl;
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int longest = BruteResult(arr);
    cout << "BruteResult: " << longest << endl;
    longest = DpResult(arr);
    cout << "DpResult: " << longest << endl;
    cout << "=========================LIS=========================" << endl;
  }

  int DpResult(vector<int> &arr)
  {
    int length = arr.size();
    vector<int> bookmark(arr.size(), 0);
    bookmark[0] = 1;
    int max = 0;
    for (int i = 0; i < length; ++i)
    {
      int currentMax = 0;
      for (int j = 0; j < i; ++j)
      {
        if (arr[i] > arr[j])
        {
          currentMax = std::max(currentMax, bookmark[j]);
        }
      }
      currentMax += 1;
      bookmark[i] = currentMax;
      max = std::max(max, currentMax);
    }

    return max;
  }

  int BruteResult(vector<int> &arr)
  {
    return BruteResultAux(arr, -1, 0);
  }

  int BruteResultAux(vector<int> &arr, int prevPos, int curPos)
  {
    int length = arr.size();
    if (curPos >= length)
    {
      return 0;
    }

    int sum1 = 0;
    int sum2 = 0;
    if (prevPos == -1 || arr[curPos] > arr[prevPos])
    {
      sum1 = BruteResultAux(arr, curPos, curPos+1) + 1;
    }

    sum2 = BruteResultAux(arr, prevPos, curPos+1);

    return std::max(sum1, sum2);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
