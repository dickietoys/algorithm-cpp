#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string s;
    int result;

    // s = "MCMIV";
    s = "MDCDXCIV";

    result = CalcResult(s);
    cout << "result: " << result << endl;
  }

  int CalcResult(string s)
  {
    int length = s.size();
    int value = 0;
    for (int i = 0; i < length; ++i)
    {
      int curValue = Value(s[i]);
      if (i + 1 < length)
      {
        int nextValue = Value(s[i+1]);
        if (curValue >= nextValue)
        {
          value += curValue;
        }
        else
        {
          value = nextValue - curValue + value;
          ++i;
        }
      }
      else
      {
        value += curValue;
      }
    }

    return value;
  }

  int Value(char r)
  {
    if (r == 'I')
      return 1;
    if (r == 'V')
      return 5;
    if (r == 'X')
      return 10;
    if (r == 'L')
      return 50;
    if (r == 'C')
      return 100;
    if (r == 'D')
      return 500;
    if (r == 'M')
      return 1000;

    return -1;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
