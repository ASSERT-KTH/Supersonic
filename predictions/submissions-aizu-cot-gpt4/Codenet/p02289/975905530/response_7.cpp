#include <iostream>
#include <queue>
#include <string>
using namespace std;

void pop_and_print(priority_queue<int> &qu) {
  int top_elem = qu.top();
  qu.pop();
  cout << top_elem << '\n';
}

int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  do {
    cin >> s;
    if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else if (s != "end") {
      pop_and_print(qu);
    }
  } while (s != "end");
  return 0;
}