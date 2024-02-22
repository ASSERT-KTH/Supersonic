#include <cstdio>

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
  int heap_sort(int *array, int len) {
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
  Heap heap;
  while (true) {
    std::string input;
    std::cin >> input;
    if (input == "end")
      break;
    if (input == "insert") {
      int insert_data;
      std::cin >> insert_data;
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
  return 0;
}