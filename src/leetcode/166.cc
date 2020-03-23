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
#include <set>
#include <cmath>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
    string result = fractionToDecimal(1, 2);
    cout << "result: " << result << endl;
    result = fractionToDecimal(1, 3);
    cout << "result: " << result << endl;
  }

  string fractionToDecimal(int numerator, int denominator) {
    if (!numerator) {
      return "0";
    }
    string ans;
    if (numerator > 0 ^ denominator > 0) {
      ans += '-';
    }
    long n = labs(numerator), d = labs(denominator), r = n % d;
    ans += to_string(n / d);
    if (!r) {
      return ans;
    }
    ans += '.';
    unordered_map<long, int> rs;
    while (r) {
      if (rs.find(r) != rs.end()) {
        ans.insert(rs[r], "(");
        ans += ')';
        break;
      }
      rs[r] = ans.size();
      r *= 10;
      ans += to_string(r / d);
      r %= d;
    }
    return ans;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
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
