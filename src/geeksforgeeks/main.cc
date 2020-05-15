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
    Solve(8);
  }

  void ShowTours(vector<vector<int>> &tours)
  {
    for (vector<int> &rows : tours)
    {
      for (int v : rows)
      {
        cout << v << ",";
      }
      cout << endl;
    }
  }

  void Solve(int n)
  {
    index = 0;
    vector<vector<int>> tours(n, vector<int>(n, -1));
    vector<pair<int, int>> next_move =
        {
          {2, 1},
          {1, 2},
          {-1, 2},
          {-2, 1},
          {-2, -1},
          {-1, -2},
          {1, -2},
          {2, -1}
        };
    tours[0][0] = 0;

    if (Aux(tours, next_move, 1, 0, 0))
    {
      ShowTours(tours);
    }
    else
    {
      cout << "can't" << endl;
    }
  }

  bool IsValidPos(int xpos, int ypos, vector<vector<int>> &tours)
  {
    int rows = tours.size();
    int cols = tours[0].size();
    if (xpos < 0 || xpos >= rows || ypos < 0 || ypos >= cols || tours[xpos][ypos] != -1)
    {
      return false;
    }

    return true;
  }

  int index;
  bool Aux(vector<vector<int>> &tours,
           vector<pair<int, int>> &next_move,
           int step,
           int xpos,
           int ypos)
  {
    int rows = tours.size();
    int cols = tours[0].size();
    // cout << ++index << ":" << rows << ":" << cols << endl;
    if (step == rows * cols)
    {
      return true;
    }

    for (int i = 0; i < next_move.size(); ++i)
    {
      pair<int, int> &move = next_move[i];
      int next_xpos = xpos + move.first;
      int next_ypos = ypos + move.second;
      if (IsValidPos(next_xpos, next_ypos, tours))
      {
        tours[next_xpos][next_ypos] = step;
        if (Aux(tours, next_move, step + 1, next_xpos, next_ypos))
        {
          return true;
        }
        else
        {
          tours[next_xpos][next_ypos] = -1;
        }
      }
    }

    return false;
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
