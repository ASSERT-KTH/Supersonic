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
  
  int extract() {
    int ret = array[0];
    array[0] = array[n - 1];
    n--;
    max_heapify(array, 0, n - 1);
    return ret;
  }

private:
  int *array;
  int n;
};

int main() {
  int insert_data;
  Heap heap;
  while (true) {
    char command;
    scanf(" %c", &command);
    if (command == 'e') {
      printf("%d\n", heap.extract());
    } else if (command == 'i') {
      scanf("%d", &insert_data);
      heap.insert(insert_data);
    } else {
      break;
    }
  }
}