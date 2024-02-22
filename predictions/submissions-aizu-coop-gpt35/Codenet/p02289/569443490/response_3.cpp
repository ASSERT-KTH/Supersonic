#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

class Heap {
public:
  Heap() {
    array = new int[16];
    capacity = 16;
    n = 0;
  }

  ~Heap() {
    delete[] array;
  }

  void resize() {
    int newCapacity = capacity * 2;
    int *newArray = new int[newCapacity];
    std::copy(array, array + n, newArray);
    delete[] array;
    array = newArray;
    capacity = newCapacity;
  }

  void insert(int data) {
    if (n == capacity) {
      resize();
    }
    array[n] = data;
    int tmp = n;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) / 2]) {
      std::swap(array[tmp], array[(tmp - 1) / 2]);
      tmp = (tmp - 1) / 2;
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
        std::swap(array[son], array[dad]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }

  int heap_sort() {
    int i;
    std::swap(array[0], array[n - 1]);
    max_heapify(0, n - 2);
    return array[n - 1];
  }

  int extract() {
    int ret = heap_sort();
    n--;
    return ret;
  }

private:
  int *array;
  int capacity;
  int n;
};

int main() {
  char buf[22];
  Heap heap;
  while (true) {
    fgets(buf, 22, stdin);
    if (buf[2] == 'd')
      break;
    if (buf[0] == 'i') {
      int insert_data;
      sscanf(buf, "insert %d", &insert_data);
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
}