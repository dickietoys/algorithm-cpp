#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string input = "hello";
    string needle = "ll";
    int result = strStr(input, needle);
    cout << "result: " << result << endl;
    assert(result == 2);

    input = "aaaaa";
    needle = "bba";
    result = strStr(input, needle);
    cout << "result: " << result << endl;
    assert(result == -1);
  }

  int strStr(string haystack, string needle) {
    int size1 = haystack.size();
    int size2 = needle.size();
    for (int i = 0; i < size1; ++i)
    {
      int j = i;
      int k = 0;
      while (j < size1 && k < size2)
      {
        if (haystack[j] == needle[k])
        {
          ++k;
          ++j;
        }
        else
        {
          break;
        }
      }

      if (k == size2 - 1)
      {
        return j;
      }
    }

    return -1;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
