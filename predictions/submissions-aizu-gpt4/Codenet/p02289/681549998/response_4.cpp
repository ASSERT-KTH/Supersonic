#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void push_heap(int key) {
  heap.push_back(key);
  push_heap(heap.begin(), heap.end());
}

int pop_heap() {
  pop_heap(heap.begin(), heap.end());
  int maxv = heap.back();
  heap.pop_back();
  return maxv;
}

int main() {
  ios::sync_with_stdio(false);  // Speed up I/O operations
  cin.tie(nullptr);

  int key;
  char com[10];
  while (1) {
    cin >> com;
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      cin >> key;
      push_heap(key);
    } else {
      cout << pop_heap() << "\n";
    }
  }
  return 0;
}