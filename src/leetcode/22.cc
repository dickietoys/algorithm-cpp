#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

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
    int n = 3;
    vector<string> result;

    result = generateParenthesis(n);
    Show(result);
  }

  void Show(vector<string> result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << endl;
    }
  }

  vector<string> generateParenthesis(int n) {
    stack<int> st;
    vector<string> result;
    string s = "";
    Aux(n, 0, 0, s, result);

    return result;
  }

  void Aux(int n, int leftSize, int rightSize, string s, vector<string> &result)
  {
    if (s.size() == n * 2)
    {
      result.push_back(s);
      return;
    }

    if (leftSize < n)
    {
      Aux(n, leftSize + 1, rightSize, s + "(", result);
    }

    if (rightSize < leftSize)
    {
      Aux(n, leftSize, rightSize + 1, s + ")", result);
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
