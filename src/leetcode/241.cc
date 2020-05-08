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

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
  }

  vector<int> diffWaysToCompute(string input) {
    vector<int> result;
    int input_size = input.size();
    for (int i = 0; i < input_size; ++i)
    {
      char cur = input[i];
      if (cur == '+' || cur == '-' || cur == '*')
      {
        vector<int> result1 = diffWaysToCompute(input.substr(0, i));
        vector<int> result2 = diffWaysToCompute(input.substr(i+1));
        for (int val1 : result1)
        {
          for (int val2 : result2)
          {
            switch(cur)
            {
              case '+' :
                result.push_back(val1 + val2);
                break;
              case '-' :
                result.push_back(val1 - val2);
                break;
              case '*' :
                result.push_back(val1 * val2);
                break;
            }
          }
        }
      }
    }
    if (result.empty())
    {
      result.push_back(std::stoi(input));
    }

    return result;
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
