#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void pop_and_print(priority_queue<int> &qu) {
  int top_element = qu.top();
  cout << top_element << endl;
  qu.pop();
}

int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  while (cin >> s) {
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else if (s == "pop") {
      pop_and_print(qu);
    }
  }
  return 0;
}