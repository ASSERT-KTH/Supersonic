#include <iostream>
#include <queue>
using namespace std;

void pop_and_print(priority_queue<int>& qu) {
  cout << qu.top() << '\n';
  qu.pop();
}

int main() {
  int inp;
  priority_queue<int> qu;
  while (cin >> inp) {
    qu.push(inp);
  }
  while (!qu.empty()) {
    pop_and_print(qu);
  }
  return 0;
}