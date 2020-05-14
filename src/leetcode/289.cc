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
    According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

    Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

    Example:

    Input:
    [
    [0,1,0],
    [0,0,1],
    [1,1,1],
    [0,0,0]
    ]
    Output:
    [
    [0,0,0],
    [1,0,1],
    [0,1,1],
    [0,1,0]
    ]
    Follow up:

    Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

   */

  void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size();
    if (rows <= 0)
    {
      return;
    }

    int cols = board[0].size();
    if (cols <= 0)
    {
      return;
    }

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (board[i][j] == 1)
        {
          can_become_dead(board, i, j);
        }
        else
        {
          can_become_live(board, i, j);
        }
      }
    }

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (board[i][j] == 11)
        {
          board[i][j] = 0;
        }
        else if(board[i][j] == 10)
        {
          board[i][j] = 1;
        }
      }
    }
  }

  void count_live_dead(vector<vector<int>>& board, int xpos, int ypos, int &dead, int &live)
  {
    int rows = board.size();
    int cols = board[0].size();
    if (xpos < 0 || xpos >= rows || ypos < 0 || ypos >= cols)
    {
      return;
    }

    if (board[xpos][ypos] == 1 || board[xpos][ypos] == 11)
    {
      ++live;
    }
    else
    {
      ++dead;
    }
  }

  void can_become_live(vector<vector<int>>& board, int xpos, int ypos)
  {
    int dead_count = 0;
    int live_count = 0;
    count_live_dead(board, xpos - 1, ypos - 1, dead_count, live_count);
    count_live_dead(board, xpos - 1, ypos, dead_count, live_count);
    count_live_dead(board, xpos - 1, ypos + 1, dead_count, live_count);
    count_live_dead(board, xpos + 1, ypos - 1, dead_count, live_count);
    count_live_dead(board, xpos + 1, ypos, dead_count, live_count);
    count_live_dead(board, xpos + 1, ypos + 1, dead_count, live_count);
    count_live_dead(board, xpos, ypos - 1, dead_count, live_count);
    count_live_dead(board, xpos, ypos + 1, dead_count, live_count);
    if (live_count == 3)
    {
      board[xpos][ypos] = 10;
    }
  }

  void can_become_dead(vector<vector<int>>& board, int xpos, int ypos)
  {
    int dead_count = 0;
    int live_count = 0;
    count_live_dead(board, xpos - 1, ypos - 1, dead_count, live_count);
    count_live_dead(board, xpos - 1, ypos, dead_count, live_count);
    count_live_dead(board, xpos - 1, ypos + 1, dead_count, live_count);
    count_live_dead(board, xpos + 1, ypos - 1, dead_count, live_count);
    count_live_dead(board, xpos + 1, ypos, dead_count, live_count);
    count_live_dead(board, xpos + 1, ypos + 1, dead_count, live_count);
    count_live_dead(board, xpos, ypos - 1, dead_count, live_count);
    count_live_dead(board, xpos, ypos + 1, dead_count, live_count);

    if (live_count < 2 || live_count > 3)
    {
      board[xpos][ypos] = 11;
    }
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
