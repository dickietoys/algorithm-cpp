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
    int value = 123;
    int result = 0;
    result = reverse(value);
    cout << "result: " << result << endl;
    assert(result == 321);

    value = -123;
    result = reverse(value);
    cout << "result: " << result << endl;
    assert(result == -321);

    value = 120;
    result = reverse(value);
    cout << "result: " << result << endl;
    assert(result == 21);
  }

  int reverse(int x) {
    int result = 0;
    while (x)
    {
      int digist = x % 10;
      x = x / 10;
      if (result > std::numeric_limits<int>::max() / 10 ||
          (result == std::numeric_limits<int>::max() / 10 && digist > std::numeric_limits<int>::max() % 10))
      {
        return 0;
      }

      if (result < std::numeric_limits<int>::min() / 10 ||
          (result == std::numeric_limits<int>::min() / 10 && digist < std::numeric_limits<int>::min() % 10))
      {
        return 0;
      }

      result = result * 10 + digist;
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
