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
    string input;
    int result;

    input = "hello world";
    result = lengthOfLastWord(input);
    cout << "result: " << result << endl;
  }

  int lengthOfLastWord(string s) {
    int size = s.size();
    int leftPos = 0;
    int rightPos = 0;
    bool doCalc = false;
    for (int i = size - 1; i >= 0; --i)
    {
      if (s[i] != ' ' && !doCalc)
      {
        doCalc = true;
        rightPos = i;
      }
      else if (s[i] == ' ' && doCalc)
      {
        leftPos = i + 1;
        break;
      }
    }
    if (doCalc)
    {
      return rightPos - leftPos + 1;
    }
    else
    {
      return 0;
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
