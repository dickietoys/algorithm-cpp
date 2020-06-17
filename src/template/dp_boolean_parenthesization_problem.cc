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
#include <queue>
#include <list>

using namespace std;


class Solution {
 public:
  void RunTest()
  {
    cout << "==================bruteforce======================" << endl;
    // 2
    int result = BooleanParenthesizationProblemRecur({true, false, true}, "^&");
    cout << "BooleanParenthesizationProblemRecur: " << result << endl;
    // 2
    result = BooleanParenthesizationProblemRecur({true, false, false}, "^|");
    cout << "BooleanParenthesizationProblemRecur: " << result << endl;
    // 4
    result = BooleanParenthesizationProblemRecur({true, true, false, true}, "|&^");
    cout << "BooleanParenthesizationProblemRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = BooleanParenthesizationProblemDp({true, false, true}, "^&");
    cout << "BooleanParenthesizationProblemDp: " << result << endl;
    result = BooleanParenthesizationProblemDp({true, false, false}, "^|");
    cout << "BooleanParenthesizationProblemDp: " << result << endl;
    result = BooleanParenthesizationProblemDp({true, true, false, true}, "|&^");
    cout << "BooleanParenthesizationProblemDp: " << result << endl;
  }

  bool CalcOp(bool lhs, bool rhs, char prev_op)
  {
    switch (prev_op)
    {
      case '^':
        return lhs ^ rhs;
      case '|':
        return lhs | rhs;
      case '&':
        return lhs & rhs;
      default:
        return false;
    }
  }

  int count_ = 0;

  void BooleanParenthesizationProblemRecurAux(vector<bool> symbols,
                                              int s_pos,
                                              string operators,
                                              int o_pos,
                                              bool prev_symbols,
                                              char prev_op)
  {
    if (s_pos >= symbols.size() || o_pos >= operators.size())
    {
      if (prev_symbols)
      {
        ++count_;
      }

      return;
    }

    bool cur_symbol = symbols[s_pos];
    bool cur_op = operators[o_pos];
    cur_symbol = CalcOp(prev_symbols, cur_op, prev_op);
    BooleanParenthesizationProblemRecurAux(symbols,
                                           cur_op + 1,
                                           operators,
                                           o_pos,
                                           prev_op)
  }

  int BooleanParenthesizationProblemRecur(vector<bool> symbols, string operators)
  {
    BooleanParenthesizationProblemRecurAux(symbols, operators, 0, true, '&');
    return count_;
  }

  int BooleanParenthesizationProblemDp(vector<bool> symbols, string operators)
  {
    return 0;
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
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
