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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    int input;
    int result;

    result = mySqrt(4);
    cout << "result: " << result << endl;

    result = mySqrt(8);
    cout << "result: " << result << endl;
  }

  int mySqrt(int x) {
    int root = 0;
    int value1 = 0;
    int value2 = 0;
    while (true)
    {
      value1 = root * root;
      value2 = (root + 1) * (root + 1);
      if (value1 < x && x < value2)
      {
        return root;
      }
      else
      {
        root += 2;
      }
    }
  }

  void Show(vector<string> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
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
