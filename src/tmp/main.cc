#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================CutRod=========================" << endl;
    vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
    int result = BruteResult(arr);
    cout << "BruteResult: " << result << endl;
    result = DpResult(arr);
    cout << "DpResult: " << result << endl;

    arr = {3, 5, 8, 9, 10, 17, 17, 20};
    result = BruteResult(arr);
    cout << "BruteResult: " << result << endl;
    result = DpResult(arr);
    cout << "DpResult: " << result << endl;
    cout << "=========================CutRod=========================" << endl;
  }

  int DpResult(vector<int> &arr)
  {
    int rodSize = arr.size();
    vector<int> bookmark(rodSize + 1, 0);
    bookmark[1] = arr[0];
    for (int i = 2; i <= rodSize; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        int remain = i - j;
        bookmark[i] = std::max(bookmark[j] + arr[i-j-1], bookmark[i]);
      }
    }

    return bookmark[rodSize];
  }

  int BruteResult(vector<int> &arr)
  {
    return BruteResultAux(arr, arr.size());
  }

  int BruteResultAux(vector<int> &arr, int rodLength)
  {
    if (rodLength <= 0)
    {
      return 0;
    }

    int sum = 0;
    for (size_t i = 1; i <= rodLength; ++i)
    {
      sum = std::max(sum, arr[i-1] + BruteResultAux(arr, rodLength - i));
    }

    return sum;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
