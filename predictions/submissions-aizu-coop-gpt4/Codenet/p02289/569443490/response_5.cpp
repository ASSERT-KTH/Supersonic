#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
  vector<int> heap;

  void insert(int data) {
    heap.push_back(data);
    push_heap(heap.begin(), heap.end());
  }

  int extract() {
    pop_heap(heap.begin(), heap.end());
    int max = heap.back();
    heap.pop_back();
    return max;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int insert_data;
  char operation;
  Heap heap;
  while (true) {
    cin >> operation;
    if (operation == 'd')
      break;
    if (operation == 'i') {
      cin >> insert_data;
      heap.insert(insert_data);
    } else {
      cout << heap.extract() << "\n";
    }
  }
  return 0;
}