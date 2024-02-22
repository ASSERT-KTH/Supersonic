#include <iostream>
#include <queue>
#include <cstring>

void pop_and_print(std::priority_queue<int>& qu) {
  std::cout << qu.top() << '\n';
  qu.pop();
}

int main() {
  char s[10];
  int inp;
  std::priority_queue<int> qu;
  
  while (true) {
    std::cin >> s;
    if (std::strcmp(s, "end") == 0) {
      break;
    } else if (std::strcmp(s, "insert") == 0) {
      std::cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
}