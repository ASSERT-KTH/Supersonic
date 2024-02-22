#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

class Heap {
public:
  Heap() = default;

  void insert(int data) {
    array.push_back(data);
    int tmp = array.size() - 1;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) / 2]) {
      std::swap(array[tmp], array[(tmp - 1) / 2]);
      tmp = (tmp - 1) / 2;
    }
  }

  void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son < end) {
      if (son + 1 < end && array[son] < array[son + 1])
        son++;
      if (array[dad] > array[son])
        return;
      std::swap(array[son], array[dad]);
      dad = son;
      son = dad * 2 + 1;
    }
  }

  int heap_sort(int len) {
    int ret = array[0];
    array[0] = array[len - 1];
    max_heapify(0, len - 1);
    return ret;
  }

  int extract() {
    int ret = heap_sort(array.size());
    array.pop_back();
    return ret;
  }

private:
  std::vector<int> array;
};

int main() {
  int insert_data;
  std::string input;
  Heap heap;
  while (true) {
    std::cin >> input;
    if (input[2] == 'd')
      break;
    if (input[0] == 'i') {
      std::stringstream ss(input.substr(7));
      ss >> insert_data;
      heap.insert(insert_data);
    } else {
      std::cout << heap.extract() << "\n";
    }
  }
  return 0;
}