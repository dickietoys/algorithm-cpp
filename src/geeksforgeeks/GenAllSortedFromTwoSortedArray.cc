#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================MinPartition=========================" << endl;
    vector<int> arr1 = {10, 15, 25};
    vector<int> arr2 = {5, 20, 30};
    BruteResult(arr1, arr2);
    cout << "=========================MinPartition=========================" << endl;
  }

  void BruteResult(vector<int> &arr1, vector<int> &arr2)
  {
    BruteResultAux(arr1, 0, arr2, 0, true, {});
  }

  void BruteResultAux(vector<int> &arr1, int pos1, vector<int> &arr2, int pos2, bool chose1, vector<int> buffer)
  {
    if (chose1)
    {
      for (size_t i = pos1; i < arr1.size(); ++i)
      {
        vector<int> tmp = buffer;
        if (buffer.size() == 0 || arr1[i] > buffer[buffer.size() - 1])
        {
          tmp.push_back(arr1[i]);
          BruteResultAux(arr1, i+1, arr2, pos1, false, tmp);
        }
      }
    }
    else
    {
      for (size_t i = pos2; i < arr2.size(); ++i)
      {
        vector<int> tmp = buffer;
        if (arr2[i] > buffer[buffer.size() - 1])
        {
          tmp.push_back(arr2[i]);
          for (size_t j = 0; j < tmp.size(); ++j)
          {
            cout << tmp[j] << ", ";
          }
          cout << endl;
          BruteResultAux(arr1, pos1, arr2, i+1, true, tmp);
        }
      }
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
