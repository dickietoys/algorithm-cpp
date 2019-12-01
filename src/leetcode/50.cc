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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    double input;
    double result;

    result = myPow(2.0, 10);
    cout << "result: " << result << endl;

    result = myPow(2.1, 3);
    cout << "result: " << result << endl;

    result = myPow(2.0, -2);
    cout << "result: " << result << endl;
  }

  double myPow(double x, int n) {
    long ln = long(n);
    double value = Aux(x, std::abs(ln));
    if (n < 0)
    {
      return 1 / value;
    }
    else
    {
      return value;
    }
  }

  double Aux(double x, long n)
  {
    if(n == 0)
    {
      return 1;
    }

    if (n == 1)
    {
      return x;
    }

    if (n % 2 == 0)
    {
      double halfValue = Aux(x, n/2);
      return halfValue * halfValue;
    }
    else
    {
      double halfValue = Aux(x, (n-1)/2);
      return halfValue * halfValue * x;
    }
  }

  void Show(vector<vector<string>> &result)
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
