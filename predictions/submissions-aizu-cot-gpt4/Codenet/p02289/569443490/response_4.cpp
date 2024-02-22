#include <stdio.h>

class Heap {
public:
  int array[2000000];
  int n = 0;

  void insert(int data) {
    int tmp = n;
    array[tmp] = data;
    int parent = (tmp - 1) / 2;
    while (tmp != 0 && array[tmp] > array[parent]) {
      std::swap(array[tmp], array[parent]);
      tmp = parent;
      parent = (tmp - 1) / 2;
    }
    n++;
  }

  int extract() {
    std::swap(array[0], array[n - 1]);
    int dad = 0;
    int son = dad * 2 + 1;
    while (son <= n - 2) {
      if (son + 1 <= n - 2 && array[son] < array[son + 1])
        son++;
      if (array[dad] > array[son])
        break;
      std::swap(array[son], array[dad]);
      dad = son;
      son = dad * 2 + 1;
    }
    n--;
    return array[n];
  }
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
      for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] >= '0' && buf[i] <= '9') {
          insert_data = (insert_data << 3) + (insert_data << 1) + (buf[i] - '0');
        }
      }
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
}