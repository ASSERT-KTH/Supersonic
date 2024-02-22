#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

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
  std::string input;
  Heap heap;
  while (true) {
    std::getline(std::cin, input);
    if (input[2] == 'd')
      break;
    if (input[0] == 'i') {
      int insert_data;
      std::istringstream iss(input.substr(7));
      iss >> insert_data;
      heap.insert(insert_data);
    } else {
      std::cout << heap.extract() << std::endl;
    }
  }

  return 0;
}