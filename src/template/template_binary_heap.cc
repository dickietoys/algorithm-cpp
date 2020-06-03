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

class BinaryHeap
{
 private:
  void Down(int pos)
  {
    int data_size = data_.size();
    int hole_pos = LeftPos(pos);
    while (hole_pos <= data_size - 1)
    {
      if (hole_pos != data_size - 1 && data_[hole_pos] > data_[hole_pos + 1])
      {
        ++hole_pos;
      }

      if (data_[pos] > data_[hole_pos])
      {
        std::swap(data_[pos], data_[hole_pos]);
        pos = hole_pos;
        hole_pos = LeftPos(pos);
      }
      else
      {
        break;
      }
    }
  }

  void Up(int pos)
  {
    int hole_pos = ParentPos(pos);
    while (data_[pos] < data_[hole_pos])
    {
      std::swap(data_[pos], data_[hole_pos]);
      pos = hole_pos;
      hole_pos = ParentPos(pos);
    }
  }

  int ParentPos(int pos)
  {
    return (pos - 1) / 2;
  }

  int LeftPos(int pos)
  {
    return pos * 2 + 1;
  }

  int RightPos(int pos)
  {
    return pos * 2 + 2;
  }

 public:
  vector<int> data_;
  BinaryHeap()
  {}

  BinaryHeap(vector<int> &data)
      : data_(data)
  {}

  void MakeBinaryHeap()
  {
    int data_size = data_.size();
    int pos = data_size / 2 - 1;
    while (pos >= 0)
    {
      Down(pos--);
    }
  }

  void Delete(int pos)
  {

  }

  void Decrease(int pos, int value)
  {

  }

  int Top()
  {
    return data_.front();
  }

  bool Empty()
  {
    return data_.empty();
  }

  void Pop()
  {
    std::swap(data_.front(), data_.back());
    data_.pop_back();
    Down(0);
  }

  void Insert(int value)
  {
    data_.push_back(value);
    Up(data_.size() - 1);
  }

  vector<int> ShowRawData()
  {
    return data_;
  }

  vector<int> GetSortedArr()
  {
    vector<int> result;
    vector<int> tmp = data_;
    while (!this->Empty())
    {
      result.push_back(this->Top());
      this->Pop();
    }

    data_ = tmp;
    return result;
  }
};


class Solution {
 public:
  void RunTest()
  {
    BinaryHeap bh;
    bh.Insert(7);
    bh.Insert(5);
    bh.Insert(8);
    bh.Insert(1);
    bh.Insert(2);
    bh.Insert(4);
    bh.Insert(6);
    bh.Insert(3);
    Show(bh.ShowRawData());
    Show(bh.GetSortedArr());
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
