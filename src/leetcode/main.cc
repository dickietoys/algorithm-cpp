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
    vector<int> nums = {2,1,3,2,1,7};
    cout << "----- SelectionSort" << endl;
    vector<int> result = SelectionSort(nums);
    Show(result);

    cout << "----- BubbleSort" << endl;
    result = BubbleSort(nums);
    Show(result);

    cout << "----- InsertionSort" << endl;
    result = InsertionSort(nums);
    Show(result);
  }

  vector<int> SelectionSort(vector<int> arr)
  {
    if (arr.empty())
    {
      return arr;
    }

    for (int i = 0; i < arr.size() - 1; ++i)
    {
      int min_pos = i;
      for (int j = i + 1; j < arr.size(); ++j)
      {
        if (arr[j] < arr[min_pos])
        {
          min_pos = j;
        }
      }
      std::swap(arr[min_pos], arr[i]);
    }

    return arr;
  }

  vector<int> BubbleSort(vector<int> arr)
  {
    if (arr.empty())
    {
      return arr;
    }

    for (int i = 0; i < arr.size(); ++i)
    {
      for (int j = 0; j < arr.size() - i - 1; ++j)
      {
        if (arr[j] > arr[j+1])
        {
          std::swap(arr[j], arr[j+1]);
        }
      }
    }

    return arr;
  }


  vector<int> InsertionSort(vector<int> arr)
  {
    if (arr.empty())
    {
      return arr;
    }

    for (int i = 1; i < arr.size(); ++i)
    {
      int j = i - 1;
      for (; j >= 0; --j)
      {
        if (arr[i] > arr[j])
        {
          break;
        }
      }
      std::swap(arr[i], arr[j]);
    }

    return arr;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
        cout << result[i][j] << ", " << endl;
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
