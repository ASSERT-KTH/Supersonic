#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
class Heap {
public:
  Heap() {
    capacity = 10;
    array = new int[capacity];
    n = 0;
  }
  void insert(int data) {
    if (n == capacity) {
      capacity *= 2;
      int* temp = new int[capacity];
      copy(array, array + n, temp);
      delete[] array;
      array = temp;
    }
    array[n] = data;
    int tmp = n;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) >> 1]) {
      std::swap(array[tmp], array[(tmp - 1) >> 1]);
      tmp = (tmp - 1) >> 1;
    }
    n++;
  }
  void max_heapify(int start, int end) {
    int dad = start;
    int son = (dad << 1) + 1;
    while (son <= end) {
      if (array[son] < array[son + 1] && son + 1 <= end)
        son++;
      if (array[dad] > array[son])
        return;
      else {
        swap(array[son], array[dad]);
        dad = son;
        son = (dad << 1) + 1;
      }
    }
  }
  int heap_sort(int len) {
    swap(array[0], array[len - 1]);
    max_heapify(0, len - 2);
    return array[len - 1];
  }
  int extract() {
    int ret = heap_sort(n);
    n--;
    return ret;
  }

private:
  int *array;
  int n;
  int capacity;
};
int main() {
  int insert_data;
  char buf[22];
  Heap heap;
  while (true) {
    char op;
    if (scanf("%c", &op) != 1)
      break;
    if (op == 'i') {
      if (scanf("%d", &insert_data) == 1)
        heap.insert(insert_data);
    } else if (op == 'e') {
      printf("%d\n", heap.extract());
    }
  }
}