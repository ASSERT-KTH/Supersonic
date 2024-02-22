#include <algorithm>
#include <iostream>
#include <vector>

class Heap {
public:
  Heap() {
    n = 0;
  }

  void insert(int data) {
    array.push_back(data);
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

  int extract() {
    int len = n;
    std::swap(array[0], array[len - 1]);
    max_heapify(0, len - 2);
    n--;
    return array[len - 1];
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
    if (buf[2] == 'd') {
      break;
    }
    if (buf[0] == 'i') {
      sscanf(buf, "i %d", &insert_data);
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }

  return 0;
}