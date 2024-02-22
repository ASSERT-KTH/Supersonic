#include <algorithm>
#include <iostream>

class Heap {
public:
  Heap() {
    array = new int[2000000];
    n = 0;
  }
  void insert(int data) {
    array[n++] = data;
    std::push_heap(array, array + n);
  }
  void max_heapify(int *array, int start, int end) {
    std::make_heap(array + start, array + end + 1);
  }
  int heap_sort(int *array, int len) {
    std::sort_heap(array, array + len);
    return array[len - 1];
  }
  int extract() {
    std::pop_heap(array, array + n--);
    return array[n];
  }

private:
  int *array;
  int n;
};

int main() {
  Heap heap;
  while (true) {
    std::string command;
    std::cin >> command;
    if (command == "end")
      break;
    if (command == "insert") {
      int insert_data;
      std::cin >> insert_data;
      heap.insert(insert_data);
    } else {
      std::cout << heap.extract() << std::endl;
    }
  }
  return 0;
}