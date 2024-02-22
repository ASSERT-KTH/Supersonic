#include <iostream>
#include <queue>
#include <string>
using namespace std;

int pop_and_print(priority_queue<int> &qu) {
  if (!qu.empty()) {
    cout << qu.top() << endl;
    qu.pop();
  } else {
    cout << "Queue is empty." << endl;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); // Speed up I/O operations
  string s;
  int inp;
  priority_queue<int> qu;
  while (true) {
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