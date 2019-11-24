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
    cout << "=========================CutRod=========================" << endl;
  }

  int BruteResult(vector<int> &arr)
  {
    return BruteResultAux(arr, 0);
  }

  int BruteResultAux(vector<int> &arr, int pos)
  {
    if (pos >= arr.size())
    {
      return 0;
    }

    int sum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
      sum = std::max(sum, arr[i] + BruteResultAux(arr, i + 1));
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
