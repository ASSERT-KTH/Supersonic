#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;
int pop_and_print(priority_queue<int> &qu) {
  cout << qu.top() << endl;
  qu.pop();
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
