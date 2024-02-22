#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
class Heap {
public:
  Heap() {
    array = new int[2000000];
    n = 0;
  }
  void insert(int data) {
    array[n] = data;
    int tmp = n, parent;
    while (tmp != 0) {
      parent = (tmp - 1) / 2;
      if(array[tmp] <= array[parent]) break;
      std::swap(array[tmp], array[parent]);
      tmp = parent;
    }
    n++;
  }
  void max_heapify(int *array, int start, int end) {
    int dad = start;
    int son;
    while (dad * 2 + 1 <= end) {
      son = dad * 2 + 1;
      if (array[son] < array[son + 1] && son + 1 <= end)
        son++;
      if (array[dad] > array[son])
        return;
      else {
        std::swap(array[son], array[dad]);
        dad = son;
      }
    }
  }
  int heap_sort(int *array, int len) {
    if(array[0] < array[len - 1])
      std::swap(array[0], array[len - 1]);
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
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int insert_data;
  char buf[22];
  Heap heap;
  while (true) {
    fgets(buf, 22, stdin);
    if (buf[2] == 'd')
      break;
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