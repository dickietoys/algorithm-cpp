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
    NextGreaterElement({11, 13, 21, 3});
  }

  void NextGreaterElement(vector<int> arr)
  {
    stack<int> st;
    // st.push(arr[0]);
    for (int i = 0; i < arr.size(); ++i)
    {
      while (!st.empty() && arr[i] > st.top())
      {
        cout << st.top() << " --> " << arr[i] << endl;
        st.pop();
      }

      st.push(arr[i]);
    }
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
