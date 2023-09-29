#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int pop_and_print(priority_queue<int> &qu) {
  int top = qu.top();
  cout << top << endl;
  qu.pop();
  return top;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int inp;
  priority_queue<int> qu;
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