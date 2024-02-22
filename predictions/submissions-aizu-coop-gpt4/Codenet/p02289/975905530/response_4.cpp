#include <iostream>
#include <queue>
#include <string>
using namespace std;

void pop_and_print(priority_queue<int> &qu) {
  if (!qu.empty()) {
    cout << qu.top() << endl;
    qu.pop();
  }
}

int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  while (cin >> s && s != "end") {
    if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
  return 0;
}