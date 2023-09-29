#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> heap;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string command;
  while (cin >> command) {
    if (command == "insert") {
      int key;
      cin >> key;
      heap.push(key);
    } else if (command == "extract") {
      cout << heap.top() << '\n';
      heap.pop();
    } else if (command == "end") {
      break;
    }
  }
  return 0;
}