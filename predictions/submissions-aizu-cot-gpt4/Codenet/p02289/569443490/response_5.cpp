#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Heap {
public:
  void insert(int data) {
    array.push_back(data);
    push_heap(array.begin(), array.end());
  }

  int extract() {
    pop_heap(array.begin(), array.end());
    int maxElement = array.back();
    array.pop_back();
    return maxElement;
  }

private:
  vector<int> array;
};

int main() {
  string cmd;
  int data;
  Heap heap;

  while (cin >> cmd) {
    if (cmd == "end") break;

    if (cmd == "insert") {
      cin >> data;
      heap.insert(data);
    } else if (cmd == "extract") {
      cout << heap.extract() << endl;
    }
  }
  return 0;
}