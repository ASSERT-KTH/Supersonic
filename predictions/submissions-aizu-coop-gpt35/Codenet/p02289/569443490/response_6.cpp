#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

class Heap {
public:
  Heap() {
    array = nullptr;
    n = 0;
  }

  ~Heap() {
    delete[] array;
  }

  void insert(int data) {
    if (n == 0) {
      array = new int[1];
      array[0] = data;
    } else {
      int* newArray = new int[n + 1];
      int left = 0, right = n;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == data) {
          left = mid + 1;
          right = mid;
          break;
        } else if (array[mid] < data) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      for (int i = 0; i < left; i++) {
        newArray[i] = array[i];
      }
      newArray[left] = data;
      for (int i = left; i <= n; i++) {
        newArray[i + 1] = array[i];
      }
      delete[] array;
      array = newArray;
    }
    n++;
  }

  void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (son + 1 <= end && array[son] < array[son + 1]) {
        son++;
      }
      if (array[dad] > array[son]) {
        return;
      } else {
        swap(array[son], array[dad]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }

  int heap_sort() {
    int i;
    swap(array[0], array[n - 1]);
    max_heapify(0, n - 2);
    return array[n - 1];
  }

  int extract() {
    int ret = heap_sort();
    n--;
    return ret;
  }

private:
  int* array;
  int n;
};

int main() {
  int insert_data;
  char buf[22];
  Heap heap;
  while (true) {
    fgets(buf, 22, stdin);
    if (buf[2] == 'd') {
      break;
    }
    if (buf[0] == 'i') {
      insert_data = 0;
      for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] >= '0' && buf[i] <= '9') {
          insert_data = 10 * insert_data + (buf[i] - '0');
        }
      }
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
}