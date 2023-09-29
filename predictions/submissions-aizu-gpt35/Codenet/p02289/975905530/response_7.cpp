#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int pop_and_print(priority_queue<int> &qu) {
  int top = qu.top();
  qu.pop();
  cout << top << endl;
  return top;
}
int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> s) {
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
