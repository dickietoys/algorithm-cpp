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
    string input;
    string result;

    result = addBinary("11", "1");
    cout << "result: " << result << endl;

    result = addBinary("1010", "1011");
    cout << "result: " << result << endl;
  }

  string addBinary(string a, string b) {
    int pos1 = a.size() - 1;
    int pos2 = b.size() - 1;

    int value = 0;
    int remain = 0;
    string result = "";
    while (pos1 >= 0 && pos2 >= 0)
    {
      value = a[pos1] - '0' + b[pos2] - '0' + remain;
      remain = value / 2;
      value = value % 2;
      result.insert(result.begin(), value + '0');
      --pos1;
      --pos2;
    }

    while (pos1 >= 0)
    {
      value = a[pos1] - '0' + remain;
      remain = value / 2;
      value = value % 2;
      result.insert(result.begin(), value + '0');
      --pos1;
    }

    while(pos2 >= 0)
    {
      value = b[pos2] - '0' + remain;
      remain = value / 2;
      value = value % 2;
      result.insert(result.begin(), value + '0');
      --pos2;
    }

    if (remain)
    {
      result.insert(result.begin(), remain + '0');
    }

    return result;
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
