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

  /*
    A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each.


    Input: citations = [3,0,6,1,5]
    Output: 3
    Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
    received 3, 0, 6, 1, 5 citations respectively.
    Since the researcher has 3 papers with at least 3 citations each and the remaining
    two with no more than 3 citations each, her h-index is 3.


   */

  int hIndex(vector<int>& citations) {
    if (citations.size() <= 0)
    {
      return 0;
    }

    vector<int> bucket(citations.size() + 1, 0);
    for (int i = 0; i < citations.size(); ++i)
    {
      if (citations[i] >= citations.size())
      {
        bucket[citations.size()]++;
      }
      else
      {
        bucket[citations[i]]++;
      }
    }

    int count = 0;
    for (int i = citations.size(); i >= 0; --i)
    {
      count += bucket[i];
      if (count >= i)
      {
        return i;
      }
    }

    return 0;
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
