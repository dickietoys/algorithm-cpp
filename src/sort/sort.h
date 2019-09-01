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

  vector<T> bucketSort(vector<T> data)
  {
    vector<T> count_bucket(1000);
    for (size_t i = 0; i < data.size(); ++i)
    {
      count_bucket[data[i]] += 1;
    }

    vector<T> sorted_data(data.size());
    int index = 0;
    for (size_t i = 0; i < count_bucket.size(); ++i)
    {
      while (count_bucket[i] != 0)
      {
        sorted_data[index++] = i;
        --count_bucket[i];
      }
    }

    return sorted_data;
  }

  vector<string> bucketRadixSort(vector<string> arr, size_t stringLen)
  {
    int letterSize = 10;
    vector<vector<string>> buckets(letterSize);
    for (int i = stringLen - 1; i >= 0; --i)
    {
      for (string &item : arr)
      {
        buckets[item[i] - '0'].push_back(item);
      }

      int idx = 0;
      for (vector<string> &thisBucket : buckets)
      {
        for (string &item : thisBucket)
        {
          arr[idx++] = item;
        }
        thisBucket.clear();
      }
    }

    return arr;
  }

  vector<string> countingRadixSort(vector<string> arr, int stringLen)
  {
    int letterSize = 10;
    vector<string> buffer(arr.size());
    for (int i = stringLen - 1; i >= 0; --i)
    {
      vector<int> counter(letterSize + 1);
      for (string &str : arr)
      {
        ++counter[str[i] - '0' + 1];
      }

      for (int i = 1; i <= letterSize; ++i)
      {
        counter[i] += counter[i-1];
      }

      for (string &str : arr)
      {
        buffer[counter[str[i] - '0']++] = str;
      }

      std::swap(arr, buffer);
    }

    return arr;
  }

  vector<string> radixSort(vector<string> arr, int maxLen)
  {
    vector<vector<string>> wordsByLength(maxLen + 1);
    vector<vector<string>> buckets(10);
    for (string &str : arr)
    {
      wordsByLength[str.size()].push_back(str);
    }

    int idx = 0;
    for (vector<string> &wordList : wordsByLength)
    {
      for (string &str : wordList)
      {
        arr[idx++] = str;
      }
    }

    int startingIndex = arr.size();
    for (int pos = maxLen - 1; pos >= 0; --pos)
    {
      startingIndex -= wordsByLength[pos+1].size();
      for (int i = startingIndex; i < arr.size(); ++i)
      {
        buckets[arr[i][pos] - '0'].push_back(arr[i]);
      }

      int idx = startingIndex;
      for (vector<string> &thisBucket : buckets)
      {
        for (string &s : thisBucket)
        {
          arr[idx++] = s;
        }
        thisBucket.clear();
      }
    }

    return arr;
  }

  void printVector(vector<T> &data)
  {
    for(size_t i = 0; i < data.size(); ++i)
    {
      cout << data[i] << ",  ";
    }

    cout << endl;
  }

  void printVector(vector<string> &data)
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
    cout << "===========after bucketsort===============" << endl;
    sorted_data = bucketSort(unsorted_data);
    printVector(sorted_data);
    cout << "===========unsorted order===============" << endl;
    vector<string> unsorted_str = {"141", "215", "1141", "1090", "218", "172"};
    printVector(unsorted_str);
    vector<string> sorted_str;
    // cout << "===========after bucketRadixsort===============" << endl;
    // sorted_str = bucketRadixSort(unsorted_str, 3);
    // printVector(sorted_str);
    // cout << "===========after countingRadixsort===============" << endl;
    // sorted_str = countingRadixSort(unsorted_str, 3);
    // printVector(sorted_str);
    cout << "===========after radixsort===============" << endl;
    sorted_str = radixSort(unsorted_str, 4);
    printVector(sorted_str);
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
