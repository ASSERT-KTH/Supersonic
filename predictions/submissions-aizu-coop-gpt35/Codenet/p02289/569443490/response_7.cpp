#include <algorithm>
#include <iostream>
#include <vector>

class Heap {
public:
  void insert(int data) {
    array.push_back(data);
    std::push_heap(array.begin(), array.end());
  }

  int extract() {
    std::pop_heap(array.begin(), array.end());
    int ret = array.back();
    array.pop_back();
    return ret;
  }

private:
  std::vector<int> array;
};

int main() {
  int insert_data;
  char buf[22];
  Heap heap;

  while (true) {
    std::cin.getline(buf, 22);
    if (buf[2] == 'd')
      break;
    if (buf[0] == 'i') {
      insert_data = std::stoi(buf + 2);
      heap.insert(insert_data);
    } else {
      std::cout << heap.extract() << std::endl;
    }
  }

  return 0;
}