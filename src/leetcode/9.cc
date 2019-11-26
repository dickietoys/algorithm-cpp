#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    int value = 0;
    bool result = 0;
    value = 121;
    result = isPalindrome(value);
    cout << "result: " << result << endl;
    assert(result == true);

    value = -121;
    result = isPalindrome(value);
    cout << "result: " << result << endl;
    assert(result == false);

    value = 10;
    result = isPalindrome(value);
    cout << "result: " << result << endl;
    assert(result == false);
  }

  bool isPalindrome(int x) {
    if (x < 0)
    {
      return false;
    }

    if (x == 0)
    {
      return true;
    }

    vector<int> digitArr;
    int digit = 0;
    while (x)
    {
      digit = x % 10;
      x = x / 10;
      digitArr.push_back(digit);
    }

    int i = 0;
    int j = digitArr.size() - 1;
    while (i < j)
    {
      if (digitArr[i] != digitArr[j])
      {
        return false;
      }

      ++i;
      --j;
    }

    return true;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
