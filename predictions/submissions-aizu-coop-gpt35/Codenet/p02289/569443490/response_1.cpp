#include <iostream>
#include <vector>

class Heap {
public:
  Heap() {
    array.reserve(2000000);
    n = 0;
  }
  void insert(int data) {
    array.push_back(data);
    for (int i = n; i > 0 && array[i] > array[(i - 1) / 2]; i = (i - 1) / 2) {
      std::swap(array[i], array[(i - 1) / 2]);
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
        std::swap(array[dad], array[son]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }
  int heap_sort(int len) {
    int ret = array[0];
    array[0] = array[len - 1];
    max_heapify(0, len - 2);
    return ret;
  }
  int extract() {
    int ret = heap_sort(n);
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
      insert_data = std::stoi(buf + 7); // Parse integer directly from input string
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
}