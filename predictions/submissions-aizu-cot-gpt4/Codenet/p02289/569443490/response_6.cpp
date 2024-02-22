#include <iostream>
#include <stdio.h>
using namespace std;
class Heap {
public:
  Heap() {
    array = nullptr;
    n = 0;
  }
  void insert(int data) {
    array = (int*)realloc(array, (n + 1) * sizeof(int));
    array[n] = data;
    int tmp = n;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) / 2]) {
      int temp = array[tmp];
      array[tmp] = array[(tmp - 1) / 2];
      array[(tmp - 1) / 2] = temp;
      tmp = (tmp - 1) / 2;
    }
    ++n;
  }
  void max_heapify(int *array, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (array[son] < array[son + 1] && son + 1 <= end)
        ++son;
      if (array[dad] > array[son])
        return;
      else {
        int temp = array[son];
        array[son] = array[dad];
        array[dad] = temp;
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }
  int heap_sort(int *array, int len) {
    int temp = array[0];
    array[0] = array[len - 1];
    array[len - 1] = temp;
    max_heapify(array, 0, len - 2);
    return array[len - 1];
  }
  int extract() {
    int ret = heap_sort(array, n);
    --n;
    return ret;
  }

private:
  int *array;
  int n;
};
int main() {
  int insert_data;
  char buf[22];
  Heap heap;
  while (true) {
    fgets(buf, 22, stdin);
    if (buf[2] == 'd')
      break;
    if (buf[0] == 'i') {
      insert_data = 0;
      for (int i = 0; buf[i] != '\0'; ++i) {
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