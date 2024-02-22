#include <iostream>
#include <queue>
#include <string>

int main() {
  std::string s;
  int inp;
  std::priority_queue<int> qu;
  while (std::cin >> s) {
    if (s == "end") {
      break;
    } else if (s == "insert") {
      std::cin >> inp;
      qu.push(inp);
    } else if (s == "print") {
      if (!qu.empty()) {
        std::cout << qu.top() << std::endl;
        qu.pop();
      }
    }
  }
  return 0;
}