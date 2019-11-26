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
    double result = 0;
    result = findMedianSortedArrays(ar1, ar2);
    cout << "result: " << result << endl;
    assert(result == 10.0);

    ar1 = {1, 3};
    ar2 = {2};
    result = findMedianSortedArrays(ar1, ar2);
    cout << "result: " << result << endl;
    assert(result == 2.0);

    ar1 = {1, 2};
    ar2 = {3, 4};
    result = findMedianSortedArrays(ar1, ar2);
    cout << "result: " << result << endl;
    assert(result == 2.5);

    ar1 = {};
    ar2 = {2, 3};
    result = findMedianSortedArrays(ar1, ar2);
    cout << "result: " << result << endl;
    assert(result == 2.5);
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int size1 = nums1.size();
    int size2 = nums2.size();
    if (size1 > size2)
    {
      std::swap(size1, size2);
      std::swap(nums1, nums2);
    }

    int medium1 = 0;
    int medium2 = 0;
    int minIndex = 0;
    int maxIndex = size1;
    int leftSize1 = 0;
    int leftSize2 = 0;
    while (minIndex <= maxIndex)
    {
      leftSize1 = (minIndex + maxIndex) / 2;
      leftSize2 = (size1 + size2 + 1) / 2 - leftSize1;
      if (leftSize1 > 0 && leftSize2 < size2 && nums1[leftSize1 - 1] > nums2[leftSize2])
      {
        maxIndex = leftSize1 - 1;
      }
      else if (leftSize1 < size1 && leftSize2 > 0 && nums2[leftSize2 - 1] > nums1[leftSize1])
      {
        minIndex = leftSize1 + 1;
      }
      else
      {
        if (leftSize1 == 0)
        {
          medium1 = nums2[leftSize2-1];
          break;
        }
        else if (leftSize2 == 0)
        {
          medium1 = nums1[leftSize1-1];
          break;
        }
        else
        {
          medium1 = std::max(nums1[leftSize1 - 1], nums2[leftSize2 - 1]);
          break;
        }
      }
    }

    if ((size1 + size2) % 2 == 1)
    {
      return medium1;
    }
    else
    {
      if (leftSize1 == size1)
      {
        medium2 = nums2[leftSize2];
      }
      else if (leftSize2 == size2)
      {
        medium2 = nums1[leftSize1];
      }
      else
      {
        medium2 = std::min(nums1[leftSize1], nums2[leftSize2]);
      }

      return (medium1 + medium2) / 2.0;
    }
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
