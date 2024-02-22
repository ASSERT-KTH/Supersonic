#include <iostream>
#include <stdio.h>

class Heap {
public:
  Heap() {
    array = new int[2000000];
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
      if (son + 1 <= end && array[son] < array[son + 1])
        son++;
      if (array[dad] > array[son])
        return;
      else {
        std::swap(array[son], array[dad]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }
  
  int extract() {
    int maxElement = array[0];
    array[0] = array[n - 1];
    n--;
    max_heapify(array, 0, n - 1);
    return maxElement;
  }

private:
  int *array;
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
      sscanf(buf, "i %d", &insert_data);
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
  
  return 0;
}