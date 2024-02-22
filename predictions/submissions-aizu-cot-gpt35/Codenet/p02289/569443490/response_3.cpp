#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

class Heap {
public:
  Heap(int size) {
    array = new int[size];
    n = 0;
  }

  void insert(int data) {
    array[n] = data;
    int tmp = n;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) / 2]) {
      std::swap(array[tmp], array[(tmp - 1) / 2]);
      tmp = (tmp - 1) / 2;
    }
    n++;
  }

  void max_heapify(int *array, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (son + 1 <= end && array[son] < array[son + 1]) {
        son++;
      }
      if (array[dad] > array[son]) {
        return;
      } else {
        swap(array[dad], array[son]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }

  int heap_sort(int *array, int len) {
    swap(array[0], array[len - 1]);
    max_heapify(array, 0, len - 2);
    return array[len - 1];
  }

  int extract() {
    int ret = heap_sort(array, n);
    n--;
    return ret;
  }

private:
  int *array;
  int n;
};

int main() {
  int insert_data;
  char buf[22];
  Heap heap(1000); // Adjust the size based on the expected number of elements
  while (true) {
    fgets(buf, 22, stdin);
    if (buf[2] == 'd') {
      break;
    }
    if (buf[0] == 'i') {
      insert_data = 0;
      sscanf(buf, "insert %d", &insert_data);
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
}