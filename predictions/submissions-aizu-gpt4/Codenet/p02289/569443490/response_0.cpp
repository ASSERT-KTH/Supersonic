#include <iostream>
#include <vector>
#include <queue>

class Heap {
public:
  void insert(int data) {
    pq.push(data);
  }

  int extract() {
    int ret = pq.top();
    pq.pop();
    return ret;
  }

private:
  std::priority_queue<int> pq;
};

int main() {
  int insert_data;
  std::string line;
  Heap heap;
  while (std::getline(std::cin, line)) {
    if (line[2] == 'd')
      break;
    if (line[0] == 'i') {
      insert_data = stoi(line.substr(7, line.size() - 8));
      heap.insert(insert_data);
    } else {
      std::cout << heap.extract() << "\n";
    }
  }
}