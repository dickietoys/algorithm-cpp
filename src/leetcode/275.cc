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
    int left=0, len = citations.size(), right= len-1,  mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(citations[mid]== (len-mid)) return citations[mid];
        else if(citations[mid] > (len-mid)) right = mid - 1;
        else left = mid + 1;
    }
    return len - (right+1);
   */

  int hIndex(vector<int>& citations) {
    int citations_size = citations.size();
    if (citations_size <= 0)
    {
      return 0;
    }
    int left = 0;
    int right = citations_size - 1;
    int mid = 0;
    while (left <= right)
    {
      mid = (left + right) / 2;
      if (citations[mid] == (citations_size - mid))
      {
        return citations[mid];
      }
      else if (citations[mid] > (citations_size - mid))
      {
        right = mid - 1;
      }
      else
      {
        left = left + 1;
      }
    }

    return citations_size - (right + 1);
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
