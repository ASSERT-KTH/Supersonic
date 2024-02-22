#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

class Heap {
public:
  Heap() {
    n = 0;
  }
  void insert(int data) {
    array.push_back(data);
    int tmp = n;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) >> 1]) {
      std::swap(array[tmp], array[(tmp - 1) >> 1]);
      tmp = (tmp - 1) >> 1;
    }
    n++;
  }
  void max_heapify(int *array, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (son + 1 <= end && array[son] < array[son + 1])
        son++;
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
    int i;
    std::swap(array[0], array[len - 1]);
    max_heapify(array, 0, len - 2);
    return array[len - 1];
  }
  int extract() {
    int ret = heap_sort(&array[0], n);
    n--;
    return ret;
  }

private:
  std::vector<int> array;
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
      insert_data = atoi(&buf[2]);
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
}