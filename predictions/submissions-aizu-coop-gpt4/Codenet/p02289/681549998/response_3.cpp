#include <iostream>
#include <queue>
#include <string>

int main() {
  std::priority_queue<int> heap;
  std::string command;

  while (true) {
    std::cin >> command;
    if (command == "end")
      break;
    if (command == "insert") {
      int key;
      std::cin >> key;
      heap.push(key);
    } else if (command == "extract") {
      if (!heap.empty()) {
        std::cout << heap.top() << std::endl;
        heap.pop();
      } else {
        std::cout << "Heap is empty." << std::endl;
      }
    }
  }

  return 0;
}