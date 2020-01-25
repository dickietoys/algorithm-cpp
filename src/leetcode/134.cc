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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = canCompleteCircuit(gas, cost);

    cout << "result: " << result << endl;
  }

  int start_gas;
  int gas_size;
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    gas_size = gas.size();
    if (gas_size == 0)
    {
      return -1;
    }

    for (int i = 0; i < gas_size; ++i)
    {
      start_gas = i;
      if (Aux(gas, cost, gas[i] - cost[i], (i + 1) % gas_size))
      {
        return start_gas;
      }
    }

    return -1;
  }

  bool Aux(vector<int>& gas, vector<int>& cost, int gas_in_tank, int gas_pos)
  {
    if (gas_in_tank < 0)
    {
      return false;
    }

    if (gas_pos == start_gas)
    {
      return true;
    }

    return Aux(gas, cost, gas_in_tank + gas[gas_pos] - cost[gas_pos], (gas_pos + 1) % gas_size);
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
