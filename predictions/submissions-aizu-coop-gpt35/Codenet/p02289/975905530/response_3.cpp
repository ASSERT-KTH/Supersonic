#include <iostream>
#include <queue>
#include <string>

int pop_and_print(std::priority_queue<int>& qu) {
  qu.pop();
  return 0;
}

int main() {
  std::string s;
  int inp;
  std::priority_queue<int> qu;
  while (true) {
    std::cin >> s;
    switch (s[0]) {
      case 'e':
        return 0;
      case 'i':
        std::cin >> inp;
        qu.push(inp);
        break;
      default:
        pop_and_print(qu);
    }
  }
}