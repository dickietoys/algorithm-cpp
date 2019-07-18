#ifndef SORT_H_
#define SORT_H_

#include <vector>
#include <iostream>

using namespace std;

template<class T>
class SortBox{
 public:
  SortBox(){}

  vector<T> bubleSort(vector<T> data)
  {
    for (size_t i = 0; i < data.size(); ++i)
    {
      for (size_t j = 0; j < data.size() - i; ++j)
      {
        if (data[j] > data[j+1])
        {
          swap(data[j], data[j+1]);
        }
      }
    }

    return data;
  }

  vector<T> insertSort(vector<T> data)
  {
    for (size_t i = 1; i < data.size(); ++i)
    {
      T tmp = data[i];
      size_t j;
      for (j = i; j > 0 && tmp < data[j - 1]; --j)
      {
        data[j] = data[j-1];
      }
      data[j] = tmp;
    }

    return data;
  }

  vector<T> selectSort(vector<T> data)
  {
    for (size_t i = 0; i < data.size(); ++i)
    {
      for (size_t j = i+1; j < data.size(); ++j)
      {
        if (data[i] > data[j])
        {
          swap(data[i], data[j]);
        }
      }
    }

    return data;
  }

  vector<T> heapSort(vector<T> data)
  {
    for (size_t i = data.size() / 2 - 1; i >= 0; --i)
    {
      percDown(data, i, data.size());
    }
  }

  vector<T> quickSort(vector<T> data)
  {

  }

  void printVector(vector<T> &data)
  {
    for(size_t i = 0; i < data.size(); ++i)
    {
      cout << data[i] << ",  ";
    }

    cout << endl;
  }

  void doAllSort(vector<T> &unsorted_data)
  {
    vector<int> sorted_data;
    cout << "===========unsorted order===============" << endl;
    printVector(unsorted_data);
    cout << "===========after bublesort===============" << endl;
    sorted_data = bubleSort(unsorted_data);
    printVector(sorted_data);
    cout << "===========after insertsort===============" << endl;
    sorted_data = insertSort(unsorted_data);
    printVector(sorted_data);
    cout << "===========after selectsort===============" << endl;
    sorted_data = selectSort(unsorted_data);
    printVector(sorted_data);
  }

 private:
  int leftChild(int i)
  {
    return 2 * i + 1;
  }

  void percDown(vector<T> &data, int currentPos,int currentSize)
  {
    int child;
    T tmp = data[currentPos];
    for (; (child = leftChild(currentPos)) < currentSize; currentPos = child)
    {
      if (child != currentSize - 1 && data[child] < data[child+1])
      {
        ++child;
      }

      if (tmp < data[child])
      {
        data[]
      }
    }
  }
};

#endif
