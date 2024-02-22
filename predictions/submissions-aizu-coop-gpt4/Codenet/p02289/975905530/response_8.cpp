#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Pass the queue by reference to avoid copying.
int pop_and_print(priority_queue<int>& qu) {
  // Check if the queue is empty to avoid popping from an empty queue.
  if (!qu.empty()) {
    cout << qu.top() << endl;
    qu.pop();
  }
  return 0;
}

int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  while (1) {
    cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
  return 0;
}