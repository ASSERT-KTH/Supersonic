#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Heap {
public:
  void insert(int data) {
    heap.push_back(data);
    push_heap(heap.begin(), heap.end());
  }

  int extract() {
    pop_heap(heap.begin(), heap.end());
    int ret = heap.back();
    heap.pop_back();
    return ret;
  }

private:
  vector<int> heap;
};

int main() {
  int insert_data;
  string line;
  Heap heap;
  while (getline(cin, line)) {
    if (line[2] == 'd') 
      break;
    if (line[0] == 'i') {
      istringstream iss(line.substr(1));
      iss >> insert_data;
      heap.insert(insert_data);
    } else {
      cout << heap.extract() << endl;
    }
  }
}