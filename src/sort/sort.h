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
      for (size_t j = 0; j < data.size() - i -1 ; ++j)
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
    int currentSize = data.size();
    for (int i = currentSize / 2 - 1; i >= 0; --i)
    {
      percDown(data, i, currentSize);
    }

    for (size_t i = 0; i < data.size(); ++i)
    {
      swap(data[0], data[currentSize-1]);
      --currentSize;
      percDown(data, 0, currentSize);
    }

    return data;
  }

  vector<T> mergeSort(vector<T> data)
  {
    vector<T> tmp(data.size());
    mergeSort(tmp, data, 0, data.size() - 1);

    return data;
  }

  vector<T> quickSort(vector<T> data)
  {
    quickSort(data, 0, data.size() - 1);
    return data;
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
    cout << "===========after heapsort===============" << endl;
    sorted_data = heapSort(unsorted_data);
    printVector(sorted_data);
    cout << "===========after mergesort===============" << endl;
    sorted_data = mergeSort(unsorted_data);
    printVector(sorted_data);
    cout << "===========after quicksort===============" << endl;
    sorted_data = quickSort(unsorted_data);
    printVector(sorted_data);
  }

 private:
  int leftChild(int i)
  {
    return 2 * i + 1;
  }

  void percDown(vector<T> &data, int hole,int currentSize)
  {
    T tmp = data[hole];
    int child;
    for (; hole * 2 + 1 < currentSize; hole = child)
    {
      child = hole * 2 + 1;
      if ((child + 1 < currentSize) && data[child+1] > data[child])
      {
        ++child;
      }

      if (tmp < data[child])
      {
        data[hole] = data[child];
      }
      else
      {
        break;
      }
    }
    data[hole] = tmp;
  }

  void mergeSort(vector<T> &tmp, vector<T> &data, int leftPos, int rightPos)
  {

    if (leftPos < rightPos)
    {
      int middle = (leftPos+rightPos) / 2;
      mergeSort(tmp, data, leftPos, middle);
      mergeSort(tmp, data, middle + 1, rightPos);

      int tmpPos = leftPos;
      int currentLeftPos = leftPos;
      int currentRightPos = middle + 1;
      while (currentLeftPos <= middle && currentRightPos <= rightPos)
      {
        if (data[currentLeftPos] >= data[currentRightPos])
        {
          tmp[tmpPos++] = data[currentRightPos++];
        }
        else
        {
          tmp[tmpPos++] = data[currentLeftPos++];
        }
      }

      while (currentLeftPos <= middle)
      {
        tmp[tmpPos++] = data[currentLeftPos++];
      }

      while (currentRightPos <= rightPos)
      {
        tmp[tmpPos++] = data[currentRightPos++];
      }

      for (int i = leftPos; i <= rightPos; ++i)
      {
        data[i] = tmp[i];
      }
    }
  }

  void quickSort(vector<T> &data, int leftPos, int rightPos)
  {
    if (leftPos >= rightPos)
    {
      return;
    }

    const T &pivot = data[rightPos];
    int i = leftPos;
    int j = rightPos-1;
    while (i <= j)
    {
      if (data[i] < pivot)
      {
        ++i;
        continue;
      }

      if (data[j] > pivot)
      {
        --j;
        continue;
      }

      swap(data[i], data[j]);
    }

    swap(data[i], data[rightPos]);
    quickSort(data, leftPos, i - 1);
    quickSort(data, i+1, rightPos);
  }
};

#endif
