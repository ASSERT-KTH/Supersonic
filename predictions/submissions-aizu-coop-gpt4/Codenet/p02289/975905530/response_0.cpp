#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Changed return type to void as the returned value is not used.
void pop_and_print(priority_queue<int> &qu) {
  // Check if queue is empty before popping.
  if (!qu.empty()) {
    cout << qu.top() << '\n';  // Replaced std::endl with '\n'
    qu.pop();
  } else {
    cout << "Queue is empty\n";
  }
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