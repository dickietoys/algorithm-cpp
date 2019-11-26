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
    string s = "42";
    int result = 0;
    result = myAtoi(s);
    cout << "result: " << result << endl;
    assert(result == 42);

    s = "-42";
    result = myAtoi(s);
    cout << "result: " << result << endl;
    assert(result == -42);

    s = "4193 with words";
    result = myAtoi(s);
    cout << "result: " << result << endl;
    assert(result == 4193);

    s = "words and 987";
    result = myAtoi(s);
    cout << "result: " << result << endl;
    assert(result == 0);

    s = "-91283472332";
    result = myAtoi(s);
    cout << "result: " << result << endl;
    assert(result == -2147483648);

    s = "-2147483649";
    result = myAtoi(s);
    cout << "result: " << result << endl;
    assert(result == -2147483648);
  }

  int myAtoi(string str) {
    int result = 0;
    int digit = 0;
    int length = str.size();
    int startPos = 0;
    for (int i = 0; i < length; ++i)
    {
      if (str[i] == ' ')
      {
        continue;
      }

      // if (str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
      // {
      //   return 0;
      // }

      startPos = i;
      break;
    }

    int negative = false;
    if (str[startPos] == '-')
    {
      negative = true;
      ++startPos;
    }
    else if (str[startPos] == '+')
    {
      negative = false;
      ++startPos;
    }

    for (int i = startPos; i < length; ++i)
    {
      if (str[i] >= '0' && str[i] <= '9')
      {
        digit = str[i] - '0';
        if (negative)
        {
          digit = -digit;
          if (result < std::numeric_limits<int>::min() / 10 ||
              (result == std::numeric_limits<int>::min() / 10 && digit < std::numeric_limits<int>::min() % 10))
          {
            return std::numeric_limits<int>::min();
          }
          result = result * 10 + digit;
        }
        else
        {
          if (result > std::numeric_limits<int>::max() / 10 ||
              (result == std::numeric_limits<int>::max() / 10 && digit > std::numeric_limits<int>::max() % 10))
          {
            return std::numeric_limits<int>::max();
          }
          result = result * 10 + digit;
        }
      }
      else
      {
        break;
      }
    }

    return result;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
