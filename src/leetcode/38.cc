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

using namespace std;

class Solution {
public:
  void RunTest()
  {
    int input;
    string result;

    result = countAndSay(1);
    cout << "result: " << result << endl;

    result = countAndSay(2);
    cout << "result: " << result << endl;

    result = countAndSay(3);
    cout << "result: " << result << endl;

    result = countAndSay(4);
    cout << "result: " << result << endl;

    result = countAndSay(5);
    cout << "result: " << result << endl;

  }

  string countAndSay(int n) {
    if (n == 1)
    {
      return "1";
    }

    string prevResult = countAndSay(n-1);
    string curResult = "";
    int count = 1;
    char lastChar = prevResult[0];
    for (size_t i = 1; i < prevResult.size(); ++i)
    {
      if (lastChar == prevResult[i])
      {
        ++count;
      }
      else
      {
        curResult.append(std::to_string(count)).push_back(lastChar);
        count = 1;
        lastChar = prevResult[i];
      }
    }
    curResult.append(std::to_string(count)).push_back(lastChar);

    return curResult;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
