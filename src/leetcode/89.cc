#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    int input;
    vector<int> result;

    result = grayCode(2);
    Show(result);

    result = grayCode(0);
    Show(result);
  }

  vector<int> grayCode(int n) {
    vector<int> result;
    bitset<64> bs;
    Aux(bs, result, n);
    return result;
  }

  void Aux(bitset<64> &bs, vector<int> &result, int n)
  {
    if (n == 0)
    {
      result.push_back(bs.to_ulong());
    }
    else
    {
      Aux(bs, result, n - 1);
      bs.flip(n-1);
      Aux(bs, result, n - 1);
    }
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
