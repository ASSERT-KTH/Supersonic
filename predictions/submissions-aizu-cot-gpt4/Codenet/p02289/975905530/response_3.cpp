#include <iostream>
#include <limits.h>
#include <queue>

int pop_and_print(std::priority_queue<int> &qu) {
  std::cout << qu.top() << "\n";
  qu.pop();
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  const char* s;
  int inp;
  std::priority_queue<int> qu;
  while (1) {
    std::cin >> s;
    if (strcmp(s, "end") == 0) {
      break;
    } else if (strcmp(s, "insert") == 0) {
      std::cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
}