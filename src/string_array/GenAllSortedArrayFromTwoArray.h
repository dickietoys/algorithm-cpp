#ifndef GEN_ALL_SORTED_ARRAY_FROM_TWO_ARRAY_H
#define GEN_ALL_SORTED_ARRAY_FROM_TWO_ARRAY_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class GenAllSortedArrayFromTwoArray : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================GenAllSortedArrayFromTwoArray====================" << endl;
    vector<int> arr1 = {10, 15, 25};
    vector<int> arr2 = {1, 5, 20, 30};
    GenAll(arr1, arr2);
    cout << "=================GenAllSortedArrayFromTwoArray====================" << endl;
  }

  void GenAll(const vector<int> &arr1, const vector<int> &arr2)
  {
    vector<int> buffer(arr1.size() + arr2.size(), 0);
    cout << "buffer.size: " << buffer.size() << endl;
    GenAllAux(arr1, 0, arr2, 0, buffer, 0, true);
  }

  void GenAllAux(const vector<int> &arr1,
                 int pos1,
                 const vector<int> &arr2,
                 int pos2,
                 vector<int> &buffer,
                 int bufferSize,
                 bool chose1)
  {
    if (chose1)
    {
      for (size_t i = pos1; i < arr1.size(); ++i)
      {
        if (bufferSize == 0)
        {
          buffer[0] = arr1[i];
          GenAllAux(arr1, i+1, arr2, pos2, buffer, bufferSize + 1, false);
        }
        else
        {
          if (arr1[i] > buffer[bufferSize-1])
          {
            buffer[bufferSize] = arr1[i];
            GenAllAux(arr1, i+1, arr2, pos2, buffer, bufferSize + 1, false);
          }
        }
      }
    }
    else
    {
      for (size_t i = pos2; i < arr2.size(); ++i)
      {
        if (arr2[i] > buffer[bufferSize-1])
        {
          buffer[bufferSize] = arr2[i];
          Show(buffer, bufferSize+1);
          GenAllAux(arr1, pos1, arr2, i+1, buffer, bufferSize + 1, true);
        }
      }
    }
  }

  void Show(const vector<int> &arr)
  {
    for (size_t i = 0; i < arr.size(); ++i)
    {
      cout << arr[i] << ", ";
    }

    cout << endl;
  }

  void Show(const vector<int> &arr, int arrSize)
  {
    for (int i = 0; i < arrSize; ++i)
    {
      cout << arr[i] << ", ";
    }

    cout << endl;
  }

};

#endif
