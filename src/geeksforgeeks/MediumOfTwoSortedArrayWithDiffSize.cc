#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    vector<int> ar1 = {900};
    vector<int> ar2 = {5, 8, 10, 20};
    double result = FindResult(ar1, ar2);
    cout << "result: " << result << endl;
    assert(result == 10.0);

    ar1 = {1, 3};
    ar2 = {2};
    result = FindResult(ar1, ar2);
    cout << "result: " << result << endl;
    assert(result == 2.0);

    ar1 = {1, 2};
    ar2 = {3, 4};
    result = FindResult(ar1, ar2);
    cout << "result: " << result << endl;
    assert(result == 2.5);
  }

  double brightFindResult(vector<int> &arr1, vector<int> &arr2)
  {

  }

  double FindResult(vector<int> &arr1, vector<int> &arr2)
  {
    int size1 = arr1.size();
    int size2 = arr2.size();
    int pos1 = 0;
    int pos2 = 0;
    int count = (size1 + size2) / 2;
    int medium1 = 0;
    int medium2 = 0;
    for (int i = 0; i <= count ; ++i)
    {
      medium1 = medium2;
      if (pos1 < size1 && pos2 < size2)
      {
        if (arr1[pos1] < arr2[pos2])
        {
          medium2 = arr1[pos1++];
        }
        else
        {
          medium2 = arr2[pos2++];
        }
      }
      else if (pos1 < size1)
      {
        medium2 = arr1[pos1++];
      }
      else
      {
        medium2 = arr2[pos2++];
      }
    }

    if ((size1 + size2) % 2 == 0)
    {
      // even
      return (medium1 + medium2) / 2.0;
    }
    else
    {
      //odd
      return medium2;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
